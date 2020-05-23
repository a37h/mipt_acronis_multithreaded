#include "lock.h"

#include <stdlib.h>
#include <sched.h>

#include <atomic>


struct lock {
	std::atomic<size_t> next_free_ticket;
	std::atomic<size_t> owner_ticket;
};


// constructor
lock_t *lock_alloc(long unsigned n_threads) {
	lock_t *lk; 
	if (!(lk = (lock_t *) aligned_alloc(sizeof(*lk), sizeof(*lk)))) {
		return NULL;
	}
	lk->owner_ticket.store(0);
	lk->next_free_ticket.store(0);
	return lk;
}

// destructor
int lock_free(lock_t* lk) {
	free(lk);
	return 0;
}


// mutex.lock
int lock_acquire(lock_t* lk) {
	const size_t this_thread_ticket = lk->next_free_ticket.fetch_add(1);
	
	while (this_thread_ticket != lk->owner_ticket.load()) {
		sched_yield();
	}

	return 0;
}

// mutex.unlock
int lock_release(lock_t* lk) {
	lk->owner_ticket.store(lk->owner_ticket.load() + 1);

	return 0;
}

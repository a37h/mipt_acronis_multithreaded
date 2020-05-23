#include "lock.h"

#include <stdlib.h>
#include <sched.h>

#include <atomic>


struct lock {
	std::atomic<bool> locked;
};

// constructor
lock_t *lock_alloc(long unsigned n_threads) {
	lock_t *lk; 
	if (!(lk = (lock_t *) aligned_alloc(sizeof(*lk), sizeof(*lk)))) {
		return NULL;
	}
	lk->locked.store(false);
	return lk;
}

// destructor
int lock_free(lock_t* lk) {
	free(lk);
	return 0;
}


// mutex.lock
int lock_acquire(lock_t* lk) {
	while (lk->locked.exchange(true) == true) {
		// sched_yield();
	};

	return 0;
}

// mutex.unlock
int lock_release(lock_t* lk) {
	lk->locked.store(false);

	return 0;
}

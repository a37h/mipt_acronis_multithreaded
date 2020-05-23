# Multithreaded Programming

## Benchmark source

The benchmark was taken from [pooh64](https://github.com/pooh64) [repository](https://github.com/pooh64/dati_parpr) and slightly modified for a nicer output

## Benchmark results for my implementations

By running `bash bench.sh` on my **8 core CPU** with **Ubuntu 18.04.4 LTS** installed I've got the following ouput:

```
bench/inc.c
n_threads: -> 1 -> 2 -> 4 -> 8
a37h_spinlock_without_yield: 1.24; 7.12; 13.49; 12.78; 
a37h_spinlock_with_yield: 1.42; 1.73; 2.77; 5.10; 
a37h_ticket_without_yield: 1.24; 8.72; 11.64; 18.45; 
a37h_ticket_with_yield: 1.42; 25.50; 36.80; 97.17; 
pthread_mutex: 1.08; 5.50; 6.41; 8.85; 
pthread_spinlock: 0.63; 1.30; 3.72; 6.16; 
bench/io.c
n_threads: -> 1 -> 2 -> 4 -> 8 -> 16 -> 32
a37h_spinlock_without_yield: 0.50; 0.47; 0.44; 0.48; 14.65; 75.66; 
a37h_spinlock_with_yield: 0.50; 0.45; 0.44; 0.48; 0.49; 0.48; 
a37h_ticket_without_yield: 0.51; 0.49; 0.44; 0.48; 84.56; 143.74; 
a37h_ticket_with_yield: 0.50; 0.51; 0.45; 0.51; 0.57; 0.57; 
pthread_mutex: 0.51; 0.56; 0.46; 0.45; 0.45; 0.45; 
pthread_spinlock: 0.53; 0.45; 0.44; 0.45; 0.47; 0.69; 
bench/ring.c
n_threads: -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
a37h_spinlock_without_yield: 0.30; 1.11; 1.52; 1.57; 1.76; 1.84; 1.90; 2.22; 
a37h_spinlock_with_yield: 0.32; 1.12; 1.76; 1.79; 1.80; 2.00; 2.34; 2.48; 
a37h_ticket_without_yield: 0.32; 1.24; 1.85; 1.94; 2.18; 2.25; 2.71; 3.91; 
a37h_ticket_with_yield: 0.32; 1.19; 1.81; 1.93; 2.24; 2.76; 2.54; 4.67; 
pthread_mutex: 0.34; 1.32; 1.72; 1.90; 2.02; 2.42; 3.35; 3.61; 
pthread_spinlock: 0.25; 1.03; 1.35; 1.59; 1.60; 1.89; 2.10; 3.45;
```

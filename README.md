# Multithreaded Programming

## Benchmark source

The benchmark was taken from [pooh64](https://github.com/pooh64) [repository](https://github.com/pooh64/dati_parpr) and slightly modified for a nicer output

## Benchmark results for my implementations

By running `bash bench.sh` on my **8 core CPU** with **Ubuntu 18.04.4 LTS** installed I've got the following ouput:

```
bench/inc.c
n_threads: -> 1 -> 2 -> 4 -> 8
a37h_spinlock_without_yield: 1.12; 6.98; 12.51; 8.15; 
a37h_spinlock_with_yield: 1.20; 1.55; 2.57; 5.15; 
a37h_spinlock_with_yield_optimized_32: 1.21; 7.21; 11.45; 7.36; 
a37h_spinlock_with_yield_optimized_8: 1.75; 2.37; 4.07; 5.07; 
a37h_ticket_without_yield: 1.14; 7.88; 10.77; 14.24; 
a37h_ticket_with_yield: 1.38; 31.26; 36.00; 89.37; 
a37h_ticket_with_yield_optimized_32: 1.50; 26.67; 37.25; 94.16; 
a37h_ticket_with_yield_optimized_8: 1.43; 23.61; 35.44; 72.96; 
pthread_mutex: 1.09; 4.55; 6.01; 8.98; 
pthread_spinlock: 0.56; 1.37; 3.57; 4.04; 
bench/io.c
n_threads: -> 1 -> 2 -> 4 -> 8 -> 16 -> 32
a37h_spinlock_without_yield: 0.51; 0.46; 0.45; 0.48; 14.29; 51.08; 
a37h_spinlock_with_yield: 0.52; 0.45; 0.45; 0.51; 0.51; 0.50; 
a37h_spinlock_with_yield_optimized_32: 0.52; 0.46; 0.47; 0.55; 0.54; 0.56; 
a37h_spinlock_with_yield_optimized_8: 0.51; 0.45; 0.45; 0.56; 0.58; 0.64; 
a37h_ticket_without_yield: 0.57; 0.45; 0.47; 0.66; 78.60; 117.67; 
a37h_ticket_with_yield: 0.51; 0.48; 0.45; 0.52; 0.54; 0.66; 
a37h_ticket_with_yield_optimized_32: 0.51; 0.49; 0.45; 0.49; 0.59; 0.58; 
a37h_ticket_with_yield_optimized_8: 0.51; 0.50; 0.45; 0.51; 0.54; 0.57; 
pthread_mutex: 0.51; 0.57; 0.48; 0.46; 0.46; 0.46; 
pthread_spinlock: 0.53; 0.45; 0.44; 0.48; 0.74; 1.15; 
bench/ring.c
n_threads: -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
a37h_spinlock_without_yield: 0.31; 1.22; 1.58; 1.72; 1.68; 1.95; 2.02; 1.98; 
a37h_spinlock_with_yield: 0.32; 1.09; 1.63; 1.77; 1.75; 1.91; 2.09; 2.36; 
a37h_spinlock_with_yield_optimized_32: 0.32; 1.17; 1.51; 1.65; 1.69; 1.87; 2.03; 2.65; 
a37h_spinlock_with_yield_optimized_8: 0.33; 1.20; 1.56; 1.70; 1.87; 1.87; 1.90; 2.21; 
a37h_ticket_without_yield: 0.31; 1.17; 1.67; 1.80; 1.92; 2.25; 2.34; 2.91; 
a37h_ticket_with_yield: 0.43; 1.40; 2.21; 2.21; 2.51; 2.60; 2.67; 2.61; 
a37h_ticket_with_yield_optimized_32: 0.33; 1.12; 1.68; 1.84; 1.96; 2.17; 2.30; 2.61; 
a37h_ticket_with_yield_optimized_8: 0.33; 1.24; 1.76; 1.87; 1.90; 2.14; 2.59; 2.53; 
pthread_mutex: 0.30; 1.32; 1.62; 1.90; 1.98; 2.20; 2.32; 2.69; 
pthread_spinlock: 0.23; 0.86; 1.18; 1.47; 1.50; 1.58; 1.74; 2.14;
```

//
// Created by Lloyd Brown on 8/30/19.
//

#ifndef WAFFLE_TIMER_H
#define WAFFLE_TIMER_H

#include <chrono>
#include <math.h>
#include "unistd.h"

#define rdtscll(val) do { \
    unsigned int __a,__d; \
    __asm__ __volatile__("rdtsc" : "=a" (__a), "=d" (__d)); \
    (val) = ((unsigned long long)__a) | (((unsigned long long)__d)<<32); \
} while(0)

// Number of ticks per us
unsigned long long rdtscuhz(void) {
    const int ntrials = 5;
    const long sleeplen = (250 * 1000); // in us
    double freq = 0.0;

    for (int i = 0; i < ntrials; i++) {
        unsigned long long start, end, t;
        double hz;

        auto s = std::chrono::high_resolution_clock::now();
        rdtscll(start);
        usleep(sleeplen);
        rdtscll(end);
        auto e = std::chrono::high_resolution_clock::now();
        t = std::chrono::duration_cast<std::chrono::microseconds>(e - s).count();
        hz = ((double)(end - start))/t;
        freq += hz;
    }

    freq = round(freq/ntrials);
    return (unsigned long long) freq;
}

#endif //WAFFLE_TIMER_H

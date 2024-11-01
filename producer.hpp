/**
 * @file consumer.hpp
 * @author Annika Hall
 * @brief The consumer header for the producer/consumer problem
 * @date 2024-11-01
 * 
 */
// producer.hpp

#ifndef PRODUCER_HPP
#define PRODUCER_HPP

#include <semaphore.h>
#include <fcntl.h>   // For O_* constants
#include <sys/mman.h> // For mmap
#include <unistd.h>  // For ftruncate
#include <iostream>  // For std::cout
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()

const int TABLE_SIZE = 2; // Define the size of the buffer

struct sharedMem {
    sem_t mutex;        // Mutex for mutual exclusion
    sem_t full;         // Semaphore to count full slots
    sem_t empty;        // Semaphore to count empty slots
    int table[TABLE_SIZE]; // Buffer to hold produced items
    int in;             // Index for the next produced item
    int out;            // Index for the next consumed item
};

#endif


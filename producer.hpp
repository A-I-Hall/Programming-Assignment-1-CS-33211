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

struct sharedMem {
    sem_t full;  // Semaphore to count full slots
    sem_t empty; // Semaphore to count empty slots
    // Add other members as needed
};

#endif


/**
 * @file consumer.cpp
 * @author Annika Hall
 * @brief The consumer in the producer and consumer problem
 * @date 2024-11-01
 *
 */

#include "producer.hpp"
<<<<<<< HEAD
#include <iostream>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

 /**
  * @brief The main function for the consumer
  *
  * @param argc The number of arguments fed into the program
  * @param argv Array to hold the command line-fed arguments, used for the shared memory file name
  * @return int Exit status of the program
  */
int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <shared_memory_name>" << std::endl;
        return 1;
    }

=======
#include "consumer.hpp"
/**
 * @brief The main function for the consumer
 * 
 * @param argc The number of arguments fed into the program
 * @param argv Array to hold the command line-fed arguments, used for the shared memory file name
 * @return int Exit status of the program
 */
int main(int argc, char *argv[]) {
>>>>>>> 8b27319e2b015f9062b081343db903cf1962adb9
    // Variables
    int fd;
    const char* shmpath = argv[1];
    struct sharedMem* consMem;

    // Open shared memory
    fd = shm_open(shmpath, O_RDWR, 0);
    if (fd == -1) {
        perror("shm_open failed");
        return 1;
    }

    // Map shared memory to local address space
    consMem = static_cast<sharedMem*>(mmap(NULL, sizeof(*consMem), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0));
    if (consMem == MAP_FAILED) {
        perror("mmap failed");
        return 1;
    }

    for (int i = 5; i > 0; --i) {
        // Wait until buffer has items and mutex is available
        sem_wait(&(consMem->full));
        sem_wait(&(consMem->mutex));

        // Retrieve item from buffer
        int consumed_value = consMem->table[consMem->out];
        std::cout << "Consumed: " << consumed_value << std::endl;

        // Update buffer index with wrapping
        consMem->out = (consMem->out + 1) % TABLE_SIZE;

        // Release mutex and signal buffer space availability
        sem_post(&(consMem->mutex));
        sem_post(&(consMem->empty));

        // Simulate variable consumption time
        sleep(rand() % 2); // Shorter sleep time for faster testing
    }

    // Detach shared memory
    shm_unlink(shmpath);

    return 0;
}

/*#include <iostream>
#include <pthread.h>

using namespace std;

// Mutex for protecting cout
pthread_mutex_t printMutex;

// Thread function
void* threadFunction(void* arg)
{
    int threadNumber = *(int*)arg;

    // Lock before printing
    pthread_mutex_lock(&printMutex);

    cout << "Thread " << threadNumber << " is executing" << endl;

    // Unlock after printing
    pthread_mutex_unlock(&printMutex);

    return NULL;
}

int main()
{
    pthread_t threads[4];
    int threadNumbers[4];

    // Initialize mutex
    pthread_mutex_init(&printMutex, NULL);

    // Create 4 threads
    for (int i = 0; i < 4; i++)
    {
        threadNumbers[i] = i + 1;

        pthread_create(
            &threads[i],
            NULL,
            threadFunction,
            &threadNumbers[i]
        );
    }

    // Wait for all threads
    for (int i = 0; i < 4; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // Destroy mutex
    pthread_mutex_destroy(&printMutex);

    return 0;
}
    */

/*#include <iostream>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 4
#define ARRAY_SIZE 8

int numbers[ARRAY_SIZE] = {
    10, 20, 30, 40,
    50, 60, 70, 80
};

// Thread function
void* processArray(void* arg)
{
    int threadID = *(int*)arg;

    // Calculate starting position
    int start = threadID * (ARRAY_SIZE / NUM_THREADS);

    // Calculate ending position
    int end = start + (ARRAY_SIZE / NUM_THREADS);

    cout << "Thread " << threadID + 1 << " processing: ";
  

    for (int i = start; i < end; i++)
    {
        cout << numbers[i] << " ";
       
    }

    cout << endl;

    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int threadIDs[NUM_THREADS];

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        threadIDs[i] = i;

        pthread_create(
            &threads[i],
            NULL,
            processArray,
            &threadIDs[i]
        );
    }

    // Wait for all threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}*/

#include <iostream>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 4
#define ARRAY_SIZE 100

int numbers[ARRAY_SIZE];

// Store the sum calculated by each thread
int partialSum[NUM_THREADS];

// Thread function
void* calculateSum(void* arg)
{
    int threadID = *(int*)arg;

    // Calculate starting position
    int start = threadID * (ARRAY_SIZE / NUM_THREADS);

    // Calculate ending position
    int end = start + (ARRAY_SIZE / NUM_THREADS);

    // Initialize partial sum
    partialSum[threadID] = 0;

    // Calculate sum of assigned portion
    for (int i = start; i < end; i++)
    {
        partialSum[threadID] += numbers[i];
    }

    return NULL;
}


int main()
{
    pthread_t threads[NUM_THREADS];
    int threadIDs[NUM_THREADS];

    // Fill the array with numbers 1 to 100
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        numbers[i] = i + 1;
    }

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        threadIDs[i] = i;

        pthread_create(&threads[i], NULL, calculateSum, &threadIDs[i]
        );
      
    }

   
   // Wait for all threads
for (int i = 0; i < NUM_THREADS; i++)
{
    pthread_join(threads[i], NULL);
}

// Display each thread's result
for (int i = 0; i < NUM_THREADS; i++)
{
    cout << "Thread " << i + 1
         << " calculated sum = "
         << partialSum[i] << endl;
}

// Calculate final sum
int totalSum = 0;

for (int i = 0; i < NUM_THREADS; i++)
{
    totalSum += partialSum[i];
}

cout << endl;
cout << "Total sum = " << totalSum << endl;

    return 0;
}
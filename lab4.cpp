/*#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
    #pragma omp parallel num_threads(4)
    {
        int threadID = omp_get_thread_num();

        #pragma omp critical
        {
            cout << "Hello from thread " << threadID << endl;
        }
    }

    return 0;
}*/

#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
    int numberOfThreads;

    cout << "Enter number of threads: ";
    cin >> numberOfThreads;

    #pragma omp parallel num_threads(numberOfThreads)
    {
        int threadID = omp_get_thread_num();

        #pragma omp critical
        {
            cout << "Hello from thread " << threadID << endl;
        }
    }

    return 0;
}
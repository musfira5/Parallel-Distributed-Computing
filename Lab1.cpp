#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    //const int N = 10000000;


    const int N = 1000000;

    // Create an array
    int* arr = new int[N];

    // Fill the array
    for (int i = 0; i < N; i++)
    {
        arr[i] = 1;
    }

    // Start measuring time
    auto start = high_resolution_clock::now();

    // Sequential calculation of sum
    long long sum = 0;

    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
    }

    // Stop measuring time
    auto end = high_resolution_clock::now();

    // Calculate execution time
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Array Size: " << N << endl;
    cout << "Sum: " << sum << endl;
    cout << "Execution Time: " << duration.count()
         << " milliseconds" << endl;

    delete[] arr;

    return 0;
}
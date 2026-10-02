/*#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double Tserial, Tpa/rallel, speedup;

    cout << "=====================================\n";
    cout << "       TASK 1 - SPEEDUP\n";
    cout << "=====================================\n";

    // Input serial execution time
    cout << "Enter serial execution time: ";
    cin >> Tserial;

    // Input parallel execution time
    cout << "Enter parallel execution time: ";
    cin >> Tparallel;

    // Check for invalid input
    if (Tparallel <= 0)
    {
        cout << "Error: Parallel execution time must be greater than 0.\n";
        return 1;
    }

    // Calculate speedup
    speedup = Tserial / Tparallel;

    // Display result
    cout << fixed << setprecision(2);

    cout << "\nSerial Execution Time   = "
         << Tserial << endl;

    cout << "Parallel Execution Time = "
         << Tparallel << endl;

    cout << "Speedup                 = "
         << speedup << endl;

    return 0;
}
   */ 

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Serial portion = 20%
    double f = 0.20;

    // Number of processors
    int processors[] = {2, 4, 8, 16};

    cout << "=====================================\n";
    cout << "      TASK 2 - AMDAHL'S LAW\n";
    cout << "=====================================\n";

    cout << "Serial Portion = 20%\n";
    cout << "Serial Fraction = 0.20\n\n";

    cout << left
         << setw(15) << "Processors"
         << setw(20) << "Speedup"
         << endl;

    cout << "-------------------------------------\n";

    // Calculate speedup for each processor count
    for (int i = 0; i < 4; i++)
    {
        int N = processors[i];

        // Amdahl's Law
        double speedup =
            1.0 / (f + ((1.0 - f) / N));

        cout << left
             << setw(15) << N
             << setw(20)
             << fixed << setprecision(2)
             << speedup
             << endl;
    }

    return 0;
}
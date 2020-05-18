#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of Randoms number to be generated:\n";
    cin >> n;
    int randoms[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
        randoms[i] = (rand() % (int)(100 - 1 + 1)) + 1;
    cout
        << "The random numbers are:";
    for (int i = 0; i < n; i++)
    {
        if (i % 10 == 0)
            cout << "\n";
        cout << randoms[i] << " ";
    }
    cout << "\n";
    const double ACCEPTANCE_VAL = 16.919;
    const int CONFIDENCE = 95;
    const int EXPECTED_FREQ = n / 10;
    const double ACCEPTED_VAL_CORRELATION = 14.067;
    int expected = 10;
    double diffSquare = 0;
    int i = 0;
    int sum = 0;
    while (i < 100)
    {
        int frequency = 0;
        for (int j : randoms)
        {
            if (j > i && j <= expected)
                frequency += 1;
        }
        int observedFreq = frequency;

        diffSquare += pow(abs(observedFreq - EXPECTED_FREQ), 2);
        sum += frequency;
        i += 10; //onto next class of expected values
        expected += 10;
    }
    cout << "\n";
    double chiSquare = (double)(diffSquare / EXPECTED_FREQ);
    cout << "Chi Square value is " << chiSquare << "\n";

    if (chiSquare < ACCEPTANCE_VAL)
    {
        cout << "The random numbers follow the chi-square test as\n";
        cout << "chi square value " << chiSquare << " is\nless than\naccepted value " << ACCEPTANCE_VAL << "\nat " << CONFIDENCE << "% confidence \n";
        cout << "when expected frequency per class is " << EXPECTED_FREQ << endl;
    }
    else
    {
        cout << "The random numbers dont follow the chi-square test as\n";
        cout << "chi square value " << chiSquare << " is\nNOT less than\naccepted value " << ACCEPTANCE_VAL << "\nat " << CONFIDENCE << "% confidence \n";
        cout << "when expected frequency per class is " << EXPECTED_FREQ << endl;
    }

    int frequencies[9] = {0};
    for (int i = 0; i < n - 1; i++)
    {
        if (randoms[i] <= 33 && randoms[i + 1] <= 33)
            frequencies[0]++;
        else if (randoms[i] <= 67 && randoms[i + 1] <= 33)
            frequencies[1]++;
        else if (randoms[i] <= 100 && randoms[i + 1] <= 33)
            frequencies[2]++;
        else if (randoms[i] <= 33 && randoms[i + 1] <= 67)
            frequencies[3]++;
        else if (randoms[i] <= 67 && randoms[i + 1] <= 67)
            frequencies[4]++;
        else if (randoms[i] <= 100 && randoms[i + 1] <= 67)
            frequencies[5]++;
        else if (randoms[i] <= 33 && randoms[i + 1] <= 100)
            frequencies[6]++;
        else if (randoms[i] <= 67 && randoms[i + 1] <= 100)
            frequencies[7]++;
        else if (randoms[i] <= 100 && randoms[i + 1] <= 100)
            frequencies[8]++;
    }
    diffSquare = 0.0;

    for (int i : frequencies)
        diffSquare += pow((double)(i - EXPECTED_FREQ), 2);
    chiSquare = (double)(diffSquare / EXPECTED_FREQ);
    if (chiSquare < ACCEPTED_VAL_CORRELATION)
    {
        cout << "The random numbers follow the chi-square test as\n";
        cout << "chi square value " << chiSquare << " is\nless than\naccepted value " << ACCEPTED_VAL_CORRELATION << "\nat " << CONFIDENCE << "% confidence \n";
    }
    else
    {
        cout << "The random numbers dont follow the chi-square test as\n";
        cout << "chi square value " << chiSquare << " is\nNOT less than\naccepted value " << ACCEPTED_VAL_CORRELATION << "\nat " << CONFIDENCE << "% confidence \n";
    }
    return 0;
}
//36 91 51 02 54 06 58 06 58 02 54 01 48 97 43 22 83 25 79 95 42 87 73 17 02 42 95 38 79 29 65 09 55 97 39 83 31 77 17 62 03 49 90 37 13 17 58 11 51 92 33 78 21 66 09 54 49 90 35 84 26 74 22 62 12 90 36 83 32 75 31 94 34 87 40 07 58 05 56 22 58 77 71 10 73 23 57 13 36 89 22 68 02 44 99 27 81 26 85 82

// 7  5 96 14 10 90 21 15 84 28 20 78 35 25 72 42 30 66 49 35 60 56 40 54 63 45 48 70 50 42 77 55 36 84 60 30 91 65 24 98 70 18 7 75 12 14 80  6 21 85 96 28 90 90 35 95 84 42  5 78 49 10 72 56 15 66 63 20 60 70 25 54 77 30 48 84 35 42 91 40 36 98 45 30 7 50 24 14 55 18 21
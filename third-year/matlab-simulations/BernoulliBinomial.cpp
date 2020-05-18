#include <bits/stdc++.h>
using namespace std;
int main()
{
    int numberOfTrials, numberOfVariates;
    double successP, y;
    cout << "Enter the number of trials:\n";
    cin >> numberOfTrials;
    cout << "Enter the probability of success(<1.0):\n";
    cin >> successP;
    cout << "Enter the number of variates to be generated\n";
    cin >> numberOfVariates;
    srand(time(0));
    cout << "The variates are:\n";
    for (int i = 0; i < numberOfVariates; i++)
    {
        int x = 0;
        for (int j = 0; j < numberOfTrials; j++)
        {
            y = (double)rand() / RAND_MAX;
            if (y < successP)
                x++;
        }
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
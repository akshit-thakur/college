#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    float lambda, mean;
    srand(time(0));
    cout << "Enter value of mean(lambda):\n";
    cin >> lambda;
    cout << "Enter the number of variates to be generated:\n";
    cin >> n;
    mean = lambda;
    cout << "The variates are:\n";
    for (int i = 0; i < n; i++)
    {
        double fact = 1;
        int x = 0;
        double cumProb = 0;
        double y = (double)rand() / RAND_MAX;
        while (y > cumProb)
        {
            double prob = pow(2.718282, -mean) * pow(mean, x) / fact;
            cumProb += prob;
            x += 1;
            fact *= x;
        }
        cout << x << " ";
    }
    cout << "\n";
}
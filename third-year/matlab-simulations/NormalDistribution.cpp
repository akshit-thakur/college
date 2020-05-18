#include <bits/stdc++.h>
using namespace std;
int main()
{
    double mue, sigma;
    int n;
    cout << "Enter the value of mue\n";
    cin >> mue;
    cout << "Enter the value of sigma\n";
    cin >> sigma;
    cout << "Enter the number of variates to be generated\n";
    cin >> n;
    srand(time(0));
    cout << "The values of variates are:\n";
    for (int i = 0; i < n; i++)
    {
        double sum = 0;
        for (int j = 0; j < 12; j++)
        {
            double x = (double)rand() / RAND_MAX;
            sum += x;
        }
        double t = (double)(mue + sigma * (sum - 6.0));
        cout << setprecision(4) << t << " ";
    }
    cout << "\n";
    return 0;
}
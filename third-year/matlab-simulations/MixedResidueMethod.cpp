#include <iostream>
using namespace std;
int main()
{
    int a, b, m, r, n;
    cout << "Enter the value of a:\n";
    cin >> a;
    cout << "Enter the value of b:\n";
    cin >> b;
    cout << "Enter the value of m:\n";
    cin >> m;
    cout << "Enter the value of r:\n";
    cin >> r;
    cout << "Enter the value of n:\n";
    cin >> n;
    cout << "The " << n << " random numbers are:\n";
    for (int i = 0; i < n; i++)
    {
        r = (a * r + b) % m;
        cout << r << " ";
    }
    cout << "\n";
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int a, m, r, n;
    cout << "Enter the value of a:\n";
    cin >> a;
    cout << "Enter the value of m:\n";
    cin >> m;
    cout << "Enter the value of seed or r:\n";
    cin >> r;
    cout << "Enter the total random numbers to be generated:\n";
    cin >> n;
    cout << "The " << n << " random numbers generated are:\n";
    for (int i = 0; i < n; i++)
    {
        r = (a * r) % m;
        cout << r << " ";
    }
    cout << "\n";
    return 0;
}
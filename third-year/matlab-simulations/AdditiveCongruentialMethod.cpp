#include <iostream>
using namespace std;
int main()
{
    int b, m, n, r;
    cout << "Enter the value of b: ";
    cin >> b;
    cout << "Enter the value of m: ";
    cin >> m;
    cout << "Enter the value of r: ";
    cin >> r;

    cout << "Enter the number of Random Numbers you want to generate: ";
    cin >> n;
    cout << "The random numbers are: \n";
    for (int i = 0; i < n; i++)
    {
        r = (r + b) % m;
        cout << r << " ";
    }
    cout << "\n";
    return 0;
}
// Output
// Enter the value of b: 11
// Enter the value of m : 19
// Enter the value of r : 1
// Enter the number of Random Numbers you want to generate : 12
// The random numbers are :
// 12 4 15 7 18 10 2 13 5 16 8 0
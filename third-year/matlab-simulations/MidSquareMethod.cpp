#include <iostream>
using namespace std;
int main()
{
    int n, seed;
    cout << "Number of Random Numbers to generate :\n";
    cin >> n;
    cout << "Enter the seed:\n";
    cin >> seed;
    cout << "The " << n << " random numbers are:\n";
    for (int i = 0; i < n; i++)
    {
        int random = seed * seed;
        random /= 100;
        random %= 10000;
        seed = random;
        cout << random << " ";
    }
    cout << "\n";
    return 0;
}
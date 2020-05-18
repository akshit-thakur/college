#include <iostream>
using namespace std;
int main()
{
    int n, r0, r1, m;
    cout << "Enter number of random numbers to be generated:\n";
    cin >> n;
    cout << "Enter first random number:\n";
    cin >> r0;
    cout << "Enter second random number:\n";
    cin >> r1;
    cout << "Enter maximum range of random number:\n";
    cin >> m;
    cout << "The random numbers are : " << endl;
    for (int i = 0; i < n; i++)
    {
        int r2 = r0 + r1;
        int random = r2 % m;
        cout << random << " ";
        r0 = r1;
        r1 = r2;
    }
    cout << "\n";
    return 0;
}
//Enter number of random numbers to be generated:
//8
//Enter first random number :
//9
//Enter second random number :
//13
//Enter maximum range of random number :
//17
//The random numbers are :
//5 1 6 7 13 3 16 2
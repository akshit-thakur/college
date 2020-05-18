#include <iostream>
using namespace std;

int count = 0; //number of iterations

int sum(int *A, int i)
{ //find sum of elements in array recursively
	count += 1;
	if (i == 1)
		return A[0];
	else
		return A[i - 1] + sum(A, i - 1);
}

int main()
{
	int n, i;

	//input
	cout << "Enter n: ";
	cin >> n;
	int *arr = new int[n];
	cout << "Enter array:\n";
	for (i = 0; i < n; i++)
		cin >> arr[i];

	//output
	cout << "Sum : " << sum(arr, n) << "\n";
	cout << "Number of iterations: " << count << "\n";
	return 0;
}

// 17/01/2019

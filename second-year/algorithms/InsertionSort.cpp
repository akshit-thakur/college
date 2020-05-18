#include <iostream>
using namespace std;

int main()
{
	int *arr;
	int n, i, j;

	//input
	cout << "Enter n: ";
	cin >> n;

	arr = new int[n];
	cout << "Enter array:\n";
	for (i = 0; i < n; i++)
		cin >> arr[i];

	//insertion sort
	for (i = 1; i < n; i++)
	{
		int key = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > key; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = key;
	}

	//output
	cout << "The array is:\n";
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	//cout<<"Number of comparisons "<<count<<"\n";
	return 0;
}

// 17/01/2019

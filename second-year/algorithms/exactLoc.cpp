#include <iostream>
using namespace std;

int item = 0;

bool search(int *&A, int size, int x)
{
	for (int i = 0; i < size; i++)
	{
		if (A[i] == x)
		{
			item = i;
			return true;
		}
	}
	return false;
}

void disp(int *A, int n)
{
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << "\n";
}

int findLoc(int *&a, int m, int p)
{
	int i = m;
	int j = p - 1;
	int v = a[item];
	while (i < j)
	{
		while (a[i] <= v)
			i += 1;
		while (a[j] > v)
			j -= 1;
		if (i < j)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	search(a, m + p, v);
	a[item] = a[j];
	a[j] = v;
	return j;
}

int main()
{
	int n, i, num;

	//input
	cout << "Enter size of array:\n";
	cin >> n;

	int *arr = new int[n];

	cout << "Enter the array in any order:\n";
	for (i = 0; i < n; i++)
		cin >> arr[i];

	cout << "Enter the number you want exact location of: ";
	cin >> num;

	//output
	cout << "The array is:\n";
	disp(arr, n);

	if (search(arr, n, num))
		cout << "The exact location of the number is: " << findLoc(arr, 0, n) << "\n";
	else
		cout << "Number not found.\n";

	cout << "The array after finding exact location is:\n";
	disp(arr, n);

	return 0;
}
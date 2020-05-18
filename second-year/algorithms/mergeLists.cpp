#include <iostream>
#define INFY -123456
using namespace std;

void disp(int *A, int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << "\n";
}

int *merge(int *&A, int *&B, int m, int n)
{
	int i = 0, j = 0, k = 0;
	int *C = new int[m + n];
	while (i <= m && j <= n)
	{
		if (A[i] > B[j])
		{
			C[k] = A[i];
			++i;
		}
		else
		{
			C[k] = B[j];
			++j;
		}
		++k;
	}
	if (m < i)
	{
		for (; j < n; ++j, ++k)
			C[k] = B[j];
	}
	else if (n < j)
	{
		for (; i < m; ++i, ++k)
			C[k] = A[i];
	}
	return C;
}

int main()
{
	int m, n;

	cout << "Enter size of A: ";
	cin >> m;

	cout << "Enter size of B: ";
	cin >> n;

	int *A = new int[m + 1];
	int *B = new int[n + 1];
	int *C = new int[m + n + 1];

	cout << "Enter array A: ";
	for (int i = 0; i < m; i++)
		cin >> A[i];
	A[m] = INFY;

	cout << "Enter array B: ";
	for (int j = 0; j < n; j++)
		cin >> B[j];
	B[n] = INFY;

	C = merge(A, B, m, n);

	cout << "Array A:\n";
	disp(A, m);

	cout << "Array B:\n";
	disp(B, n);

	cout << "Merged Array:\n";
	disp(C, m + n);

	return 0;
}

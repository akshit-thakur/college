#include <iostream>
using namespace std;

void initialize(int **&A, int n)
{
	A = new int *[n];
	int i, j;
	for (i = 0; i < n; i++)
		A[i] = new int[n];
}

void disp(int **&A, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << A[i][j] << " ";
		cout << "\n";
	}
}

int main()
{
	int n = 4;
	int **A;
	int **B;
	int **C;
	initialize(A, n);
	initialize(B, n);
	initialize(C, n);
	int i, j;
	cout << "Enter A:\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cin >> A[i][j];
	}
	cout << "Enter B:\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cin >> B[i][j];
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			C[i][j] = 0;
			for (int k = 0; k < n; k++)
				C[i][j] += A[i][k] * B[k][j];
		}
	}
	cout << "A:\n";
	disp(A, n);
	cout << "B:\n";
	disp(B, n);
	cout << "C:\n";
	disp(C, n);
	return 0;
}
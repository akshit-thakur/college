#include <iostream>
using namespace std;

float *x;

void bubbleSort(float **A, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (A[2][j] < A[2][j + 1])
			{
				for (int k = 0; k < 4; k++)
				{
					float t = A[k][j];
					A[k][j] = A[k][j + 1];
					A[k][j + 1] = t;
				}
			}
		}
	}
}
float greedyKnapsack(float **pw, int m, int n)
{
	x = new float[n];
	int i, u = m;
	for (i = 0; i <= n; i++)
		x[i] = 0.0;
	for (i = 0; i < n; i++)
	{
		if (pw[1][i] > u)
			break;
		x[i] = 1;
		u -= pw[1][i];
	}
	if (i <= n)
		x[i] = u / pw[1][i];
	float profit = 0;
	for (int j = 0; j <= i; j++)
		profit += pw[0][j] * x[j];
	return profit;
}

int main()
{
	int n, i, m;
	cout << "Enter the number of items: ";
	cin >> n;

	float **pw = new float *[4];
	for (i = 0; i < 4; i++)
		pw[i] = new float[n];

	cout << "Enter price and weights for " << n << " items:\n";
	for (i = 0; i < n; i++)
	{
		cin >> pw[0][i] >> pw[1][i];
		pw[2][i] = pw[0][i] / pw[1][i];
		pw[3][i] = i + 1;
	}

	bubbleSort(pw, n);

	cout << "Enter knapsack size: ";
	cin >> m;

	float profit = greedyKnapsack(pw, m, n);
	cout << "Buying item(s) numbered ";
	for (i = 0; x[i] == 1 && i < n; i++)
		cout << pw[3][i] << " ";
	cout << "as whole";
	if (x[i] < 1 && x[i] > 0)
		cout << " and " << pw[3][i] << " as a fraction " << x[i];
	cout << "\nTotal profit is: " << profit << "\n";
	return 0;
}
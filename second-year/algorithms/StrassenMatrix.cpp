#include <iostream>
using namespace std;

int **P;
int **Q;
int **R;
int **S;
int **T;
int **U;
int **V;

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

void addMat(int **&A, int **&B, int **&C, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			C[i][j] = A[i][j] + B[i][j];
	}
}

void subMat(int **&A, int **&B, int **&C, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			C[i][j] = A[i][j] - B[i][j];
	}
}

void strassen(int n, int **&A, int **&B, int **&C)
{
	if (n == 2)
	{
		for (int a = 0; a < 2; a++)
		{
			for (int b = 0; b < 2; b++)
			{
				C[a][b] = 0;
				for (int c = 0; c < 2; c++)
					C[a][b] += A[a][c] * B[c][b];
			}
		}
	}
	else
	{
		int i, j, k, l;
		//Array initialization
		int **A1;
		int **B1;
		int **A2;
		int **B2;
		int **A3;
		int **B3;
		int **A4;
		int **B4;
		initialize(A1, n / 2);
		initialize(A2, n / 2);
		initialize(A3, n / 2);
		initialize(A4, n / 2);
		initialize(B1, n / 2);
		initialize(B2, n / 2);
		initialize(B3, n / 2);
		initialize(B4, n / 2);
		//end of array initializaton
		k = 0;
		//for A1,B1
		for (i = 0; i < n / 2; i++, k++)
		{
			l = 0;
			for (j = 0; j < n / 2; j++, l++)
			{
				A1[k][l] = A[i][j];
				B1[k][l] = B[i][j];
			}
		}
		k = 0;
		//for A2,B2
		for (i = 0; i < n / 2; i++, k++)
		{
			l = 0;
			for (j = n / 2; j < n; j++, l++)
			{
				A2[k][l] = A[i][j];
				B2[k][l] = B[i][j];
			}
		}
		k = 0;
		//for A3,B3
		for (i = n / 2; i < n; i++, k++)
		{
			l = 0;
			for (j = 0; j < n / 2; j++, l++)
			{
				A3[k][l] = A[i][j];
				B3[k][l] = B[i][j];
			}
		}
		k = 0;
		//for A4,B4
		for (i = n / 2; i < n; i++, k++)
		{
			l = 0;
			for (j = n / 2; j < n; j++, l++)
			{
				A4[k][l] = A[i][j];
				B4[k][l] = B[i][j];
			}
		}

		int **AP;
		int **BP;
		int **AQ;
		int **BR;
		int **BS;
		int **AT;
		int **AU;
		int **BU;
		int **AV;
		int **BV;

		initialize(AP, n / 2);
		addMat(A1, A4, AP, n / 2);

		initialize(BP, n / 2);
		addMat(B1, B2, BP, n / 2);

		initialize(AQ, n / 2);
		addMat(A3, A4, AQ, n / 2);

		initialize(BR, n / 2);
		subMat(B2, B4, BR, n / 2);

		initialize(BS, n / 2);
		subMat(B3, B1, BS, n / 2);

		initialize(AT, n / 2);
		addMat(A1, A2, AT, n / 2);

		initialize(AU, n / 2);
		subMat(A3, A1, AU, n / 2);

		initialize(BU, n / 2);
		addMat(B1, B2, BU, n / 2);

		initialize(AV, n / 2);
		subMat(A2, A4, AV, n / 2);

		initialize(BV, n / 2);
		addMat(B3, B4, BV, n / 2);

		initialize(P, n / 2);
		strassen(n / 2, AP, BP, P);

		initialize(Q, n / 2);
		strassen(n / 2, AQ, B1, Q);

		initialize(R, n / 2);
		strassen(n / 2, A1, BR, R);

		initialize(S, n / 2);
		strassen(n / 2, A2, BS, S);

		initialize(T, n / 2);
		strassen(n / 2, AT, B2, T);

		initialize(U, n / 2);
		strassen(n / 2, AU, BU, U);

		initialize(V, n / 2);
		strassen(n / 2, AV, BV, V);

		int **C1;
		initialize(C1, n / 2);
		int **C2;
		initialize(C2, n / 2);
		int **C3;
		initialize(C3, n / 2);
		int **C4;
		initialize(C4, n / 2);
		for (k = 0; k < n / 2; k++)
		{
			for (l = 0; l < n / 2; l++)
			{
				C1[k][l] = P[k][l] + S[k][l] - T[k][l] + V[k][l];
				C2[k][l] = R[k][l] + T[k][l];
				C3[k][l] = Q[k][l] + S[k][l];
				C4[k][l] = P[k][l] + R[k][l] - Q[k][l] + U[k][l];
			}
		}
		//for C1
		k = 0;
		for (i = 0; i < n / 2; i++, k++)
		{
			l = 0;
			for (j = 0; j < n / 2; j++, l++)
				C[k][l] = C1[i][j];
		}
		//for C2
		k = 0;
		for (i = 0; i < n / 2; i++, k++)
		{
			l = 0;
			for (j = n / 2; j < n; j++, l++)
				C[i][j] = C2[k][l];
		}
		//for C3
		k = 0;
		for (i = n / 2; i < n; i++, k++)
		{
			l = 0;
			for (j = 0; j < n / 2; j++, l++)
				C[i][j] = C3[k][l];
		}
		//for C4
		k = 0;
		for (i = n / 2; i < n; i++, k++)
		{
			l = 0;
			for (j = n / 2; j < n; j++, l++)
				C[i][j] = C4[k][l];
		}
	}
}
int main()
{
	int i, j, n = 4;

	int **A;
	int **B;
	int **C;
	initialize(A, n);
	initialize(B, n);
	initialize(C, n);

	cout << "Enter A: \n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cin >> A[i][j];
	}

	cout << "Enter B: \n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cin >> B[i][j];
	}

	cout << "A:\n";
	disp(A, n);
	cout << "B:\n";
	disp(B, n);
	strassen(n, A, B, C);
	cout << "C:\n";
	disp(C, n);
	return 0;
}

/*
Enter the number of stations:
6
Entry time for line 1: 2
Entry time for line 2: 4
Exit time for line 1: 3
Exit time for line 2: 2
Enter the operation time for individual stations of line 1
7 9 3 4 8 4
Enter the operation time for individual stations of line 2
8 5 6 4 5 7
Enter the transportation times *from* line 1
2 3 1 3 4
Enter the transportation times *from* line 2
2 1 2 2 1
*/
#include <iostream>
using namespace std;

int *o1; //output array containing the cost after each step/station if item first enters 1st line
int *o2; //output array containing the cost after each step/station if item first enters 2nd line

int *t1; //transportation costs between stations of 1st line(source) to 2nd line(destination)
int *t2; //transportation costs between stations of 2nd line(source) to 1st line(destination)

int *a1; //operation cost(time) at each individual station of line 1 is stored in this array
int *a2; //operation cost(time) at each individual station of line 2 is stored in this array

int *l1; //output path when first station is on first line
int *l2; //output path when first station is on second line

int main()
{
	int n; //number of stations in each line
	int i, j;
	int e1, e2; //entry time(time taken to reach station 1 of line 1 and line 2 respectively)
	int x1, x2; //exit time(time taken to reach the warehouse from station n(last) of line 1 and line 2 respectively)
	int o;		//(mincost)stores the cost of the cheaper path undertaken
	int l;		//stores whether exit in the cheaper case was from line 1 or 2

	/*Take input*/
	cout << "Enter the number of stations:\n";
	cin >> n;

	cout << "Entry time for line 1: ";
	cin >> e1;

	cout << "Entry time for line 2: ";
	cin >> e2;

	cout << "Exit time for line 1: ";
	cin >> x1;

	cout << "Exit time for line 2: ";
	cin >> x2;
	//Array Initializations
	o1 = new int[n];
	o2 = new int[n];

	t1 = new int[n - 1];
	t2 = new int[n - 1];

	a1 = new int[n];
	a2 = new int[n];

	l1 = new int[n - 1];
	l2 = new int[n - 1];

	//Fill up the station arrays
	cout << "Enter the operation time for individual stations of line 1\n";
	for (i = 0; i < n; i++)
		cin >> a1[i];
	cout << "Enter the operation time for individual stations of line 2\n";
	for (i = 0; i < n; i++)
		cin >> a2[i];

	//Fill up the transportation arrays
	cout << "Enter the transportation times *from* line 1\n";
	for (i = 0; i < n - 1; i++)
		cin >> t1[i];
	cout << "Enter the transportation times *from* line 2\n";
	for (i = 0; i < n - 1; i++)
		cin >> t2[i];

	//getting the answer
	o1[0] = e1 + a1[0];
	o2[0] = e2 + a2[0];

	for (i = 1; i < n; i++)
	{
		if (o1[i - 1] + a1[i] <= o2[i - 1] + t2[i - 1] + a1[i])
		{
			o1[i] = o1[i - 1] + a1[i];
			l1[i - 1] = 1;
		}
		else
		{
			o1[i] = o2[i - 1] + t2[i - 1] + a1[i];
			l1[i - 1] = 2;
		}
		if (o2[i - 1] + a2[i] <= o1[i - 1] + t1[i - 1] + a2[i])
		{
			o2[i] = o2[i - 1] + a2[i];
			l2[i - 1] = 2;
		}
		else
		{
			o2[i] = o1[i - 1] + t1[i - 1] + a2[i];
			l2[i - 1] = 1;
		}
	}

	if (o1[n - 1] + x1 <= o2[n - 1] + x2)
	{
		o = o1[n - 1] + x1;
		l = 1;
	}
	else
	{
		o = o2[n - 1] + x2;
		l = 2;
	}

	//print the stations used (from entry to exit)
	i = l;
	cout << "\nThe cost of minimum path is " << o << "\n";
	cout << "Line " << i << " Station " << n << "\n";
	if (l == 1)
	{
		for (j = n - 1; j > 0; j--)
		{
			i = l1[j - 1];
			cout << "Line " << i << " Station " << j << "\n";
		}
	}
	else
	{
		for (j = n - 1; j > 0; j--)
		{
			i = l2[j - 1];
			cout << "Line " << i << " Station " << j << "\n";
		}
	}
	return 0;
}
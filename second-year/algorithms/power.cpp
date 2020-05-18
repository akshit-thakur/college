#include <iostream>
using namespace std;

int count = 0; //counts number of iterations

int exponent(int x, int n)
{ //function to return x^n with complexity log n

	int z = x;

	int power = 1;

	while (n > 0)
	{

		while (n % 2 == 0)
		{

			n = n / 2;
			z = (z * z);
			count += 1;
		}

		n = n - 1;
		power = power * z;
	}

	return power;
}

int main()
{
	int a, n, result = 0; // a=base n=power result=a^n
	//long temp; long result=1;

	//input
	cout << "Enter base: ";
	cin >> a;
	cout << "Enter power: ";
	cin >> n;

	result = exponent(a, n);

	//output
	cout << "Result: " << result << "\n";
	cout << "No of iterations: " << count << "\n";

	/*if(n==0)
	result=1;
	else if(n==1)
	result=a;
	else{
		result=1;
		while(n>0){
			temp=a;
			for(i=1;i<=n/2;i*=2){
				temp=temp*temp;
			}
			result*=temp;
			n=n-i;
			count+=1;
		}
	}*/

	return 0;
}

// 17/01/2019

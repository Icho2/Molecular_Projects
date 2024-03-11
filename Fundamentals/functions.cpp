#include <iostream>
using namespace std;

double power(double, int); //stating functions

int main()
{
	int exponent=18;
	double base=5.3;
	double value;

	value = power(base,exponent);
	cout.precision(12);
	cout << value << endl;

	return 0;
}

double power(double a, int n) //functions stated above are expressed here
{
	int i;
	double val=a;

	for(i=1; i<n; i++)
		val *= a;
	
	return val;
}

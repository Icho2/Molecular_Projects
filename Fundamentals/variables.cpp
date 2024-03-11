#include <iostream>

using namespace std;

void junk1(int);
void junk2(int *); //went from 'int' to 'pointer to int'

int main()
{
	int i=1;

	cout << "This junk function doesn't know about the global i variable" << endl;
	
	cout << "in main, i= " << i << endl; //here we see that the value of i				            		   //inside junk(i) does't change
	junk1(i);
	cout << "in main, i= " << i << endl;
	
	cout << "" << endl;

	cout << "This junk function does know about the global i variable" << endl;
	cout << "in main, i= " << i << endl;
	junk2(&i);
	cout << "in main, i= " << i << endl;

	return 0;
}
 
void junk1(int i)
{
	i=2;
	cout << "in junk, i= " << i << endl;
}
void junk2(int *i)
{
	*i=2;
	cout << "in junk, i= " << *i << endl;
}

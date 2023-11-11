#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
using namespace std;

int main(){

	ifstream input("acetaldehyde.dat");
	double pos;
	int natom;
	double numero;
	string line;
	list<int> Z_val;
	list<double> x_vect;
	list<double> y_vect;
	list<double> z_vect;

	input >> natom;
	cout << natom << endl;
	for(int i=0; i < natom; i++)
	{
		input >> numero;
		Z_val.push_back(numero);
		input >> numero;
		x_vect.push_back(numero);
		input >> numero;
		y_vect.push_back(numero);
		input >> numero;
		z_vect.push_back(numero);
		cout << Z_val.back() << ", " << x_vect.back() << ", " << y_vect.back() << ", " << z_vect.back() << endl;
	}		

	input.close();
	
	return 0;
}

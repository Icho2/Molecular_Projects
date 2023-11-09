#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

int main(){

	ifstream input("acetaldehyde.dat");
	double pos;
	int natom;
	string line;
	vector<int> Z_val;
	vector<double> x_vect;
	vector<double> y_vect;
	vector<double> z_vect;

	input >> natom;

	for(int i=0; i < natom; i++)
	{
		input >> x_vect >> y_vect >> z_vect;
	}		

	input.close();

	cout << x_vect << endl;
	
	return 0;
}

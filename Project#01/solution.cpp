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

	while (input >> line){
		if (input >> natom){
			cout << natom << endl;		
		}

	}

	input.close();

	return 0;
}

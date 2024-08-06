#include <iostream>                                                                                                                                                              
#include <fstream>                                                                                                                                                                
#include "molecule.h"                                                                                                                                                             
#include <cassert>                                                                                                                                                                
#include <string>              
#include "../Project#01/eigen-3.4.0/Eigen/Dense"

using namespace std;                                                                                                                                                              
using namespace Eigen;                                                                                                                                                                                  

int main(){
	Molecule mol("input/h2o/DZ/geom.dat" ,0);
	string line;
	double integral;
	int mu, nu;
	int lines = 0;

	//Step1
	ifstream is("input/h2o/STO-3G/enuc.dat");
	assert(is.good());
	
	is >> mol.n_repulsion_energy;
	printf("%.15f\n", mol.n_repulsion_energy);
	is.close();
	
	//Step2
	is.open("input/h2o/STO-3G/s.dat");
	assert(is.good());
	
	while(!is.eof()){ //checking how many lines are present in the file
		lines += 1;
	}
	cout << lines << endl;

	is.clear(); //now we go back to the top of the file
	is.seekg(0, ios::beg);
        assert(is.good());
	
	MatrixXd S(lines, lines);
	
	while(!is.eof()){
		is >> mu >> nu >> integral;
		printf("%d %d %.5f\n", mu, nu, integral);
		S(mu, nu) = integral;
	       	
	}
	is.close();

	//printf("S matrix:\n");
	//cout << S << endl;
	return 0;
}       

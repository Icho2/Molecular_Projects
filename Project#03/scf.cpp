#include <iostream>                                                                                                                                                              
#include <fstream>                                                                                                                                                                
#include <cassert>                                                                                                                                                                
#include <string>              
#include "../Project#01/eigen-3.4.0/Eigen/Dense"

using namespace std;                                                                        using namespace Eigen;                                                                                                                                                                                  

int main(){
	string line;
	double integral;
	int mu, nu;
	int lines = 0;

	//Step1
	ifstream file1("input/h2o/STO-3G/enuc.dat");
	assert(file1.good());
	
	file1 >> mol.n_repulsion_energy;
	printf("%.15f\n", mol.n_repulsion_energy);
	file1.close();
	
	//Step2
	ifstream file2("input/h2o/STO-3G/s.dat");
	assert(file2.good());
	
	while(getline(file2,line)){ //checking how many lines are present in the file
		lines += 1;
	}
	cout << lines << endl;
	file2.close(); //now we go back to the top of the file
	
	ifstream file3("input/h2o/STO-3G/s.dat");
	assert(file3.good());
	MatrixXd S(lines, lines);
	
	for(int i=0; i < lines; i++){
		file3 >> mu >> nu >> integral;
		S(mu, nu) = integral;
	       	
	}
	file3.close();

	
	return 0;
}       

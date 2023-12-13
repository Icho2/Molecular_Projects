#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>

int main(){
//Step 1
	//check if you are able to open up the molcule file first
	std::ifstream input("acetaldehyde.dat");
	if (!input.is_open()){
		std::cerr << "Youre gay.\n";
	       return 1;
	}

	double pos; //
	int natom; //number of atoms in the molecule
	input >> natom;
	double numero; //atomic number of a said atom
	std::string line;
	std::vector<int> Z_val(natom);
  	std::vector<double> x_vect(natom);
  	std::vector<double> y_vect(natom);
  	std::vector<double> z_vect(natom);

	//std::cout << natom << "\n";
	for(int i=0; i < natom; i++)
	{
		input >> numero;
		Z_val[i] = numero;
		input >> numero;
		x_vect[i] = numero;
		input >> numero;
		y_vect[i] = numero;
		input >> numero;
		z_vect[i]= numero;
		//std::cout << Z_val[i] << ", " << x_vect[i] << ", " << y_vect[i] << ", " << z_vect[i] << "\n";
	}		

	input.close();

//Step 2
	double xij, yij, zij;
	std::vector<std::vector<double>> R(natom, std::vector<double>(natom, 0.0));
	
	for(int i=0; i < natom; i++){
		for(int j=0; j < natom; j++){
			xij = x_vect[i] - x_vect[j];
			yij = y_vect[i] - y_vect[j];
			zij = z_vect[i] - z_vect[j];;
			R[i][j] = sqrt(pow(xij,2) + pow(yij,2) + pow(zij,2));
			std::cout << R[i][j] << "\n";
			}	
		}
	return 0;
}

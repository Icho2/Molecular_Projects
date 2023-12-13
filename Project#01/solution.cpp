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
	std::ifstream input("input/benzene.dat");
	if (!input.is_open()){
		std::cerr << "Uninstall yourself.\n";
	       return 1;
	}

	int natom; //number of atoms in the molecule
	input >> natom;
	double numero; //using it to read the inputs of the molecule file
	std::vector<int> Z_val(natom); //atomic number of a said atom
  	std::vector<double> x_vect(natom); // x values
  	std::vector<double> y_vect(natom); // y ''
  	std::vector<double> z_vect(natom); // z ''

	//std::cout << natom << "\n";
	for(int i=0; i < natom; i++)
	{
		input >> numero;
		Z_val[i] = numero;
		input >> std::setprecision(12) >> numero;
		x_vect[i] = numero;
		input >> std::setprecision(12) >> numero;
		y_vect[i] = numero;
		input >> std::setprecision(12) >> numero;
		z_vect[i]= numero;
		//std::cout << Z_val[i] << ", " << std::setprecision(12) << x_vect[i] << ", " << std::setprecision(12) << y_vect[i] << ", " << std::setprecision(12) << z_vect[i] << "\n";
	}		

	input.close();

//Step 2
	//int R_size = 0;
	double xij, yij, zij;

	//generating the size of vector R
	//for(int i=0;i<natom;i++){
	//	R_size = R_size + (i-1);
	//}
	//std::vector<double> R()
	std::vector<std::vector<double>> R(natom, std::vector<double>(natom, 0.0));
	
	for(int i=0; i < natom-1; i++){
		for(int j=i+1; j < natom; j++){
			xij = x_vect[i] - x_vect[j];
			yij = y_vect[i] - y_vect[j];
			zij = z_vect[i] - z_vect[j];;
			R[i][j] = sqrt(pow(xij,2) + pow(yij,2) + pow(zij,2));
			std::cout << R[i][j] << " ";
			}	
		std::cout << "\n";
		}
	return 0;
}

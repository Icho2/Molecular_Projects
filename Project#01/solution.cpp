#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <cstdio>
#include <string>
#include <cmath>

int main(){
//Step 1
	std::ifstream input("acetaldehyde.dat");
	double pos;
	int natom;
	double numero;
	std::string line;
  	int *Z_val = new int[natom];
  	double *x_vect = new double[natom];
  	double *y_vect = new double[natom];
  	double *z_vect = new double[natom];

	input >> natom;
	std::cout << natom << "\n";
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
		std::cout << Z_val.back() << ", " << x_vect.back() << ", " << y_vect.back() << ", " << z_vect.back() << "\n";
	}		

	input.close();

//Step 2
	double xij, yij, zij;
	double R[natom][natom];
	
	for(int i=0; i < natom; i++){
		for(int j=0; j < natom; j++){
			xij = x_vect[i] - x_vect[j];
			yij = y_vect[i] - y_vect[j];
			zij = z_vect[i] - z_vect[j];;
			R[i][j] = sqrt(pow(xij,2) + pow(yij,2) + pow(zij,2));
			std::cout << R[i][j] << "\n";
			}	
		}

	//deleting data after its served its purpose
	for(int i=0; i < mol.natom; i++)
  		delete[] R[i];
	delete[] R;


	return 0;
}

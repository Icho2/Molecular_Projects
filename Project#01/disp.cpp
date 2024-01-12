#include <iostream>
#include "molecule.h"
#include <fstream>

int main(){
	
	std::ifstream file;
	file.open("acetaldehyde.dat");
	molecule acetaldehyde;
	
	int natom;
	file >> natom;
	std::cout << natom << "\n";
	int charge;
	int numero;
	int *z_val;
	double geom;
	std::string point_group;
	
	//acetaldehyde.disp_coordinates();
	
	return 0;
}

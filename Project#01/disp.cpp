#include <iostream>
#include "molecule.h"
#include <fstream>

int main(){
	
	std::ifstream file;
	file.open("acetaldehyde.dat");
	
	Molecule acetaldehyde;
	
	file >> acetaldehyde.natom;
	std::cout << acetaldehyde.natom << "\n";
	acetaldehyde.charge = 0;
	acetaldehyde.zvals = new int[acetaldehyde.natom];
	acetaldehyde.geom = new double* [acetaldehyde.natom];
	
	for(int i=0; i < acetaldehyde.natom; i++)
	{
		acetaldehyde.geom[i] = new double[3];
	}


	return 0;
}

#include <iostream>
#include "molecule.h"

int main(){
	
	molecule acetaldehyde;
	
	int natom;
	int charge;
	int numero;
	int *z_val;
	double geom;
	std::string point_group;

	acetaldehyde.disp_coordinates();
	
	return 0;
}

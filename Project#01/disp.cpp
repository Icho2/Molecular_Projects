#include <iostream>
#include "molecule.h"

int main(){
	
	molecule acetaldehyde("input/acetaldehyde.dat");
	acetaldehyde.get_coordinates();
	return 0;
}

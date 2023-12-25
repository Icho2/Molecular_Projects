#include <iostream>
#include "molecule.h"

int main(){
	
	molecule acetaldehyde("input/acetaldehyde.dat");
	acetaldehyde.display_coordinates();
	return 0;
}

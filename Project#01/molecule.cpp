#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>

class molecule{
	
	//Constructor 
	molecule(std::string xyz_file);

    	int natom; //number of atoms in the molecule
	double numero; //using it to read the inputs of the molecule file
	std::vector<int> Z_val(natom); //atomic number of a said atom
  	std::vector<double> x_vect(natom); // x values
  	std::vector<double> y_vect(natom); // y ''
  	std::vector<double> z_vect(natom); // z ''

    	int get_coordinates{
        //Step 1: Read the Coordinate Data from Input
        //check if you are able to open up the molcule file first
		std::ifstream input(xyz_file);
	    	if (!input.is_open()){
			std::cerr << "Uninstall yourself.\n";
	        	return 1;
	    	}

        	input >> natom;
        	std::cout << "Number of atoms: " << natom << "\n";
	    	std::cout << "Input Cartesian coordinates:\n";
	    	for(int i=0; i < natom; i++)
	    	{
			input >> numero;
		    	Z_val[i] = numero;
            		input >> std::fixed >> std::setprecision(12) >> numero;
            		x_vect[i] = numero;
            		input >> std::fixed >> std::setprecision(12) >> numero;
            		y_vect[i] = numero;
            		input >> std::fixed >> std::setprecision(12) >> numero;
            		z_vect[i]= numero;
            		printf("%d %20.12f %20.12f %20.12f\n", (int) Z_val[i], x_vect[i], y_vect[i], z_vect[i]);
        	}		

    	input.close();
        return 0;
    	};
};

int main(){
	
	molecule acetaldehyde("input/acetaldehyde.dat");
	acetaldehyde.display_coordinates();
	return 0;
	
}

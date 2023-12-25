#ifndef molecule_h
#define molecule_h
#include <string>
#include <vector>

class molecule {
public:
        int natom;
    int numero;
	std::vector<int> Z_val(natom); //atomic number of a said atom
    std::vector<double> x_vect(natom); // x values
    std::vector<double> y_vect(natom); // y ''
  	std::vector<double> z_vect(natom); // z ''
};
    molecule(std::string xyz_file);

    int display_coordinates();
    
#endif
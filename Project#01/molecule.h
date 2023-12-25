#ifndef molecule_h
#define molecule_h
#include <string>
#include <vector>

class molecule {
public:
    molecule(std::string xyz_file);

    void get_coordinates();

private:
    int natom; //number of atoms in the molecule
	double numero; //using it to read the inputs of the molecule file
	std::vector<int> Z_val(natom); //atomic number of a said atom
  	std::vector<double> x_vect(natom); // x values
  	std::vector<double> y_vect(natom); // y ''
  	std::vector<double> z_vect(natom); // z ''
    std::string molecule_info;

};
#endif
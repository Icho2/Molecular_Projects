#include <string>

class molecule {
public:

    int natom;
    int charge;
    int numero;
	int *z_val; //atomic number of a said atom
    double geom;
    std::string point_group;

    void disp_coordinates();

    molecule();
    ~molecule();
};
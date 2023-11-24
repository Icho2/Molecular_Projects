#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <string>

class Molecule
{
  public:
    int natom;
    int charge;
    int *zvals;
    double **geom;
    string point_group;
 
    void print_geom();
    void rotate(double phi);
    void translate(double x, double y, double z);
    double bond(int atom1, int atom2);
    double angle(int atom1, int atom2, int atom3);
    double torsion(int atom1, int atom2, int atom3, int atom4);
 
    Molecule();
    ~Molecule();
};

int main(){
//Step 1
	std::ifstream input("acetaldehyde.dat");
	double **R = new double* [mol.natom];
	double pos;
	int natom;
	double numero;
	string line;
	list<int> Z_val;
	list<double> x_vect;
	list<double> y_vect;
	list<double> z_vect;

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
	for(int i=0; i < mol.natom; i++){
  		R[i] = new double[mol.natom];
	}
	
	for(int i=0; i < mol.natom; i++){
		for(int j=0; j < mol.atom; j++){
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

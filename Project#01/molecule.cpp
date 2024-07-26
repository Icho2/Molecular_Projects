#include "molecule.h"
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cmath>

//functions
void Molecule::print_geom()
{
	for(int i=0; i < natom; i++)
		printf("%d %8.5f %8.5f %8.5f\n", zvals[i], geom[i][0], geom[i][1], geom[i][2]);
}

void Molecule::translate(double x, double y, double z)
{
	for(int i=0; i < natom; i++){
		geom[i][0] += x;
		geom[i][1] += y;
		geom[i][2] += z;
	}
}

double Molecule::bond(int atom1, int atom2)
{
        double R;
        double x, y, z;
        
	x = geom[atom2][0] - geom[atom1][0];
        y = geom[atom2][1] - geom[atom1][1];
        z = geom[atom2][2] - geom[atom1][2];
        R = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
             
	return R;
}

double Molecule::angle(int atom1, int atom2, int atom3)
{
	double phi;
	double *eij;
	double *ejk;
	double R;
        
	R = bond(atom1,atom2);
	eij[0] = -(geom[atom1][0] - geom[atom2][0])/R;
        eij[1] = -(geom[atom1][1] - geom[atom2][1])/R;
        eij[2] = -(geom[atom1][2] - geom[atom2][2])/R;

	R = bond(atom2, atom3);
	ejk[0] = -(geom[atom2][0] - geom[atom3][0])/R;
        ejk[1] = -(geom[atom2][1] - geom[atom3][1])/R;
        ejk[2] = -(geom[atom2][2] - geom[atom3][2])/R;

        phi = acos((-eij[0] * ejk[0]) + (-eij[1] * ejk[1]) + (-eij[2] * ejk[2]));
        
	delete[] eij;
        delete[] ejk;
	
	return phi;	
	
}

//constructor
Molecule::Molecule(const char* filename, int q){

	charge = q;

	std::ifstream is(filename);
	assert(is.good());

        is >> natom;
	
	//allocate space
	zvals = new int[natom];
	geom = new double* [natom];
	for(int i=0; i < natom; i++)
		geom[i] = new double[3];
	
        for(unsigned int i=0; i < natom; i++)
                is >> zvals[i] >> geom[i][0] >> geom[i][1] >> geom[i][2];
        is.close();
}

//destructor
Molecule::~Molecule()
{
  delete[] zvals;
  for(int i=0; i < natom; i++)
    delete[] geom[i];
  delete[] geom;
}

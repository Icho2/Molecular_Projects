#include "molecule.h"
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>

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

Molecule::~Molecule()
{
  delete[] zvals;
  for(int i=0; i < natom; i++)
    delete[] geom[i];
  delete[] geom;
}

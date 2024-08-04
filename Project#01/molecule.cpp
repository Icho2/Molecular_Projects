#include "molecule.h"
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

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
        double r;
        double x, y, z;
        
	x = geom[atom2][0] - geom[atom1][0];
        y = geom[atom2][1] - geom[atom1][1];
        z = geom[atom2][2] - geom[atom1][2];
        r = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));     
	return r;
}

double Molecule::angle(int atom1, int atom2, int atom3)
{
	double phi;
	double eij[3];
	double ejk[3];
	double R;

	//cout << "it works here" << endl;
        
	R = bond(atom1, atom2);
	eij[0] = (geom[atom1][0] - geom[atom2][0])/R;
        eij[1] = (geom[atom1][1] - geom[atom2][1])/R;
        eij[2] = (geom[atom1][2] - geom[atom2][2])/R;

	R = bond(atom2, atom3);
	ejk[0] = -(geom[atom2][0] - geom[atom3][0])/R;
        ejk[1] = -(geom[atom2][1] - geom[atom3][1])/R;
        ejk[2] = -(geom[atom2][2] - geom[atom3][2])/R;

        phi = acos((eij[0] * ejk[0]) + (eij[1] * ejk[1]) + (eij[2] * ejk[2]));
	
	
	return phi;	
	
}

double Molecule::oop_angle(int atom1, int atom2, int atom3, int atom4)
{
	double ekj[3];
	double ekl[3];
	double eki[3];
	double c1, c2, c3;
	double ckjjl[3];
	double theta;
	
	ekj[0] = -(geom[atom3][0] - geom[atom2][0])/bond(atom3, atom2);
        ekj[1] = -(geom[atom3][1] - geom[atom2][1])/bond(atom3, atom2);
        ekj[2] = -(geom[atom3][2] - geom[atom2][2])/bond(atom3, atom2);
	
	ekl[0] = -(geom[atom3][0] - geom[atom4][0])/bond(atom3, atom4);
        ekl[1] = -(geom[atom3][1] - geom[atom4][1])/bond(atom3, atom4);
        ekl[2] = -(geom[atom3][2] - geom[atom4][2])/bond(atom3, atom4);
	
	eki[0] = -(geom[atom3][0] - geom[atom1][0])/bond(atom3, atom1);
        eki[1] = -(geom[atom3][1] - geom[atom1][1])/bond(atom3, atom1);
        eki[2] = -(geom[atom3][2] - geom[atom1][2])/bond(atom3, atom1);
	
	//cout << "ekj:" << endl;
	//cout << ekj[0] << endl;
	//cout << ekj[1] << endl;
	//cout << ekj[2] << endl;
	
	//cross product
	c1 = (ekj[1]*ekl[2]) - (ekj[2]*ekl[1]);
	c2 = (ekj[2]*ekl[0]) - (ekj[0]*ekl[2]);
	c3 = (ekj[0]*ekl[1]) - (ekj[1]*ekl[0]);
	
	//dividing by sin theta
	ckjjl[0] = c1 / sin(angle(atom2, atom3, atom4));
	ckjjl[1] = c2 / sin(angle(atom2, atom3, atom4));
	ckjjl[2] = c3 / sin(angle(atom2, atom3, atom4));
	
	//dot product
	theta = asin((ckjjl[0]*eki[0]) + (ckjjl[1]*eki[1]) + (ckjjl[2]*eki[2])); 
	
	return theta*(180.0 / acos(-1.0));
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
	
        for(int i=0; i < natom; i++)
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

#include "molecule.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <math.h>

using namespace std;

int main()
{
  Molecule mol("acetaldehyde.dat", 0);

  //Part1
  cout << "Number of atoms: " << mol.natom << endl;
  cout << "Input Cartesian coordinates:\n";
  mol.print_geom();
  
  //Part2
  cout << "Bond lengths:" << endl;
        double **R;
        double x, y, z;

        for(int i=0; i < mol.natom; i++){
                for(int j=0; j < i; j++){
			R[i][j] = mol.bond(i,j);
                        printf("%2d-%2d %10.5f\n", i, j, R[i][j]);
                }
	}

  //Part3
  cout << "Bond angles:" << endl;
	double phi;
	double *eij;
	double *ejk;
  for(int i=0; i < mol.natom; i++){
	for(int j=0; j < i; j++){
		for(int k=0; k < j; k++){
			if(R[i][j] < 4.0 && R[k][j] < 4.0){
				phi = mol.angle(i,j,k);
				printf("%2d-%2d-%2d %10.6f\n", i, j, k, phi*(180.0 / M_PI));
			}
		}
	}
  }

  return 0;
}

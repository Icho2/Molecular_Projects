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
        double** R = new double* [mol.natom];		
        double x, y, z;

        for(int i=0; i < mol.natom; i++){
		R[i] = new double [mol.natom];
	}
	for(int i=0; i < mol.natom; i++){
                for(int j=0; j < i; j++){
			R[i][j] = mol.bond(i,j);
                        printf("%2d-%2d %10.5f\n", i, j, R[i][j]);
                }
	}

  //Part3
  cout << "Bond angles:" << endl;
	double phi;
  	for(int i=0; i < mol.natom; i++){
		for(int j=0; j < i; j++){
			for(int k=0; k < j; k++){
				if(R[i][j] < 4.0 && R[j][k] < 4.0){
					phi = mol.angle(i,j,k);
					printf("%2d-%2d-%2d %10.6f\n", i, j, k, phi*(180.0 / acos(-1.0)));
				}
			}
		}
  	}

  //Part4
  cout << "Out-of-Plane Angles" << endl;
  	double theta;
	for(int i=0; i < mol.natom; i++){
		cout << i << endl;
		for(int j=0; j < mol.natom; j++){
			for(int k=0; k < mol.natom; k++){
				for(int l=0; l < mol.natom; l++){
					printf("%2d-%2d-%2d-%2d %10.6f\n", i, j, k, l, mol.oop_angle(i,j,k,l));
				}
			}
		}
	}

  return 0;
}

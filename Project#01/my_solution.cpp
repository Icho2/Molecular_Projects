#include "molecule.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include "eigen-3.4.0/Eigen/Dense"

using namespace Eigen;
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
  cout << "Out-of-Plane Angles:" << endl;
  	double theta;
	for(int i=0; i < mol.natom; i++){
		for(int j=0; j < mol.natom; j++){
			for(int k=0; k < mol.natom; k++){
				for(int l=0; l < j; l++){
					if(mol.bond(k,j)< 4.0 && mol.bond(k,l) < 4.0 && mol.bond(k,i) < 4.0 && i!=j && i!=k && i!=l && j!=k && j!=l && k!=l){
						printf("%2d-%2d-%2d-%2d %10.6f\n", i, j, k, l, mol.oop_angle(i,j,k,l)*(180.0 / acos(-1.0)));
					}
				}
			}
		}
	}

  //Part5
  cout << "Torsion/Dihedral Angles:" << endl;
  double tau;
        for(int i=0; i < mol.natom; i++){
                for(int j=0; j < i; j++){
                        for(int k=0; k < j; k++){
                                for(int l=0; l < k; l++){
                                        if(mol.bond(k,j)< 4.0 && mol.bond(k,l) < 4.0 && mol.bond(k,i) < 4.0 && i!=j && i!=k && i!=l && j!=k && j!=l && k!=l){
                                                printf("%2d-%2d-%2d-%2d %10.6f\n", i, j, k, l, mol.torsion(i,j,k,l)*(180.0 / M_PI));
                                        }
                                }
                        }
                }
        }
  
  //Part6
  cout << "Center-of-Mass Translation:" << endl;
  
  printf("%.4f	%.4f	%.4f\n ", mol.com("x"), mol.com("y"), mol.com("z"));	

  //Part7
  cout << "Principal Moments of Inertia" << endl;
  MatrixXd I(3, 3);
  I(0,0) = mol.pmi("x","x");
  I(0,1) = -mol.pmi("x","y");
  I(0,2) = -mol.pmi("x","z");
  I(1,0) =  mol.pmi("y","x");
  I(1,1) =  mol.pmi("y","y");
  I(1,2) = -mol.pmi("y","z");
  I(2,0) =  mol.pmi("z","x");
  I(2,1) =  mol.pmi("z","y");
  I(2,2) =  mol.pmi("z","z");

  cout << "Here is moment of inertia tensor:\n" << I << endl;

  SelfAdjointEigenSolver<MatrixXd> eigensolver(I);
  if (eigensolver.info() != Eigen::Success) abort();
  cout << "Here are the principal moments of inertia (eigenvalues) in amu bohr^2, amu A^2, and g cm^2,respectively:\n" << endl;
  printf("amu bohr^2:\n");
  cout << eigensolver.eigenvalues() << endl;
  printf("amu A^2:\n");
  cout << eigensolver.eigenvalues()*pow(0.53,2) << endl;
  printf("g cm^2:\n");
  cout << eigensolver.eigenvalues()*pow(5.29177249e-10,2)*1.66054e-24 << endl;
 
  printf("Based on these moments of inertia, our molecule is a asymmetric rotor.")
  return 0;
}

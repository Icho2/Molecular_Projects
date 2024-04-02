#include <iostream>
#include <fstream>
#include <cmath>

using std::endl;
using std::cout;
using std::ifstream;
using std::string;
using std::ios;

int main(){
// PART 1: Read Coordinate Data
	cout << "PART 1" << endl;
	FILE *my_input;		
	string line;
	int natom;
	my_input = fopen("input/acetaldehyde.dat", "r");

	fscanf(my_input, "%d", &natom);
	int zval[natom];
        double coordinates[natom][3];
	for(int i=0; i < natom; i++)
		fscanf(my_input, "%d %lf %lf %lf",  &zval[i], &coordinates[i][0], &coordinates[i][1], &coordinates[i][2]);
	
	cout << natom << endl;
	for(int i=0; i<natom; i++)
		printf("%d %lf %lf %lf \n",  zval[i], coordinates[i][0], coordinates[i][1], coordinates[i][2]);
	
//PART 2: Bond Lengths
	cout << "PART 2" << endl;
	double R[natom][natom];	
	double x, y, z;

	for(int i=0; i < natom; i++){
		for(int j=0; j < natom; j++){
			x = coordinates[i][0] - coordinates[j][0];
			y = coordinates[i][1] - coordinates[j][1];
			z = coordinates[i][2] - coordinates[j][2];
			R[i][j] = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
			printf("%2d-%2d %10.6f\n", i, j, R[i][j]);
		}
	}

//PART 3: Bond Angles
	cout << "PART 3" << endl;
	double e[natom][natom][3];
	double phi[natom][natom][natom];
	
	for(int i=0; i < natom; i++){
		for(int j=0; j < i; j++){
			e[i][j][0] = -(coordinates[i][0] - coordinates[j][0])/R[i][j];
			e[i][j][1] = -(coordinates[i][1] - coordinates[j][1])/R[i][j];
			e[i][j][2] = -(coordinates[i][2] - coordinates[j][2])/R[i][j];
		}
	}
	
	for(int i=0; i < natom; i++){
		for(int j=0; j < i; j++){
			for(int k=0; k < j; k++){
				phi[i][j][k] = acos((-e[i][j][0] * e[j][k][0]) + (-e[i][j][1] * e[j][k][1]) + (-e[i][j][2] * e[j][k][2])); 
				printf("%2d-%2d-%2d %10.6f\n", i, j, k, phi[i][j][k]*(180.0 / M_PI));
			}
		}
	}
//PART 4: Out-of-Plane Angles
	cout << "PART 4" << endl;
	double theta[natom][natom][natom][natom];
	double cross[3];
	double dot;
	
	for(int i=0; i < natom; i++){
		for(int j=0; j < natom; j++){
			for (int k=0; k < natom; k++){
				for(int l=0;  l < natom; l++){
					if(i!=j && i!=k && i!=l && j!=k && j!=l && k!=l && R[i][k] < 4.0 && R[k][j] < 4.0 && R[k][l] < 4.0) { 
						cross[0] = ((e[k][j][1]*e[k][l][2]) - (e[k][j][2]*e[k][l][1])); 
						cross[1] = ((e[k][j][2]*e[k][l][0]) - (e[k][j][0]*e[k][l][2])); 
						cross[2] = ((e[k][j][0]*e[k][l][1]) - (e[k][j][1]*e[k][l][0]));
						dot = (cross[0]*e[k][i][0]) + (cross[1]*e[k][i][1]) + (cross[2]*e[k][i][2]);
						theta[i][j][k][l] = asin(dot/sin(phi[j][k][l]));
						printf("%2d-%2d-%2d-%2d %10.6f\n", i, j, k, l, theta[i][j][k][l]);
					}
				}  
			}
		}
	}
	
	return 0;
}

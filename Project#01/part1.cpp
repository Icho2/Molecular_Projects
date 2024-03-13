#include <iostream>
#include <fstream>

using std::endl;
using std::cout;
using std::ifstream;
using std::string;
using std::ios;

int main(){
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
	
	return 0;	
}

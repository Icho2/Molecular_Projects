#include "HF.h"
#include <string>
#include <fstream>
#include <cassert>
#include "../Project#01/eigen-3.4.0/Eigen/Dense"

using namespace std;
using namespace Eigen;

//functions
void HF::get_n_repulsion_energy(string filepath)
{
	ifstream file(filepath);
	assert(file.good());

	file >> n_repulsion_energy;
	file.close();
}

MatrixXd HF::two_variable_integrals(string filepath)
{
	string line;
	double integral;
	int mu, nu;
	int lines = 0;

	ifstream file1(filepath);
	assert(file1.good());
	
	while(getline(file1,line)){ //checking how many lines are present in the file
		lines += 1;
        }
        
        file1.close(); //now we go back to the top of the file

        ifstream file2(filepath);
        assert(file2.good());
        MatrixXd S(lines, lines);

        for(int i=0; i < lines; i++){
                file2 >> mu >> nu >> integral;
                S(mu, nu) = integral;

        }
	file2.close();
	
	return S;
}


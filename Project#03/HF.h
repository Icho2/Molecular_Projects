#include <iostream>
#include <string>
#include "../Project#01/eigen-3.4.0/Eigen/Dense"

using namespace std;
using namespace Eigen;

class HF
{
	public:
		//variables
		double n_repulsion_energy;
		double **AO_overlap_integrals;
		double **KE_integrals;		
		double **nuclear_attraction_integrals;
		
		//functions
		void get_n_repulsion_energy(string filepath);
		MatrixXd two_variable_integrals(string filepath);

		HF(string filepath);
		~HF();  
};

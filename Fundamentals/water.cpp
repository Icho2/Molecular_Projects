#include "molecule.h"

using namespace std;

int main(int argc, char *argv[])
{
	Molecule h2o;

	h2o.natom = 3;
	h2o.charge = 0;
	h2o.zvals = new int[h2o.natom];
	h2o.geom = new double* [h2o.natom];
	for(int i=0; i < h2o.natom; i++)
		h2o.geom[i] = new double[3];
	h2o.zvals[0] = 8;
  	h2o.geom[0][0] =  0.000000000000;
  	h2o.geom[0][1] =  0.000000000000;
  	h2o.geom[0][2] = -0.122368916506;
  	h2o.zvals[1] = 1;
  	h2o.geom[1][0] =  0.000000000000;
  	h2o.geom[1][1] =  1.414995841403;
 	h2o.geom[1][2] =  0.971041753535;
  	h2o.zvals[2] = 1;
  	h2o.geom[2][0] =  0.000000000000;
  	h2o.geom[2][1] = -1.414995841403;
  	h2o.geom[2][2] =  0.971041753535;
	
	h2o.print_geom();
	h2o.translate(5, 0, 0);
	h2o.print_geom();

	delete[] h2o.zvals;
	for(int i=0; i < h2o.natom; i++)
		delete[] h2o.geom[i];
	delete[] h2o.geom;
	
	return 0;
}

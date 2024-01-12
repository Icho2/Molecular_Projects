#include "molecule.h"
#include <cstdio>

int disp_coordinates()
{
	for(int i=0; i < natom; i++)
    	{printf("%d %8.5f %8.5f %8.5f\n", z_val[i], geom[i][0], geom[i][1], geom[i][2]);}
}

molecule::molecule(){ }
molecule::~molecule(){ }

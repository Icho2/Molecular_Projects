#include <iostream>                                                                                                                                                              
#include <fstream>                                                                                                                                                                
#include "molecule.h"                                                                                                                                                             
#include <cassert>                                                                                                                                                                
                                                                                                                                                                                  
using namespace std;                                                                                                                                                              
                                                                                                                                                                                  
int main(){                                                                                                                                                                       
        Molecule mol("input/h2o/DZ/geom.dat" ,0);                                                                                                                                 
                                                                                                                                                                                  
        ifstream is("input/h2o/DZ/enuc.dat");                                                                                                                                     
        assert(is.good());                                                                                                                                                        
                                                                                                                                                                                  
        is >> mol.n_repulsion_energy;                                                                                                                                             
                                                                                                                                                                                  
        printf("%.15f\n", mol.n_repulsion_energy);                                                                                                                                
                                                                                                                                                                                  
        is.close();                                                                                                                                                               
                                                                                                                                                                                  
        ifstream io("input/h2o/DZ/s.dat");                                                                                                                                        
                                                                                                                                                                                  
        for(int i=1; i < 8;i++){                                                                                                                                                  
                for(int j=1; j <= i; j++){                                                                                                                                        
                        printf("%d      %d\n",i,j);                                                                                                                               
                }                                                                                                                                                                 
        }                                                                                                                                                                         
                                                                                                                                                                                  
        return 0;                                                                                                                                                                 
}       

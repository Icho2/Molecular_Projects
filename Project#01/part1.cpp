#include <iostream>
#include <fstream>

using std::endl;
using std::cout;
using std::ifstream;
using std::string;
using std::ios;

int main(){
	ifstream my_input("input/acetaldehyde.dat", ios::in);		
	string line;
	if (my_input.is_open()) {
		while (getline(my_input, line)) {
			cout << line << endl;
		}
		my_input.close();
	}
	
	else {
		cout << "Unable to open file" << endl;
	}
	return 0;	
}

#ifndef molecule_h
#define molecule_h
#include <string>
#include <vector>

class molecule {
public:
    molecule(std::string xyz_file);

    int display_coordinates();

private:

};
#endif
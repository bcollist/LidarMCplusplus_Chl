#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(){
  ////////////////////////////////////////////////////////////
  //// Phytoplankton Refractive Index File Parameters ////////
  ////////////////////////////////////////////////////////////
  vector <string> wavelength_pandf_storage;
  vector <string> aw_storage;

  string wavelength_pandf_str;
  string aw_str;

  ifstream pandfCSV("pandf.csv"); // open up a file stream
  if (pandfCSV.is_open()){
    while (pandfCSV.good()){
      getline(pandfCSV,wavelength_pandf_str,',');
      getline(pandfCSV,aw_str,'\n');

      wavelength_pandf_storage.push_back(wavelength_pandf_str);
      aw_storage.push_back(aw_str);

    }
  }
  else{
    cout << "Error Opening" << endl;
  }

  double wavelength_pandf[wavelength_pandf_storage.size()];
  double aw[aw_storage.size()];

  for (int i = 0; i<wavelength_pandf_storage.size()-1; i++){
    wavelength_pandf[i] = stod(wavelength_pandf_storage[i]);
    aw[i] = stod(aw_storage[i]);
    cout << aw[i] << endl;

  }
}

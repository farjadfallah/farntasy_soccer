#include "DataProvider.hpp"
#include <string>
#include<sstream>
#include<fstream>
#include <iostream>

using namespace std;

DataProvider::DataProvider(std::string file_path){
    file = ifstream(file_path);
}

DataProvider::~DataProvider(){
    file.close();
}

bool DataProvider::get_team_name_from_initial_file(std::string& team_name){
    string team_name;
    getline(file, team_name, ',');
}

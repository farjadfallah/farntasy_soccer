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
    char tmp;
    while (file.get(tmp)) {
        if(tmp == ','){
            return true;
        }
        if (tmp == EOF){
            return false;
        }
        team_name = team_name + tmp;
    }
    return false;
}

bool DataProvider::get_Player_from_initiail_file(std::string& player_name){
    char tmp;
    while (file.get(tmp)) {
        if(tmp == ';'){
            return true;
        }
        if (tmp == ',' || tmp == '\n'){
            player_name = player_name;
            return false;
        }
        player_name = player_name + tmp;
    }
}

void DataProvider::get_header(){
    string tmp;
    getline(file,tmp);
}

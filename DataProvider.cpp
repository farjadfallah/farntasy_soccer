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
    return get_word_untill_delimiter(team_name, ',' , EOF);
}

bool DataProvider::get_Player_from_initiail_file(std::string& player_name){
    return get_word_untill_delimiter(player_name, ';' , ',', 13);
}

void DataProvider::get_header(){
    string tmp;
    getline(file,tmp);
}

bool DataProvider::get_word_untill_delimiter(std::string& word, char delimiter, char first_end_sign, char second_end_sign ){
    char tmp;
    while (file.get(tmp)) {
        if(tmp == delimiter){
            return true;
        }
        if (tmp == first_end_sign || tmp == second_end_sign){
            return false;
        }
        word = word + tmp;
    }
}
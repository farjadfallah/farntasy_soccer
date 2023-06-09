#include "ReadFileUtil.hpp"
#include <string>
#include<sstream>
#include<fstream>
#include <iostream>
#include "Exceptions.hpp"

using namespace std;


//constructor and destructor

ReadFileUtil::ReadFileUtil(std::string file_path){
    file = ifstream(file_path);
}

ReadFileUtil::~ReadFileUtil(){
    file.close();
}



//utils

void ReadFileUtil::get_header(){
    string tmp;
    getline(file,tmp);
}

bool ReadFileUtil::get_word_untill_delimiter(std::string& word, char delimiter, char first_end_sign, char second_end_sign ){
    char tmp;
    char dump;
    while (file.get(tmp)) {
        if(tmp == delimiter){
            return true;
        }
        if (tmp == first_end_sign){
            return false;
        }
        if (tmp == '\n'){
            return false;
        }
         if (tmp == second_end_sign){
            file.get(dump);
            return false;
        }
        word = word + tmp;
    }
    return false;
}


//Initial file

bool ReadFileUtil::get_team_name_from_initial_file(std::string& team_name){
    return get_word_untill_delimiter(team_name, ',' , EOF);
}

bool ReadFileUtil::get_Player_from_file(std::string& player_name){
    return get_word_untill_delimiter(player_name, ';' , ',', 13);
}


//Weeks file
void ReadFileUtil::get_team_names_from_week_file(std::string& first_team, std::string& second_team ){
    getline(file, first_team, ':');
    getline(file, second_team, ',');
}

void ReadFileUtil::get_team_goals_from_week_file(int& first_team, int& second_team ){
    std::string first_team_str, second_team_str;
    getline(file, first_team_str, ':');
    getline(file, second_team_str, ',');
    first_team = stoi(first_team_str);
    second_team = stoi(second_team_str);
}
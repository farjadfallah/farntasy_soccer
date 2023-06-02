#include "CommandProvider.hpp"
#include <vector>
#include <string>

using namespace std;

bool CommandProvider::get_command(vector<string>& words){
    string line = prepare_raw_line();
    words = parse_word_by_word(line);
    if(words.size() <= 0){
        return false;
    }
    return true;
}

string CommandProvider::prepare_raw_line(){
    string line;
    getline(cin, line);
    if(line.back()== '\r'){
        line.pop_back();
    }
    line += " ";
    return line;
}

vector<string> CommandProvider::parse_word_by_word(string line){
    vector<string> words;
    string tmp_word;
    for(int i=0; i < line.size(); i++){
        if(line[i] == '\n' || line[i] == ' '){
            if(tmp_word!=""){
                words.push_back(tmp_word);
            }
            tmp_word.clear();
        }else{
            tmp_word.push_back(line[i]);
        }
    }
    return words;
}



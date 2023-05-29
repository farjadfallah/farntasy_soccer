#include "FantasyTeam.hpp"
#include <string>

using namespace std;

FantasyTeam::FantasyTeam(string _username, string _password){
    username = _username;
    password = _password;
}

bool FantasyTeam::has_certain_password(std::string _password){
    if(_password == password ){
        return true;
    }
    return false;
}
bool FantasyTeam::has_certain_username(std::string _username){
    if(_username == username ){
        return true;
    }
    return false;
}
#include "Admin.hpp"
#include "Exceptions.hpp"
#include <string>

using namespace std;

Admin::Admin(string _username, string _password){
    username = _username;
    password = _password;
}

bool Admin::has_certain_username(string _username){
    return _username == username;
}
bool Admin::has_certain_password(string _password){
    return password == _password;
}
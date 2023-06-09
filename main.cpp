#include "FantasyFootball.hpp"
#include "ReadFileUtil.hpp"
#include <string>
#include <iostream>
#include "Exceptions.hpp"
#include "CommandProvider.hpp"
#include "CommandDelegator.hpp"
#include "MagicNumbers.hpp"
using namespace std;


int main(){
    FantasyFootball fantasy_football;
    CommandProvider command_provider;
    CommandDeligator command_deligator(&fantasy_football);

    fantasy_football.get_initial_data();
    fantasy_football.add_admin(DEFAULT_ADMIN_USER , DEFAULT_ADMIN_PASS);
    vector<string> words;
    while (command_provider.get_command(words)){
       command_deligator.handle_command(words);
    }

}

#include "FantasyFootball.hpp"
#include "ReadFileUtil.hpp"
#include <string>
#include <iostream>
#include "Exceptions.hpp"
#include "CommandProvider.hpp"
#include "CommandDelegator.hpp"

using namespace std;


int main(){
    FantasyFootball fantasy_football;
    CommandProvider command_provider;
    CommandDeligator command_deligator(&fantasy_football);

    
    fantasy_football.add_admin("admin" , "123456");
    fantasy_football.register_admin("admin" , "123456");
    fantasy_football.get_initial_data();
    // for(int i=0;i<19;i++){
    //     fantasy_football.pass_week();
    // }
    
    // fantasy_football.print();
    fantasy_football.open_transfer_window();
    fantasy_football.logout();
    fantasy_football.signup("farjad" , "Farjad83");
    fantasy_football.buy_player("D. Randolph");
    fantasy_football.buy_player("J. Manquillo");
    fantasy_football.buy_player("Tommi O'reilly");
    fantasy_football.buy_player("A. Semenyo");
    fantasy_football.buy_player("M. Senesi");
    fantasy_football.pass_week();
    fantasy_football.logout();
    for(int i=0; i<40; i++){
        vector<string> words = command_provider.get_command();
        command_deligator.handle_command(words);
    }
    fantasy_football.sell_player("J. Manquillo");
    fantasy_football.sell_player("M. Senesi");
    fantasy_football.buy_player("M. Senesi");
    fantasy_football.pass_week();
    fantasy_football.buy_player("J. Manquillo");
    fantasy_football.pass_week();
    fantasy_football.logout();
    fantasy_football.login("farjad" , "Farjad83");
    // fantasy_football.sell_player("Tommi O'reilly");
    // fantasy_football.sell_player("D. Sadi");
    // fantasy_football.matches_result_league(19);
    // fantasy_football.get_players_of_team("Arsenal FC", "fw", 1);
    // fantasy_football.team_of_the_week(1);

    // fantasy_football.signup("farjad" , "Farjad83");
    // fantasy_football.print_weeks_resutls();
    // fantasy_football.print_clubs_standings();

}

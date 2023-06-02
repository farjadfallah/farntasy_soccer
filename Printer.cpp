#include "Printer.hpp"
#include "Exceptions.hpp"
#include "Player.hpp"
#include <iostream>

using namespace std;

void Printer::print_team_of_the_week(vector<shared_ptr<Player> > players_list, int week){
    cout << "team of the week:" << endl;
    cout << "GoalKeeper: " << players_list[0]->team_of_the_week_output(week) << endl;
    cout << "Defender 1: " << players_list[1]->team_of_the_week_output(week) << endl;
    cout << "Defender 2: " << players_list[2]->team_of_the_week_output(week) << endl;
    cout << "Midfielder: " << players_list[3]->team_of_the_week_output(week) << endl;
    cout << "Forward: " << players_list[4]->team_of_the_week_output(week) << endl;
}

void Printer::print_matches_result_league(std::shared_ptr<WeekMatchResults> selected_week){
    for(int i=0; i<selected_week->size(); i++){
        cout << selected_week->return_game_summary(i) << endl;
    }
}
void Printer::print_fantasy_squad(std::string username, std::vector<std::shared_ptr<Player> >& goalkeepers,
                        std::vector<std::shared_ptr<Player> >& defenders, std::vector<std::shared_ptr<Player> >& midfielders,
                        std::vector<std::shared_ptr<Player> >& forwards){
    
    
    cout << "fantasy_team: " << username << endl;
    // cout << "Goalkeeper: " ;


}

void Printer::print_request_successful(){
    cout << SUCCESS_MESSAGE << endl;
}

void Printer::print_error(Exceptions& err){
    cout << err.error_message() << endl;
}
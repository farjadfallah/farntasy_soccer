#include "Printer.hpp"
#include "Exceptions.hpp"
#include "Player.hpp"
#include <iostream>
#include "SoccerClub.hpp"
#include "FantasyTeam.hpp"

using namespace std;

void Printer::print_team_of_the_week(const vector<shared_ptr<Player> >& players_list, int week){
    cout << "team of the week:" << endl;
    cout << "GoalKeeper: " << players_list[0]->team_of_the_week_output(week) << endl;
    cout << "Defender 1: " << players_list[1]->team_of_the_week_output(week) << endl;
    cout << "Defender 2: " << players_list[2]->team_of_the_week_output(week) << endl;
    cout << "Midfielder: " << players_list[3]->team_of_the_week_output(week) << endl;
    cout << "Forward: " << players_list[4]->team_of_the_week_output(week) << endl;
}

void Printer::print_players_of_team(const vector<shared_ptr<Player> >& players_list){
    cout << "list of players:" << endl;
    for(int i=0; i<players_list.size(); i++){
        cout << i+1 << ". " << players_list[i]->players_of_the_team_output() << endl;
    }
}

void Printer::print_clubs_standings(const vector<shared_ptr<SoccerClub> >& clubs_list){
    cout << "league standing:" << endl;
    for(int i=0; i<clubs_list.size(); i++){
        cout << i+1 << ". " << clubs_list[i]->league_standing_output() << endl;
    }
}

void Printer::print_user_ranking(const std::vector<std::shared_ptr<FantasyTeam> >& fantasy_teams_list){
    for(int i=0; i<fantasy_teams_list.size(); i++){
        cout << i+1 << ". " << fantasy_teams_list[i]->user_ranking_output() << endl;
    }
}





void Printer::print_matches_result_league(std::shared_ptr<WeekMatchResults> selected_week){
    for(int i=0; i<selected_week->size(); i++){
        cout << selected_week->match_result_league_output(i) << endl;
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



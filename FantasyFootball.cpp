#include "FantasyFootball.hpp"
#include "DataProvider.hpp"
#include "Positions.hpp"
#include <string>
#include <memory>
using namespace std;

const string INITIAL_FILEPATH = "./data/premier_league.csv";


void FantasyFootball::get_initial_data(){
    DataProvider data_provider(INITIAL_FILEPATH);
    string new_team_name;
    string player_name;
    while(data_provider.get_team_name_from_initial_file(new_team_name)){
        std::shared_ptr<SoccerClub> new_team = make_shared<SoccerClub>(new_team_name);
        teams_list.push_back(new_team);
        while(data_provider.get_Player_from_initiail_file(player_name)){
            new_team->add_player(make_shared<GoalKeeper>(player_name));
        }
        while(data_provider.get_Player_from_initiail_file(player_name)){
            new_team->add_player(make_shared<Defender>(player_name));
        }
        while(data_provider.get_Player_from_initiail_file(player_name)){
            new_team->add_player(make_shared<Midfeilder>(player_name));
        }
        while(data_provider.get_Player_from_initiail_file(player_name)){
            new_team->add_player(make_shared<Forward>(player_name));
        }
    }

}
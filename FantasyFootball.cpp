#include "FantasyFootball.hpp"
#include "DataProvider.hpp"
#include "Positions.hpp"
#include "SoccerClub.hpp"
#include <string>
#include <iostream>
#include <memory>
using namespace std;

const string INITIAL_FILEPATH = "./data/premier_league.csv";


void FantasyFootball::get_initial_data(){
    DataProvider data_provider(INITIAL_FILEPATH);
    data_provider.get_header();
    string new_team_name;
    while(data_provider.get_team_name_from_initial_file(new_team_name)){
        std::shared_ptr<SoccerClub> new_team = make_shared<SoccerClub>(new_team_name);
        teams_list.push_back(new_team);
        find_goalkeepers_from_initial_file(new_team, data_provider);
        find_defenders_from_initial_file(new_team, data_provider);
        find_midfielders_from_initial_file(new_team, data_provider);
        find_Forwards_from_initial_file(new_team, data_provider);
        new_team_name.clear();
    }
}

void FantasyFootball::print(){
    for(shared_ptr<SoccerClub> tmp : teams_list){
        tmp->print();
    }
}

void FantasyFootball::find_Forwards_from_initial_file(std::shared_ptr<SoccerClub> new_team, DataProvider& data_provider){
    bool state = true;
    string player_name;
    while(true){
        if(state == false){
            state = true;
            break;
        }
        player_name.clear();
        state = data_provider.get_Player_from_initiail_file(player_name);
        new_team->add_player(make_shared<Forward>(player_name));
    }
}

void FantasyFootball::find_midfielders_from_initial_file(std::shared_ptr<SoccerClub> new_team, DataProvider& data_provider){
    bool state = true;
    string player_name;
    while(true){
        if(state == false){
            state = true;
            break;
        }
        player_name.clear();
        state = data_provider.get_Player_from_initiail_file(player_name);
        new_team->add_player(make_shared<Midfielder>(player_name));
    }
}

void FantasyFootball::find_defenders_from_initial_file(std::shared_ptr<SoccerClub> new_team, DataProvider& data_provider){
    bool state = true;
    string player_name;
    while(true){
        if(state == false){
            state = true;
            break;
        }
        player_name.clear();
        state = data_provider.get_Player_from_initiail_file(player_name);
        new_team->add_player(make_shared<Defender>(player_name));
    }
}

void FantasyFootball::find_goalkeepers_from_initial_file(std::shared_ptr<SoccerClub> new_team, DataProvider& data_provider){
    bool state = true;
    string player_name;
    while(true){
        if(state == false){
            state = true;
            break;
        }
        player_name.clear();
        state = data_provider.get_Player_from_initiail_file(player_name);
        new_team->add_player(make_shared<GoalKeeper>(player_name));
    }
}
#include "SoccerClub.hpp"
#include <iostream>

using namespace std;

void SoccerClub::print(){
    cout << "|" << name << "| score: " << score << " GF: " << goals_for << " GA: " << goals_against << " GD: " << goals_difference << endl;
    // for(int i=0; i < players_in_team.size(); i++){
    //     players_in_team[i]->print();
    //     cout << "     and this is the above player position: " << players_in_team[i]->get_position() << endl;
    // }
    cout <<"--------------------"<<endl;
}

SoccerClub::SoccerClub(string _name){
    name = _name;
}

void SoccerClub::add_player(std::shared_ptr<Player> new_player){
    players_in_team.push_back(new_player);
}

bool SoccerClub::has_certain_name(string _name){
    if(name == _name){
        return true;
    }
    return false;
}

void SoccerClub::add_points(int points){
    score += points;
}
void SoccerClub::add_goals_for(int goals){
    goals_for += goals;
    goals_difference += goals;
}
void SoccerClub::add_goals_against(int goals){
    goals_against += goals;
    goals_difference -= goals;
}

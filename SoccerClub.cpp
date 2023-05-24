#include "SoccerClub.hpp"
#include <iostream>

using namespace std;

void SoccerClub::print(){
    cout << "this is the team: |" << name << "| and this is the score: " << score << " GF: " << goals_for << " GA: " << goals_against << " GD: " << goals_difference << endl;
    for(int i=0; i < players_in_team.size(); i++){
        players_in_team[i]->print();
        cout << "     and this is the above player position: " << players_in_team[i]->get_position() << endl;
    }
    cout <<"--------------------"<<endl;
}

SoccerClub::SoccerClub(string _name){
    name = _name;
}

void SoccerClub::add_player(std::shared_ptr<Player> new_player){
    players_in_team.push_back(new_player);
}

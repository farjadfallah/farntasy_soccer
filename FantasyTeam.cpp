#include "FantasyTeam.hpp"
#include <string>
#include <iostream>
#include "Exceptions.hpp"

using namespace std;

FantasyTeam::FantasyTeam(string _username, string _password){
    username = _username;
    password = _password;
}

bool FantasyTeam::has_certain_password(string _password){
    if(_password == password ){
        return true;
    }
    return false;
}

bool FantasyTeam::has_certain_username(string _username){
    if(_username == username ){
        return true;
    }
    return false;
}

void FantasyTeam::add_player(shared_ptr<Player> new_player){
    tmp_squad_players_list.push_back(new_player);
    players_bought_this_week ++;
}

void FantasyTeam::delete_player(shared_ptr<Player> new_player){
    if(!this->can_sell_player()){
        throw (PERMISSION_DENIED());
    }
    for(int i=0; i<tmp_squad_players_list.size(); i++){
        if(tmp_squad_players_list[i] == new_player){
            tmp_squad_players_list.erase(tmp_squad_players_list.begin() + i);
            players_sold_this_week ++;
            return;
        }
    } 
    throw(NOT_FOUND());
}

void FantasyTeam::print(){
    cout << "this is the team_name: |" << username << "|" << endl;
    cout << "and these are the players: " << endl;
    for(shared_ptr<Player> tmp : tmp_squad_players_list ){
        tmp->print();
    }
    cout << "---" << endl << endl;
}

bool FantasyTeam::can_sell_player(){
    if(players_sold_this_week >= 2 ){
        return false;
    }
    return true;
}
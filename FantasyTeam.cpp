#include "FantasyTeam.hpp"
#include <string>
#include <iostream>
#include "Exceptions.hpp"
#include "MagicNumbers.hpp"
#include <map>

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
    check_if_team_can_buy_player(new_player->get_position());
    tmp_squad_players_list.push_back(new_player);
    players_bought_this_week ++;
    if(tmp_squad_players_list.size() == 5){
        once_completed = true;
    }
}

void FantasyTeam::delete_player(shared_ptr<Player> new_player){
    check_if_team_can_sell_player();
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
    cout << "this is the team_name: |" << username << "| and this is the score:" << points << endl;
    cout << "and these are the players: " << endl;
    for(shared_ptr<Player> tmp : tmp_squad_players_list ){
        tmp->print();
    }
    cout << "---" << endl << endl;
}

void FantasyTeam::check_if_team_can_sell_player(){
    if(players_sold_this_week >= 2 ){
       throw(PERMISSION_DENIED());
    }
    return;
}

void FantasyTeam::check_if_team_can_buy_player(string post){
    if(players_bought_this_week >=1 && once_completed){
        throw(PERMISSION_DENIED());
    }
    if(players_num_in_position(post) >= MAX_POSITION_NUMBER.at(post)){
        cout << "max : " << MAX_POSITION_NUMBER.at(post) << " this: " << players_num_in_position(post) << endl;
        throw(BAD_REQUEST());
    }
}

int FantasyTeam::players_num_in_position(string position){
    int count =0;
    for(shared_ptr<Player> tmp : tmp_squad_players_list){
        if(tmp->get_position() == position){
            count ++;
        }
    }
    return count;
}

void FantasyTeam::pass_week(int new_week){
    players_list_each_week.push_back(tmp_squad_players_list);
    players_bought_this_week = 0;
    players_sold_this_week = 0;
    //should be done
    //calculate the new week score if team was valid(5 players)
    if(tmp_squad_players_list.size() >= 5){
        //add the new score to each_week_score_list
        points_each_week.push_back(calculate_total_score(new_week));
        //add the new score to the total score
        points += calculate_total_score(new_week);

    }else{
        //add 0 to new score each week score list
    }

}

double FantasyTeam::calculate_total_score(int week){
    double total_score =0;
    for(shared_ptr<Player> tmp: tmp_squad_players_list){
        total_score += tmp->get_score_at_week(week);
    }
    return total_score;
}
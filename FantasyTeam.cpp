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
    if(tmp_squad_players_list.size() >= 5){
        points_each_week.push_back(calculate_total_score(new_week));
        points += calculate_total_score(new_week);

    }else{
        points_each_week.push_back(0);
    }

}

double FantasyTeam::calculate_total_score(int week){
    double total_score =0;
    for(shared_ptr<Player> tmp: tmp_squad_players_list){
        total_score += tmp->get_score_at_week(week);
    }
    return total_score;
}

vector<shared_ptr<Player> >  FantasyTeam::squad(){
    if(players_list_each_week.size() <= 0){
        throw(EMPTY());
    }
    if (players_list_each_week[players_list_each_week.size()-1].size() != 5){
        throw(EMPTY());
    }
    return prepare_squad();
}


vector<shared_ptr<Player> > FantasyTeam::prepare_squad(){
    vector<shared_ptr<Player> > squad;
    squad.push_back(get_next_player_with_position(GOALKEEPER, squad));
    squad.push_back(get_next_player_with_position(DEFENDER, squad));
    squad.push_back(get_next_player_with_position(DEFENDER, squad));
    squad.push_back(get_next_player_with_position(MIDFIELDER, squad));
    squad.push_back(get_next_player_with_position(FORWARD, squad));
    return squad;
}

shared_ptr<Player> FantasyTeam::get_next_player_with_position(string post, vector<shared_ptr<Player> >& selected_previously){
    shared_ptr<Player> selected_player;
    for(shared_ptr<Player> tmp : players_list_each_week[players_list_each_week.size()-1]){
        if(tmp->get_position() != post){
            continue;
        }
        if(!tmp->is_better_alphabetically(selected_player)){
            continue;
        }
        bool is_duplicate = false;
        for(shared_ptr<Player> compared_to : selected_previously){
            if(tmp == compared_to){
                is_duplicate = true;
            }
        }
        if(is_duplicate){
            continue;
        }
        selected_player = tmp;
    }
    return selected_player;
}

bool FantasyTeam::is_better_than(shared_ptr<FantasyTeam> compared_to){
    if(this->points > compared_to->points){
        return true;
    }
    if(this->points == compared_to->points){
        if(this->username.compare(compared_to->username) < 0){
            return true;
        }
    }
    return false;
}

string FantasyTeam::user_ranking_output(){
    return "team_name: " + username + " | point: " + to_string(points);
}

string FantasyTeam::fantasy_squad_name_output(){
    return username;
}
string FantasyTeam::fantasy_squad_points_output(){
    return to_string(points);
}
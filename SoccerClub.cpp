#include "SoccerClub.hpp"
#include <iostream>
#include "Exceptions.hpp"

using namespace std;


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

bool SoccerClub::is_better_than(std::shared_ptr<SoccerClub> compared_to){
    if(this->score > compared_to->score){
        return true;
    }
    if(this->score == compared_to->score){
        if(this->goals_difference > compared_to->goals_difference){
            return true;
        }
        if(this->goals_difference == compared_to->goals_difference){
            if(this->goals_for > compared_to->goals_for){
                return true;
            }
        }
    }
    return false;
}

vector<shared_ptr<Player> > SoccerClub::print_players_of_team(std::string post, bool sorted){
    vector<shared_ptr<Player> > selected_list;
    for(shared_ptr<Player> tmp : players_in_team){
        if(tmp->get_position() == post || post == ALL_POSTS){
            selected_list.push_back(tmp);
        }
    }
    if(sorted == true){
        for(int i=0; i<selected_list.size(); i++){
            for(int j=i; j<selected_list.size(); j++){
                if(selected_list[i]->average_points() < selected_list[j]->average_points()){
                    shared_ptr<Player> tmp = selected_list[i];
                    selected_list[i] = selected_list[j];
                    selected_list[j] = tmp;
                }
            }
        }
    }
    return selected_list;
}


std::string SoccerClub::league_standing_output(){
    return name + ": score: " + to_string(score) + " | GF: " + to_string(goals_for) + " | GA: " + to_string(goals_against);
}

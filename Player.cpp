#include "Player.hpp"
#include <iostream>

using namespace std;

void Player::print(){
    cout << "     this is the player name: |" << full_name << "| post: |" << this->get_position() <<"| injured : " << injury << " yellowCards:" << yellow_card << " missed: "<< missed_next_match << endl;
    cout << "            these are the ratings:" << endl;
    for(int i=0; i < ratings_each_week.size(); i++){
        cout << "           week number " << i+1 << " : " << ratings_each_week[i] << endl;
    }
}

Player::Player(string _full_name){
    full_name = _full_name;
}

bool Player::has_certain_name(string name){
    if(name == full_name){
        return true;
    }
    return false;
}
void Player::injured(){
    injury = 3;
}

void Player::add_yellow_card(){
    yellow_card ++;
    if(yellow_card >= 3){
        missed_next_match = true;
        yellow_card = 0;
    }
}

void Player::add_red_Card(){
    missed_next_match = true;
}

void Player::add_new_point(){
    ratings_each_week.push_back(0);
}


void Player::edit_new_score(double new_score){
    ratings_each_week[ratings_each_week.size()-1] = new_score;
}

void Player::pass_one_week_of_injury(){
    if(injury >= 1){
        injury --;
    }
}


void Player::reset_misses_next_match_status(){
    missed_next_match = false;
}

double Player::get_score_at_week(int week){
    return ratings_each_week[week-1];
}

double Player::total_points(){
    double total_rating =0;
    for(double rating : ratings_each_week){
        total_rating += rating;
    }
    return total_rating;
}

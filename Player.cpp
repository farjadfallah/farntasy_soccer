#include "Player.hpp"
#include <iostream>

using namespace std;

void Player::print(){
    cout << "     this is the player name: |" << full_name << "| injured : " << injured << " yellowCards:" << yellow_card << "missed: "<< missed_next_match << endl;
    cout << "            these are the ratings:" << endl;
    for(int i=0; i < ratings_each_week.size(); i++){
        cout << "           week number " << i << " : " << ratings_each_week[i] << endl;
    }
}

Player::Player(string _full_name){
    full_name = _full_name;
}
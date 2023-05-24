#include "Positions.hpp"
#include <string>

using namespace std;

const std::string GOALKEEPER = "gk";
const std::string DEFENDER = "df";
const std::string MIDFIELDER = "md";
const std::string FORWARD = "fw";

std::string GoalKeeper::get_position(){
    return GOALKEEPER;
}
GoalKeeper::GoalKeeper(string _full_name):
    Player(_full_name){
}


std::string Defender::get_position(){
    return DEFENDER;
}
Defender::Defender(string _full_name):
    Player(_full_name){

}


std::string Midfielder::get_position(){
    return MIDFIELDER;
}
Midfielder::Midfielder(string _full_name):
    Player(_full_name){
}


std::string Forward::get_position(){
    return FORWARD;
}
Forward::Forward(string _full_name):
    Player(_full_name){
}
#include "Positions.hpp"
#include "MagicNumbers.hpp"
#include <string>
#include "Exceptions.hpp"

using namespace std;



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
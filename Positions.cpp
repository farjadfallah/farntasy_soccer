#include "Positions.hpp"

const std::string GOALKEEPER = "gk";
const std::string DEFENDER = "df";
const std::string MIDFEILDER = "md";
const std::string FORWARD = "fw";

std::string GoalKeeper::get_position(){
    return GOALKEEPER;
}

std::string Defender::get_position(){
    return DEFENDER;
}

std::string Midfeilder::get_position(){
    return MIDFEILDER;
}

std::string Forward::get_position(){
    return FORWARD;
}
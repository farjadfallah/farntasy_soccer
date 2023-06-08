#include "MatchResult.hpp"
#include "MagicNumbers.hpp"
#include <iostream>
#include <string>
#include "Exceptions.hpp"

using namespace std;



MatchResult::MatchResult(string _first_team, string _second_team, int _first_team_goals,int _second_team_goals){
    first_team_name = _first_team;
    second_team_name = _second_team;
    first_team_goals = _first_team_goals;
    second_team_goals = _second_team_goals;
}

std::string MatchResult::first_team(){
    return first_team_name;
}

std::string MatchResult::second_team(){
    return second_team_name;
}

int MatchResult::first_team_points(){
    if(first_team_goals > second_team_goals){
        return WON;
    }
    if(first_team_goals < second_team_goals){
        return LOST;
    }
    return DRAW;
}
int MatchResult::second_team_points(){
    if(first_team_goals > second_team_goals){
        return LOST;
    }
    if(first_team_goals < second_team_goals){
        return WON;
    }
    return DRAW;
}
int MatchResult::first_team_goals_for(){
    return first_team_goals;
}
int MatchResult::second_team_goals_for(){
    return second_team_goals;
}
int MatchResult::first_team_goals_against(){
    return second_team_goals;
}
int MatchResult::second_team_goals_against(){
    return first_team_goals;
}
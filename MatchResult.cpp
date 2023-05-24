#include "MatchResult.hpp"
#include <iostream>
#include <string>
using namespace std;

void MatchResult::print(){
    cout << first_team << " " << first_team_goals << " : " << second_team_goals << " " << second_team << endl;
}

MatchResult::MatchResult(string _first_team, string _second_team, int _first_team_goals,int _second_team_goals){
    first_team = _first_team;
    second_team = _second_team;
    first_team_goals = _first_team_goals;
    second_team_goals = _second_team_goals;
}

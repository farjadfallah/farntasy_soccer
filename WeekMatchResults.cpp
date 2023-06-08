#include "WeekMatchResults.hpp"
#include "Exceptions.hpp"
#include <memory>
#include <iostream>
using namespace std;


void WeekMatchResults::add_result(shared_ptr<MatchResult> new_match_result){
    results_list.push_back(new_match_result);
}



std::string WeekMatchResults::match_result_league_output(int number){
    string result ;
    result = results_list[number]->first_team() + " " + to_string(results_list[number]->first_team_goals_for());
    result = result + " | ";
    result = result + results_list[number]->second_team() + " " + to_string(results_list[number]->second_team_goals_for());
    return result;
}

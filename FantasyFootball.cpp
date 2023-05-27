#include "FantasyFootball.hpp"
#include "ReadFileUtil.hpp"
#include "Positions.hpp"
#include "SoccerClub.hpp"
#include "MatchResult.hpp"
#include "WeekMatchResults.hpp"
#include "FileReader.hpp"
#include <string>
#include <iostream>
#include <memory>

using namespace std;

const std::string GOALKEEPER = "gk";
const std::string DEFENDER = "df";
const std::string MIDFIELDER = "md";
const std::string FORWARD = "fw";


void FantasyFootball::get_initial_data(){
    file_reader.get_initial_data(teams_list, players_list);
}


void FantasyFootball::pass_week(){
    active_week ++;
    for(shared_ptr<Player> tmp : players_list){
        tmp->add_new_point();
        tmp->pass_one_week_of_injury();
        tmp->reset_misses_next_match_status();
    }
    file_reader.pass_week(active_week, weeks_results_list, teams_list, players_list);
}


shared_ptr<Player> FantasyFootball::find_player_by_name(string fullname){
    for(shared_ptr<Player> tmp : players_list){
        if(tmp->has_certain_name(fullname)){
            return tmp;
        }
    }
    return NULL;
}


shared_ptr<SoccerClub> FantasyFootball::find_soccer_club_by_name(string fullname){
    for(shared_ptr<SoccerClub> tmp : teams_list){
        if(tmp->has_certain_name(fullname)){
            return tmp;
        }
    }
    return NULL;
}


void FantasyFootball::print_weeks_resutls(){
    for(int i=0; i < weeks_results_list.size(); i++){
        cout <<"this is week number " << i+1 << ": " << endl;
        weeks_results_list[i]->print();
        cout << endl << endl;
    }
}

void FantasyFootball::print_players_resutls(){
    for(int i=0; i < players_list.size(); i++){
        players_list[i]->print();
        cout << endl << endl;
    }
}

void FantasyFootball::print_clubs_standings(){
    sort_soccer_clubs_list();
    for(shared_ptr<SoccerClub> tmp : teams_list){
        tmp->print();
    }
}

void FantasyFootball::print(){
    for(shared_ptr<SoccerClub> tmp : teams_list){
        tmp->print();
    }
}

void FantasyFootball::team_of_the_week(int week){
    if(week == THISWEEK){
        week = active_week;
    }
    vector<shared_ptr<Player> > selected_players;
    selected_players.push_back(find_best_player_at_position(week, GOALKEEPER));
    selected_players.push_back(find_best_player_at_position(week, DEFENDER));
    selected_players.push_back(find_best_player_at_position(week, DEFENDER,selected_players[1]));
    selected_players.push_back(find_best_player_at_position(week, MIDFIELDER));
    selected_players.push_back(find_best_player_at_position(week, FORWARD));
    //print the vector here
    for(shared_ptr<Player> tmp : selected_players){
        tmp->print();
    }
}

shared_ptr<Player> FantasyFootball::find_best_player_at_position(int week, string position, shared_ptr<Player> excluding){
    double highest_score;
    shared_ptr<Player> selected_player;
    for(shared_ptr<Player> tmp: players_list){
        if(tmp == excluding){
            continue;
        }
        if(tmp->get_position() != position){
            continue;
        }
        if(tmp->get_score_at_week(week) > highest_score){
            highest_score = tmp->get_score_at_week(week);
            selected_player = tmp;
        }
    }
    return selected_player;
}

void FantasyFootball::sort_soccer_clubs_list(){
    for(int i=0 ; i<teams_list.size(); i++){
        for (int j=i; j<teams_list.size(); j++){
            if(teams_list[j]->is_better_than(teams_list[i])){
                shared_ptr<SoccerClub> tmp = teams_list[i];
                teams_list[i] = teams_list[j];
                teams_list[j] = tmp;
            }
        }
    }
}

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
    for(shared_ptr<SoccerClub> tmp : teams_list){
        tmp->print();
    }
}

void FantasyFootball::print(){
    for(shared_ptr<SoccerClub> tmp : teams_list){
        tmp->print();
    }
}
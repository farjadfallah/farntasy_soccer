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

const string INITIAL_FILEPATH = "./data/premier_league.csv";
const string WEEKS_DATA_FILEPATH = "./data/weeks_stats/week_";
const string WEEKS_DATA_FILE_EXTENSION = ".csv";

void FantasyFootball::get_initial_data(){
    file_reader.get_initial_data(teams_list, players_list);
}

void FantasyFootball::print(){
    for(shared_ptr<SoccerClub> tmp : teams_list){
        tmp->print();
    }
}

void FantasyFootball::pass_week(){
    active_week ++;
    for(shared_ptr<Player> tmp : players_list){
        tmp->add_new_point();
        tmp->pass_one_week_of_injury();
        tmp->reset_misses_next_match_status();
    }
    string new_file_path = WEEKS_DATA_FILEPATH + to_string(active_week) + WEEKS_DATA_FILE_EXTENSION;
    ReadFileUtil read_file_util(new_file_path);
    read_file_util.get_header();
    shared_ptr<WeekMatchResults> tmp_week_results = make_shared<WeekMatchResults>();
    for(int i=0 ; i<10; i++){
        shared_ptr<MatchResult> tmp_game_result = get_result(read_file_util); 
        tmp_week_results->add_result(tmp_game_result);
        //add points to teams
        update_teams_stats(tmp_game_result);
        update_injured_players(read_file_util);
        update_players_yellow_card(read_file_util); 
        update_players_red_card(read_file_util);
        update_players_scores(read_file_util);
    }
    weeks_results_list.push_back(tmp_week_results);
    
}

shared_ptr<MatchResult>  FantasyFootball::get_result(ReadFileUtil& read_file_util){
    string first_team_str, second_team_str;
    int first_goal, second_goal;
    read_file_util.get_team_names_from_week_file(first_team_str, second_team_str);
    read_file_util.get_team_goals_from_week_file(first_goal, second_goal);
    shared_ptr<MatchResult> tmp_game_result = make_shared<MatchResult>(first_team_str, second_team_str, first_goal, second_goal);
    return tmp_game_result;
}

void FantasyFootball::update_teams_stats(shared_ptr<MatchResult> game){
    shared_ptr<SoccerClub> first_team = find_soccer_club_by_name(game->first_team());
    shared_ptr<SoccerClub> second_team = find_soccer_club_by_name(game->second_team());
    first_team->add_points(game->first_team_points());
    second_team->add_points(game->second_team_points());
    first_team->add_goals_for(game->first_team_goals_for());
    second_team->add_goals_for(game->second_team_goals_for());
    first_team->add_goals_against(game->first_team_goals_against());
    second_team->add_goals_against(game->second_team_goals_against());
}

void FantasyFootball::update_players_scores(ReadFileUtil& read_file_util){

    bool state = true;
    string data;
    while(true){
        if(state == false){
            state = true;
            break;
        }
        data.clear();
        state = read_file_util.get_Player_from_file(data);
        if(data !=""){
            string player_name, score_str;
            double score;
            int delimiter_location=0;
            for(int i=0; i<data.size(); i++){
                if(data[i] == ':'){
                    delimiter_location = i;
                }
            }
            player_name = data.substr(0, delimiter_location);
            score_str = data.substr(delimiter_location + 1, data.size());
            score = stod(score_str);
            find_player_by_name(player_name)->edit_new_score(score);
        }
    }
}


void FantasyFootball::update_injured_players(ReadFileUtil& read_file_util){
    vector<string> selected_players_list; 
    get_players_list(selected_players_list, read_file_util);
    for(string tmp : selected_players_list){
            find_player_by_name(tmp)->injured();
    } 
}

void FantasyFootball::update_players_yellow_card(ReadFileUtil& read_file_util){
    vector<string> selected_players_list; 
    get_players_list(selected_players_list, read_file_util);
    for(string tmp : selected_players_list){
            find_player_by_name(tmp)->add_yellow_card();
    }   
}

void FantasyFootball::update_players_red_card(ReadFileUtil& read_file_util){
    vector<string> selected_players_list; 
    get_players_list(selected_players_list, read_file_util);
    for(string tmp : selected_players_list){
            find_player_by_name(tmp)->add_red_Card();
    }
}

void FantasyFootball::get_players_list(vector<string>& selected_players_list, ReadFileUtil& read_file_util){
    bool state = true;
    string player_name;
    while(true){
        if(state == false){
            state = true;
            break;
        }
        player_name.clear();
        state = read_file_util.get_Player_from_file(player_name);
        if(player_name !=""){
           selected_players_list.push_back(player_name);
        }
    }
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
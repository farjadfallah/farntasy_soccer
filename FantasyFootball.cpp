#include "FantasyFootball.hpp"
#include "DataProvider.hpp"
#include "Positions.hpp"
#include "SoccerClub.hpp"
#include "MatchResult.hpp"
#include "WeekMatchResults.hpp"
#include <string>
#include <iostream>
#include <memory>

using namespace std;

const string INITIAL_FILEPATH = "./data/premier_league.csv";
const string WEEKS_DATA_FILEPATH = "./data/weeks_stats/week_";
const string WEEKS_DATA_FILE_EXTENSION = ".csv";

void FantasyFootball::get_initial_data(){
    DataProvider data_provider(INITIAL_FILEPATH);
    data_provider.get_header();
    string new_team_name;
    while(data_provider.get_team_name_from_initial_file(new_team_name)){
        std::shared_ptr<SoccerClub> new_team = make_shared<SoccerClub>(new_team_name);
        teams_list.push_back(new_team);
        find_goalkeepers_from_initial_file(new_team, data_provider);
        find_defenders_from_initial_file(new_team, data_provider);
        find_midfielders_from_initial_file(new_team, data_provider);
        find_Forwards_from_initial_file(new_team, data_provider);
        new_team_name.clear();
    }
}

void FantasyFootball::print(){
    for(shared_ptr<SoccerClub> tmp : teams_list){
        tmp->print();
    }
}

void FantasyFootball::find_Forwards_from_initial_file(std::shared_ptr<SoccerClub> new_team, DataProvider& data_provider){
    vector<string> selected_players_list; 
    get_players_list(selected_players_list, data_provider);
    for(string tmp : selected_players_list){
        shared_ptr<Player> new_player = make_shared<Forward>(tmp);
        new_team->add_player(new_player);
        players_list.push_back(new_player);
    }
}

void FantasyFootball::find_midfielders_from_initial_file(std::shared_ptr<SoccerClub> new_team, DataProvider& data_provider){
    vector<string> selected_players_list; 
    get_players_list(selected_players_list, data_provider);
    for(string tmp : selected_players_list){
        shared_ptr<Player> new_player = make_shared<Midfielder>(tmp);
        new_team->add_player(new_player);
        players_list.push_back(new_player);
    }

}

void FantasyFootball::find_defenders_from_initial_file(std::shared_ptr<SoccerClub> new_team, DataProvider& data_provider){
    vector<string> selected_players_list; 
    get_players_list(selected_players_list, data_provider);
    for(string tmp : selected_players_list){
        shared_ptr<Player> new_player = make_shared<Defender>(tmp);
        new_team->add_player(new_player);
        players_list.push_back(new_player);
    }
}

void FantasyFootball::find_goalkeepers_from_initial_file(std::shared_ptr<SoccerClub> new_team, DataProvider& data_provider){
    vector<string> selected_players_list; 
    get_players_list(selected_players_list, data_provider);
    for(string tmp : selected_players_list){
        shared_ptr<Player> new_player = make_shared<GoalKeeper>(tmp);
        new_team->add_player(new_player);
        players_list.push_back(new_player);
    }

}

void FantasyFootball::pass_week(){
    active_week ++;
    string new_file_path = WEEKS_DATA_FILEPATH + to_string(active_week) + WEEKS_DATA_FILE_EXTENSION;
    DataProvider data_provider(new_file_path);
    data_provider.get_header();
    for(shared_ptr<Player> tmp : players_list){
        tmp->add_new_point();
        tmp->pass_one_week_of_injury();
        tmp->reset_misses_next_match_status();
    }
    shared_ptr<WeekMatchResults> tmp_week_results = make_shared<WeekMatchResults>();
    for(int i=0 ; i<10; i++){
        shared_ptr<MatchResult> tmp_game_result = get_result(data_provider); 
        tmp_week_results->add_result(tmp_game_result);
        //add points to teams
        update_teams_stats(tmp_game_result);
        update_injured_players(data_provider);
        update_players_yellow_card(data_provider); 
        update_players_red_card(data_provider);
        update_players_scores(data_provider);
    }
    weeks_results_list.push_back(tmp_week_results);
    
}

shared_ptr<MatchResult>  FantasyFootball::get_result(DataProvider& data_provider){
    string first_team_str, second_team_str;
    int first_goal, second_goal;
    data_provider.get_team_names_from_week_file(first_team_str, second_team_str);
    data_provider.get_team_goals_from_week_file(first_goal, second_goal);
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

void FantasyFootball::update_players_scores(DataProvider& data_provider){

    bool state = true;
    string data;
    while(true){
        if(state == false){
            state = true;
            break;
        }
        data.clear();
        state = data_provider.get_Player_from_initiail_file(data);
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


void FantasyFootball::update_injured_players(DataProvider& data_provider){
    vector<string> selected_players_list; 
    get_players_list(selected_players_list, data_provider);
    for(string tmp : selected_players_list){
            find_player_by_name(tmp)->injured();
    } 
}

void FantasyFootball::update_players_yellow_card(DataProvider& data_provider){
    vector<string> selected_players_list; 
    get_players_list(selected_players_list, data_provider);
    for(string tmp : selected_players_list){
            find_player_by_name(tmp)->add_yellow_card();
    }   
}

void FantasyFootball::update_players_red_card(DataProvider& data_provider){
    vector<string> selected_players_list; 
    get_players_list(selected_players_list, data_provider);
    for(string tmp : selected_players_list){
            find_player_by_name(tmp)->add_red_Card();
    }
}

void FantasyFootball::get_players_list(vector<string>& selected_players_list, DataProvider& data_provider){
    bool state = true;
    string player_name;
    while(true){
        if(state == false){
            state = true;
            break;
        }
        player_name.clear();
        state = data_provider.get_Player_from_initiail_file(player_name);
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
#include "FileReader.hpp"
#include "ReadFileUtil.hpp"
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

void FileReader::get_initial_data(vector<shared_ptr<SoccerClub> >& teams_list, vector<shared_ptr<Player> >& players_list){
    ReadFileUtil read_file_util(INITIAL_FILEPATH);
    read_file_util.get_header();
    string new_team_name;
    while(read_file_util.get_team_name_from_initial_file(new_team_name)){
        std::shared_ptr<SoccerClub> new_team = make_shared<SoccerClub>(new_team_name);
        teams_list.push_back(new_team);
        find_goalkeepers_from_initial_file(new_team, read_file_util, players_list);
        find_defenders_from_initial_file(new_team, read_file_util, players_list);
        find_midfielders_from_initial_file(new_team, read_file_util, players_list);
        find_Forwards_from_initial_file(new_team, read_file_util, players_list);
        new_team_name.clear();
    }
}

void FileReader::find_goalkeepers_from_initial_file(std::shared_ptr<SoccerClub> new_team, ReadFileUtil& read_file_util,  vector<shared_ptr<Player> >& players_list){
    vector<string> selected_players_list; 
    get_players_list(selected_players_list, read_file_util);
    for(string tmp : selected_players_list){
        shared_ptr<Player> new_player = make_shared<GoalKeeper>(tmp);
        new_team->add_player(new_player);
        players_list.push_back(new_player);
    }

}

void FileReader::find_defenders_from_initial_file(std::shared_ptr<SoccerClub> new_team, ReadFileUtil& read_file_util,  vector<shared_ptr<Player> >& players_list){
    vector<string> selected_players_list; 
    get_players_list(selected_players_list, read_file_util);
    for(string tmp : selected_players_list){
        shared_ptr<Player> new_player = make_shared<Defender>(tmp);
        new_team->add_player(new_player);
        players_list.push_back(new_player);
    }

}

void FileReader::find_midfielders_from_initial_file(std::shared_ptr<SoccerClub> new_team, ReadFileUtil& read_file_util,  vector<shared_ptr<Player> >& players_list){
    vector<string> selected_players_list; 
    get_players_list(selected_players_list, read_file_util);
    for(string tmp : selected_players_list){
        shared_ptr<Player> new_player = make_shared<Midfielder>(tmp);
        new_team->add_player(new_player);
        players_list.push_back(new_player);
    }

}

void FileReader::find_Forwards_from_initial_file(std::shared_ptr<SoccerClub> new_team, ReadFileUtil& read_file_util,  vector<shared_ptr<Player> >& players_list){
    vector<string> selected_players_list; 
    get_players_list(selected_players_list, read_file_util);
    for(string tmp : selected_players_list){
        shared_ptr<Player> new_player = make_shared<Forward>(tmp);
        new_team->add_player(new_player);
        players_list.push_back(new_player);
    }

}

void FileReader::get_players_list(vector<string>& selected_players_list, ReadFileUtil& read_file_util){
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



// void FantasyFootball::pass_week(){
//     active_week ++;
//     for(shared_ptr<Player> tmp : players_list){
//         tmp->add_new_point();
//         tmp->pass_one_week_of_injury();
//         tmp->reset_misses_next_match_status();
//     }
//     string new_file_path = WEEKS_DATA_FILEPATH + to_string(active_week) + WEEKS_DATA_FILE_EXTENSION;
//     ReadFileUtil read_file_util(new_file_path);
//     read_file_util.get_header();
//     shared_ptr<WeekMatchResults> tmp_week_results = make_shared<WeekMatchResults>();
//     for(int i=0 ; i<10; i++){
//         shared_ptr<MatchResult> tmp_game_result = get_result(read_file_util); 
//         tmp_week_results->add_result(tmp_game_result);
//         //add points to teams
//         update_teams_stats(tmp_game_result);
//         update_injured_players(read_file_util);
//         update_players_yellow_card(read_file_util); 
//         update_players_red_card(read_file_util);
//         update_players_scores(read_file_util);
//     }
//     weeks_results_list.push_back(tmp_week_results);
    
// }
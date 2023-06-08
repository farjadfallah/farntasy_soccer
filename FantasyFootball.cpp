#include "FantasyFootball.hpp"
#include "ReadFileUtil.hpp"
#include "Positions.hpp"
#include "SoccerClub.hpp"
#include "MatchResult.hpp"
#include "WeekMatchResults.hpp"
#include "FileReader.hpp"
#include "MagicNumbers.hpp"
#include "Exceptions.hpp"
#include <string>
#include <iostream>
#include <memory>

using namespace std;

void FantasyFootball::get_initial_data()
{
    file_reader.get_initial_data(teams_list, players_list);
}

void FantasyFootball::pass_week()
{
    active_week++;
    for (shared_ptr<Player> tmp : players_list)
    {
        tmp->pass_week();
    }
    file_reader.pass_week(active_week, weeks_results_list, teams_list, players_list);
    for (shared_ptr<FantasyTeam> tmp : fantasy_teams_list)
    {
        tmp->pass_week(active_week);
    }
}

shared_ptr<Player> FantasyFootball::find_player_by_name(string fullname)
{
    for (shared_ptr<Player> tmp : players_list)
    {
        if (tmp->has_certain_name(fullname))
        {
            return tmp;
        }
    }
    return NULL;
}

shared_ptr<SoccerClub> FantasyFootball::find_soccer_club_by_name(string fullname)
{
    for (shared_ptr<SoccerClub> tmp : teams_list)
    {
        if (tmp->has_certain_name(fullname))
        {
            return tmp;
        }
    }
    return NULL;
}


void FantasyFootball::print_clubs_standings()
{
    sort_soccer_clubs_list();
    printer.print_clubs_standings(teams_list);
}



void FantasyFootball::team_of_the_week(int week)
{
    if (week == THISWEEK)
    {
        week = active_week;
    }
    vector<shared_ptr<Player>> selected_players;
    selected_players.push_back(find_best_player_at_position(week, GOALKEEPER));
    selected_players.push_back(find_best_player_at_position(week, DEFENDER));
    selected_players.push_back(find_best_player_at_position(week, DEFENDER, selected_players[1]));
    selected_players.push_back(find_best_player_at_position(week, MIDFIELDER));
    selected_players.push_back(find_best_player_at_position(week, FORWARD));

    printer.print_team_of_the_week(selected_players, week);

}

shared_ptr<Player> FantasyFootball::find_best_player_at_position(int week, string position, shared_ptr<Player> excluding)
{
    shared_ptr<Player> selected_player;
    for (shared_ptr<Player> tmp : players_list)
    {
        if (tmp == excluding)
        {
            continue;
        }
        if (tmp->get_position() != position)
        {
            continue;
        }
        if(tmp->is_better_than_in_week(selected_player, week)){
            selected_player = tmp;
        }
    }
    return selected_player;
}

void FantasyFootball::sort_soccer_clubs_list()
{
    for (int i = 0; i < teams_list.size(); i++)
    {
        for (int j = i; j < teams_list.size(); j++)
        {
            if (teams_list[j]->is_better_than(teams_list[i]))
            {
                shared_ptr<SoccerClub> tmp = teams_list[i];
                teams_list[i] = teams_list[j];
                teams_list[j] = tmp;
            }
        }
    }
}

void FantasyFootball::get_players_of_team(std::string team_name, string post, bool sorted)
{
    shared_ptr<SoccerClub> selected_team = find_soccer_club_by_name(team_name);
    if(selected_team == NULL){
        throw(NOT_FOUND());
    }
    check_if_post_is_valid(post);
    vector<shared_ptr<Player> > selected_players = selected_team->print_players_of_team(post, sorted);
    printer.print_players_of_team(selected_players);
}

void FantasyFootball::matches_result_league(int week_num)
{
    shared_ptr<WeekMatchResults> selected_week;
    if (week_num != NO_WEEK_SELECTED_FOR_WEEK_RESULT)
    {
        if(weeks_results_list.size() <= week_num-1){
            throw(BAD_REQUEST());
        }
        selected_week = weeks_results_list[week_num-1];
    }
    else
    {
        selected_week = weeks_results_list.back();
    }
    printer.print_matches_result_league(selected_week);
}

void FantasyFootball::signup(string username, string password)
{
    if(active_fantasy_team_user != NULL || active_admin_user != NULL){
        throw(BAD_REQUEST());
    }
    if(find_fantasy_team_with_username(username) != NULL){
        throw(BAD_REQUEST());
    }
    fantasy_teams_list.push_back(make_shared<FantasyTeam>(username, password));
    active_fantasy_team_user = fantasy_teams_list[fantasy_teams_list.size() -1];
}

void FantasyFootball::login(string username, string password)
{
    if(active_fantasy_team_user != NULL || active_admin_user != NULL){
        throw(BAD_REQUEST());
    }
    shared_ptr<FantasyTeam> selected_team = find_fantasy_team_with_username(username);
    if(selected_team == NULL){
        throw(NOT_FOUND());
    }
    if (selected_team->has_certain_password(password))
    {
        active_fantasy_team_user = selected_team;
    }else{
        throw(PERMISSION_DENIED());
    }
}

void FantasyFootball::logout(){
    active_fantasy_team_user = NULL;
    active_admin_user = NULL;
}

void FantasyFootball::register_admin(string username, string password)
{
    shared_ptr<Admin> selected_Admin = find_admin_with_username(username);
    if(selected_Admin == NULL){
        throw(BAD_REQUEST());
    }
    if (selected_Admin->has_certain_password(password))
    {
        active_admin_user = selected_Admin;
    }else{
        throw(BAD_REQUEST());
    }
}

shared_ptr<FantasyTeam> FantasyFootball::find_fantasy_team_with_username(string username)
{
    for (shared_ptr<FantasyTeam> tmp : fantasy_teams_list)
    {
        if (tmp->has_certain_username(username))
        {
            return tmp;
        }
    }
    return NULL;
}

shared_ptr<Admin> FantasyFootball::find_admin_with_username(string username)
{
    for (shared_ptr<Admin> tmp : admin_list)
    {
        if (tmp->has_certain_username(username))
        {
            return tmp;
        }
    }
    return NULL;
}

void FantasyFootball::open_transfer_window(){
    transfer_window_open = true;
}

void FantasyFootball::close_transfer_window(){
    transfer_window_open = true;
}

void FantasyFootball::buy_player(std::string player_name){
    if(active_fantasy_team_user==NULL){
        throw (BAD_REQUEST());
    }
    if(!transfer_window_open){
        throw(PERMISSION_DENIED());
    }
    shared_ptr<Player> new_player = find_player_by_name(player_name);
    if(new_player == NULL){
        throw(NOT_FOUND());
    }
    if(!new_player->can_play_next_week()){
        throw(PLAYER_NOT_AVAILABLE_THIS_WEEK());
    }
    active_fantasy_team_user->add_player(new_player);
}

void FantasyFootball::sell_player(std::string player_name){
    if(active_fantasy_team_user==NULL){
        throw (BAD_REQUEST());
    }
    if(!transfer_window_open){
        throw(PERMISSION_DENIED());
    }
    shared_ptr<Player> new_player = find_player_by_name(player_name);
    active_fantasy_team_user->delete_player(new_player);
}

void FantasyFootball::check_if_post_is_valid(string post){
    if(post != FORWARD && post!=MIDFIELDER && post != DEFENDER && post != GOALKEEPER && post != ALL_POSTS){
        throw(BAD_REQUEST());
    }
}

void FantasyFootball::add_admin(string username, string password){
    admin_list.push_back(make_shared<Admin>(username, password));
}

void FantasyFootball::squad(std::string team_name ){
    shared_ptr<FantasyTeam> selected_team;
    if(team_name != NO_TEAM_SELECTED){
        selected_team = find_fantasy_team_with_username(team_name);
    } else if(active_fantasy_team_user!=NULL){
        selected_team = active_fantasy_team_user;
    }else{
        throw(BAD_REQUEST());
    }    
    if(selected_team == NULL){
        throw(NOT_FOUND());
    }
    vector<shared_ptr<Player> > squad = selected_team->squad();
    printer.print_fantasy_squad(selected_team, squad);
}

void FantasyFootball::users_ranking(){
    sort_fantasy_teams();
    printer.print_user_ranking(fantasy_teams_list);
}

void FantasyFootball::sort_fantasy_teams()
{
    for (int i = 0; i < fantasy_teams_list.size(); i++)
    {
        for (int j = i; j < fantasy_teams_list.size(); j++)
        {
            if (fantasy_teams_list[j]->is_better_than(fantasy_teams_list[i]))
            {
                shared_ptr<FantasyTeam> tmp = fantasy_teams_list[i];
                fantasy_teams_list[i] = fantasy_teams_list[j];
                fantasy_teams_list[j] = tmp;
            }
        }
    }
}

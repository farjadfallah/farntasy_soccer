#include "CommandDelegator.hpp"
#include <vector>
#include <string>
#include "FantasyFootball.hpp"
#include "Exceptions.hpp"
#include <iostream>

using namespace std;

CommandDeligator::CommandDeligator(FantasyFootball* _fantasy_football){
    fantasy_football = _fantasy_football;
}

void CommandDeligator::handle_command(vector<string>& _words){
    words = _words;
    switch (this->command_type())
    {
    case POST:
        this->handle_POST_command(this->get_POST_command_number());
        break;
    case GET:
        this->handle_GET_command(this->get_GET_command_number());
        break;
    default:
        break;
    }
}

void CommandDeligator::handle_GET_command(int command_number){
    switch (command_number)
    {
    case TEAM_OF_THE_WEEK:
        this->team_of_the_week();
        break;
    case PLAYERS:
        this->players();
        break;
    case LEAGUE_STANDINGS:
        this->league_standings();
        break;
    case USER_RANKING:
        this->users_ranking();
        break;
    case MATHCES_RESULT_LEAGUE: {
        this->matches_result_league();
        break;
    }
    case SQUAD:
        this->squad();
        break;
    default:
        break;
    }
}

void CommandDeligator::handle_POST_command(int command_number){
    switch (command_number)
    {
    case SIGNUP:
        this->signup();
        break;
    case LOGIN:
        this->login();
        break;
    case REGISTE_ADMIN:

        break;
    case LOGOUT:
        this->logout();
        break;
    case SELL_PLAYER:

        break;
    case BUY_PLAYER:

        break;
    case CLOSE_TRANSFER_WINDOW:
    
        break;
    case OPEN_TRANSFER_WINDOW:

        break;
    case PASS_WEEK:
    
        break;
    default:
        break;
    }
}


int CommandDeligator::command_type(){
    for(int i=0; i < COMMAND_TYPES_LIST.size(); i++){
        if(COMMAND_TYPES_LIST[i] == words[COMMAND_TYPE_POSITION]){
            return i;
        }
    }
    throw(BAD_REQUEST());
}

int CommandDeligator::get_GET_command_number(){
    for(int i=0; i < GET_COMMANDS_LIST.size(); i++){
        if(GET_COMMANDS_LIST[i] == words[COMMAND_NAME_POSITION]){
            return i;
        }
    }
    throw(BAD_REQUEST());
}

int CommandDeligator::get_POST_command_number(){
    for(int i=0; i < POST_COMMANDS_LIST.size(); i++){
        if(POST_COMMANDS_LIST[i] == words[COMMAND_NAME_POSITION]){
            return i;
        }
    }
    throw(BAD_REQUEST());
}

int CommandDeligator::get_field_int(string field_name){
    int result = -1;
    for(int i=0; i<words.size(); i++){
        if(words[i] == field_name){
            result = stoi(words[i+1]);
            break;
        }
    }
    return result;
}

string CommandDeligator::get_field_string(string field_name){
    string result = "";
    for(int i=0; i<words.size(); i++){
        if(words[i] == field_name){
            result = words[i+1];
            break;
        }
    }
    return result;
}

bool CommandDeligator::has_certain_feild(string field_name){
    for(int i=0; i<words.size(); i++){
        if(words[i] == field_name){
            return true;
        }
    }
    return false;
}

string CommandDeligator::has_wich_field(vector<string> field_options){
    for(int j=0; j< field_options.size(); j++){
        for(int i=0; i<words.size(); i++){
            if(words[i] == field_options[j]){
                return field_options[j];
            }
        }
    }
    return "";
}


void CommandDeligator::team_of_the_week(){
    cout << "this is from team of the week" << endl;
    int week_num = get_field_int(WEEK_NUMBER_FIELD);
    fantasy_football->team_of_the_week(week_num);
}

void CommandDeligator::players(){
    cout << "this is from players" << endl;
    string team_name = get_field_string(TEAM_NAME_FIELD);
    for(int i=0; i<team_name.size(); i++){
        if(team_name[i] == '_'){
            team_name[i] = ' ';
        }
    }
    bool sorted = has_certain_feild(RANKED_FIELD);
    string post = has_wich_field(POSITIONS_LIST);
    fantasy_football->get_players_of_team(team_name, post, sorted);
}

void CommandDeligator::league_standings(){
    cout << "this is from league_standings" << endl;
    fantasy_football->print_clubs_standings();
}

void CommandDeligator::users_ranking(){
    cout << "this is from users_ranking" << endl;
    fantasy_football->users_ranking();
}

void CommandDeligator::matches_result_league(){
    cout << "this is from matches_result_league" << endl;
    int week_num = get_field_int(WEEK_NUMBER_FIELD);
    fantasy_football->matches_result_league(week_num);
}

void CommandDeligator::squad(){
    cout << "this is from squad" << endl;
    string team_name = get_field_string(FANTASY_TEAM_FIELD);
    fantasy_football->squad(team_name);
}

void CommandDeligator::signup(){
    cout << "this is from the signtp" << endl;
    string username = get_field_string(TEAM_NAME_FIELD);
    string password = get_field_string(PASSWORD_FEILD);
    fantasy_football->signup(username, password);
}

void CommandDeligator::login(){
    cout << "this is from the login" << endl;
    string username = get_field_string(TEAM_NAME_FIELD);
    string password = get_field_string(PASSWORD_FEILD);
    fantasy_football->login(username, password);
}

void CommandDeligator::logout(){
    cout << "this is from the logout" << endl;
    fantasy_football->logout();
}

void CommandDeligator::register_admin(){
    cout << "this is from register admin" << endl;
    string username = get_field_string(USERNAME_FEILD);
    string password = get_field_string(PASSWORD_FEILD);
    fantasy_football->register_admin(username, password);
}

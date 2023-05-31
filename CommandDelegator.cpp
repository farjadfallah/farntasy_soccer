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

        break;
    case PLAYERS:

        break;
    case LEAGUE_STANDINGS:

        break;
    case USER_RANKING:
    
        break;
    case MATHCES_RESULT_LEAGUE:

        break;
    case SQUAD:
    
        break;
    default:
        break;
    }
}

void CommandDeligator::handle_POST_command(int command_number){
    switch (command_number)
    {
    case SIGNUP:

        break;
    case LOGIN:

        break;
    case REGISTE_ADMIN:

        break;
    case LOGOUT:

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
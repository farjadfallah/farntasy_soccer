#ifndef __MAGIC__NUMBERS__
#define __MAGIC__NUMBERS__
#include <map>
#include <string>
#include <vector>
const std::string GOALKEEPER = "gk";
const std::string DEFENDER = "df";
const std::string MIDFIELDER = "md";
const std::string FORWARD = "fw";

const std::vector<std::string> POSITIONS_LIST = {"gk", "df", "md", "fw" };

const int THISWEEK = -1;
const std::string ALL_POSTS = "";

const std::map<std::string, int> MAX_POSITION_NUMBER { { GOALKEEPER, 1}, { DEFENDER, 2 }, {MIDFIELDER , 1}, {FORWARD, 1} };


const std::string INITIAL_FILEPATH = "./data/premier_league.csv";
const std::string WEEKS_DATA_FILEPATH = "./data/weeks_stats/week_";
const std::string WEEKS_DATA_FILE_EXTENSION = ".csv";

const int WON = 3;
const int LOST = 0;
const int DRAW =1;

const int NO_WEEK_SELECTED_FOR_WEEK_RESULT = -1;

const std::string NO_TEAM_SELECTED = "";

const int NOT_INJURED =0;

//commands list
const std::vector<std::string>  COMMAND_TYPES_LIST = { "POST", "GET", "PUT", "DELETE"};

const std::vector<std::string>GET_COMMANDS_LIST = { "team_of_the_week", "players", "league_standings", "users_ranking", "matches_result_league", "squad"};

const std::vector<std::string> POST_COMMANDS_LIST = {"signup", "login", "register_admin", "logout", "sell_player", "buy_player", "close_transfer_window", 
                            "open_transfer_window", "pass_week"};

enum {
    POST,
    GET,
    PUT,
    DELETE
};

enum {
    SIGNUP,
    LOGIN,
    REGISTE_ADMIN,
    LOGOUT,
    SELL_PLAYER,
    BUY_PLAYER,
    CLOSE_TRANSFER_WINDOW,
    OPEN_TRANSFER_WINDOW,
    PASS_WEEK
};

enum {
    TEAM_OF_THE_WEEK,
    PLAYERS,
    LEAGUE_STANDINGS,
    USER_RANKING,
    MATHCES_RESULT_LEAGUE,
    SQUAD
};

//headers position
const int COMMAND_TYPE_POSITION = 0;
const int COMMAND_NAME_POSITION = 1;


//feilds name
const std::string WEEK_NUMBER_FIELD = "week_num";
const std::string TEAM_NAME_FIELD = "team_name";
const std::string RANKED_FIELD = "ranks";
const std::string FANTASY_TEAM_FIELD = "fantasy_team";
const std::string PASSWORD_FEILD = "password";
const std::string USERNAME_FEILD = "username";
const std::string PLAYER_NAME_FEILD = "name";


//messages
const std::string SUCCESS_MESSAGE = "OK";
#endif
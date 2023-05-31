#ifndef __MAGIC__NUMBERS__
#define __MAGIC__NUMBERS__
#include <map>
#include <string>
const std::string GOALKEEPER = "gk";
const std::string DEFENDER = "df";
const std::string MIDFIELDER = "md";
const std::string FORWARD = "fw";


const int THISWEEK = -1;
const std::string ALL_POSTS = "ALL";

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
#endif
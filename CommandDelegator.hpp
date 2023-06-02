#include <vector>
#include <string>
#include "FantasyFootball.hpp"

class CommandDeligator {
    public:
        CommandDeligator(FantasyFootball* _fantasy_football);
        void handle_command(std::vector<std::string>& words);


        void team_of_the_week();
        void players();
        void league_standings();
        void users_ranking();
        void matches_result_league();
        void squad();

        void signup();
        void login();
        void logout();
    private:
        FantasyFootball* fantasy_football;
        std::vector<std::string> words;
        
        int command_type();
        int get_GET_command_number();
        int get_POST_command_number();
        void handle_GET_command(int command_number);
        void handle_POST_command(int command_number);
        int get_field_int(std::string field_name);
        std::string get_field_string(std::string field_name);
        bool has_certain_feild(std::string feild_name);
        std::string has_wich_field(std::vector<std::string> field_options);
};

// const std::vector<std::string>GET_COMMANDS_LIST = { "team_of_the_week", "players", "league_standings", "users_ranking", "matches_result_league", "squad"};

// const std::vector<std::string> POST_COMMANDS_LIST = {"signup", "login", "register_admin", "logout", "sell_player", "buy_player", "close_transfer_window", 
//                             "open_transfer_window", "pass_week"};
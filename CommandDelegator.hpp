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
        void register_admin();
        void logout();
        void buy_player();
        void sell_player();
        void open_transfer_window();
        void close_transfer_window();
        void pass_week();
    private:
        FantasyFootball* fantasy_football;
        std::vector<std::string> words;
        Printer printer;
        int command_type();
        int get_GET_command_number();
        int get_POST_command_number();
        void handle_GET_command(int command_number);
        void handle_POST_command(int command_number);
        int get_field_int(std::string field_name);
        std::string get_field_string(std::string field_name);
        bool has_certain_feild(std::string feild_name);
        std::string has_which_field(std::vector<std::string> field_options);
        std::string get_player_name(std::vector<std::string> field_options);

};


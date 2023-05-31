#include <vector>
#include <string>
#include "FantasyFootball.hpp"

class CommandDeligator {
    public:
        CommandDeligator(FantasyFootball* _fantasy_football);
        void handle_command(std::vector<std::string>& words);
    private:
        FantasyFootball* fantasy_football;
        std::vector<std::string> words;
        
        int command_type();
        int get_GET_command_number();
        int get_POST_command_number();
        void handle_GET_command(int command_number);
        void handle_POST_command(int command_number);
};
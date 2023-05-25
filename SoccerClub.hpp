#ifndef __SOCCER_CLUB__
#define __SOCCER_CLUB__
#include <vector>
#include <string>
#include <memory>
#include "Player.hpp"

class SoccerClub {
    public:
        void print();
        void add_player(std::shared_ptr<Player> new_player);
        SoccerClub(std::string _name);
        bool has_certain_name(std::string name);
        void add_points(int points);
        void add_goals_for(int goals);
        void add_goals_against(int goals);
    private:
        std::string name;
        std::vector<std::shared_ptr<Player> > players_in_team;
        int score = 0;
        int goals_for = 0;
        int goals_against = 0;
        int goals_difference = 0;
};  
#endif
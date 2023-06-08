#ifndef __SOCCER_CLUB__
#define __SOCCER_CLUB__
#include <vector>
#include <string>
#include <memory>
#include "Player.hpp"
#include "MagicNumbers.hpp"



class SoccerClub {
    public:
        void add_player(std::shared_ptr<Player> new_player);
        SoccerClub(std::string _name);
        bool has_certain_name(std::string name);
        void add_points(int points);
        void add_goals_for(int goals);
        void add_goals_against(int goals);
        bool is_better_than(std::shared_ptr<SoccerClub> compared_to);
        
        std::string league_standing_output();
        std::vector<std::shared_ptr<Player> >  print_players_of_team(std::string post, bool sorted);
    private:
        std::string name;
        std::vector<std::shared_ptr<Player> > players_in_team;
        int score = 0;
        int goals_for = 0;
        int goals_against = 0;
        int goals_difference = 0;
};  
#endif
#include <vector>
#include <string>
#include <memory>
#include "Player.hpp"

class SoccerClub {
    public:
        void print();
        void add_player(std::shared_ptr<Player>);
        SoccerClub(std::string _name);
    private:
        std::string name;
        std::vector<std::shared_ptr<Player> > players_in_team;
        int score = 0;
        int goals_for = 0;
        int goals_against = 0;
        int goals_difference = 0;
};  
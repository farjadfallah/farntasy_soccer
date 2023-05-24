#ifndef __FANTASY__FOOTBALL__
#define __FANTASY__FOOTBALL__
#include <vector>
#include <string>
#include <memory>
#include "Player.hpp"
#include "SoccerClub.hpp"

class FantasyFootball{
    public:
        void get_initial_data();
        void print();
    private:
        std::vector<std::shared_ptr<Player> > players_list;
        std::vector<std::shared_ptr<SoccerClub> > teams_list;
};
#endif
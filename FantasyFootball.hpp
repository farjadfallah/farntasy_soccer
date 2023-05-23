#include <vector>
#include <string>
#include <memory>
#include "Player.hpp"
#include "SoccerClub.hpp"

class FantasyFootball{
    public:
        void get_initial_data();
    private:
        std::vector<std::shared_ptr<Player> > players_list;
        std::vector<std::shared_ptr<SoccerClub> > teams_list;
};
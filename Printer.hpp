#ifndef __PRINTER__
#define __PRINTER__
#include "WeekMatchResults.hpp"
#include "Player.hpp"
#include "Exceptions.hpp"
#include <memory>
#include <vector>
#include <string>

class Printer{
    public:
        void print_team_of_the_week(std::vector<std::shared_ptr<Player> >, int week);
        void print_players_of_team(std::vector<std::shared_ptr<Player> > players_list);

        
        void print_matches_result_league(std::shared_ptr<WeekMatchResults> selected_week);
        void print_fantasy_squad(std::string username, std::vector<std::shared_ptr<Player> >& goalkeepers,
                std::vector<std::shared_ptr<Player> >& defenders, std::vector<std::shared_ptr<Player> >& midfielders,
                std::vector<std::shared_ptr<Player> >& forwards);
        void print_request_successful();
        void print_error(Exceptions& err);
    private:

};
#endif
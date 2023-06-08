#ifndef __PRINTER__
#define __PRINTER__
#include "WeekMatchResults.hpp"
#include "Player.hpp"
#include "Exceptions.hpp"
#include "SoccerClub.hpp"
#include "FantasyTeam.hpp"
#include <memory>
#include <vector>
#include <string>

class Printer{
    public:
        void print_team_of_the_week(const std::vector<std::shared_ptr<Player> >& players_list, int week);
        void print_players_of_team(const std::vector<std::shared_ptr<Player> >& players_list);
        void print_clubs_standings(const std::vector<std::shared_ptr<SoccerClub> >& clubs_list);
        void print_user_ranking(const std::vector<std::shared_ptr<FantasyTeam> >& fantasy_teams_list);

        void print_matches_result_league(std::shared_ptr<WeekMatchResults> selected_week);
        void print_fantasy_squad(std::shared_ptr<FantasyTeam> selected_team, std::vector<std::shared_ptr<Player> >& squad);
        void print_request_successful();
        void print_error(Exceptions& err);
    private:

};
#endif
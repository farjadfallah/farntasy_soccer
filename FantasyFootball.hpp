#ifndef __FANTASY__FOOTBALL__
#define __FANTASY__FOOTBALL__
#include <vector>
#include <string>
#include <memory>
#include "Player.hpp"
#include "SoccerClub.hpp"
#include "DataProvider.hpp"
#include "WeekMatchResults.hpp"
class FantasyFootball{
    public:
        void get_initial_data();
        void print();
        void pass_week();
        void print_weeks_resutls();
        void print_players_resutls();

    private:
        std::vector<std::shared_ptr<Player> > players_list;
        std::vector<std::shared_ptr<SoccerClub> > teams_list;
        std::vector<std::shared_ptr<WeekMatchResults> > weeks_results_list;
        
        int active_week = 0;

        
        
        
        void find_Forwards_from_initial_file(std::shared_ptr<SoccerClub> new_team, DataProvider& data_provider);
        void find_goalkeepers_from_initial_file(std::shared_ptr<SoccerClub> new_team, DataProvider& data_provider);
        void find_defenders_from_initial_file(std::shared_ptr<SoccerClub> new_team, DataProvider& data_provider);
        void find_midfielders_from_initial_file(std::shared_ptr<SoccerClub> new_team, DataProvider& data_provider);
        std::shared_ptr<Player> find_player_by_name(std::string fullname);
        void update_injured_players(DataProvider& data_provider);
        void update_players_yellow_card(DataProvider& data_provider);
        void update_players_red_card(DataProvider& data_provider);
        void update_players_scores(DataProvider& data_provider);


};
#endif
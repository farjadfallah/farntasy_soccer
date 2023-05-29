#ifndef __FANTASY__FOOTBALL__
#define __FANTASY__FOOTBALL__
#include <vector>
#include <string>
#include <memory>
#include "Player.hpp"
#include "SoccerClub.hpp"
#include "ReadFileUtil.hpp"
#include "WeekMatchResults.hpp"
#include "MatchResult.hpp"
#include "FileReader.hpp"
#include "MagicNumbers.hpp"
#include "Printer.hpp"
#include "FantasyTeam.hpp"
#include"Admin.hpp"

class FantasyFootball{
    public:
        void get_initial_data();
        void print();
        void print_weeks_resutls();
        void print_players_resutls();
        
        void pass_week();
        
        void team_of_the_week(int week = THISWEEK);
        void print_clubs_standings();
        void get_players_of_team(std::string team_name, std::string post = ALL_POSTS, int sorted = 0);
        void matches_result_league(int week_num = NO_WEEK_SELECTED_FOR_WEEK_RESULT);

        void signup(std::string _username, std::string password);
        void login(std::string username, std::string password);
        void register_admin(std::string _username, std::string password);
        void logout();
    private:
        std::vector<std::shared_ptr<Player> > players_list;
        std::vector<std::shared_ptr<SoccerClub> > teams_list;
        std::vector<std::shared_ptr<WeekMatchResults> > weeks_results_list;
        std::vector<std::shared_ptr<FantasyTeam> > fantasy_teams_list;
        std::vector<std::shared_ptr<Admin> > admin_list;
        std::shared_ptr<FantasyTeam> active_fantasy_team_user = NULL;
        std::shared_ptr<Admin> active_admin_user = NULL;
        FileReader file_reader;
        int active_week = 0;
        Printer printer;

        std::shared_ptr<SoccerClub> find_soccer_club_by_name(std::string fullname);
        std::shared_ptr<Player> find_player_by_name(std::string fullname);
        std::shared_ptr<Player> find_best_player_at_position(int week, std::string position, std::shared_ptr<Player> excluding = NULL);
        std::shared_ptr<FantasyTeam> find_fantasy_team_with_username(std::string username);
        std::shared_ptr<Admin> find_admin_with_username(std::string username);

        void sort_soccer_clubs_list();
};
#endif
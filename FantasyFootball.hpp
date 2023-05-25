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

class FantasyFootball{
    public:
        void get_initial_data();
        void print();
        void pass_week();
        void print_weeks_resutls();
        void print_players_resutls();
        void print_clubs_standings();
    private:
        std::vector<std::shared_ptr<Player> > players_list;
        std::vector<std::shared_ptr<SoccerClub> > teams_list;
        std::vector<std::shared_ptr<WeekMatchResults> > weeks_results_list;
        FileReader file_reader;
        int active_week = 0;


        std::shared_ptr<MatchResult> get_result(ReadFileUtil& read_file_util);
        void get_players_list(std::vector<std::string>& selected_players_list, ReadFileUtil& read_file_util);        
        std::shared_ptr<Player> find_player_by_name(std::string fullname);
        void update_teams_stats(std::shared_ptr<MatchResult> tmp_game_result);
        std::shared_ptr<SoccerClub> find_soccer_club_by_name(std::string fullname);
        void update_injured_players(ReadFileUtil& read_file_util);
        void update_players_yellow_card(ReadFileUtil& read_file_util);
        void update_players_red_card(ReadFileUtil& read_file_util);
        void update_players_scores(ReadFileUtil& read_file_util);


};
#endif
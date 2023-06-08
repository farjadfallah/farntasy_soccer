#ifndef __PLAYER__
#define __PLAYER__
#include <string>
#include <vector>
#include "MagicNumbers.hpp"
#include <memory>

class Player{
    public:
        Player(std::string _full_name);
        virtual std::string get_position() = 0;
        bool has_certain_name(std::string name);
        void injured();
        void add_yellow_card();
        void add_red_Card();
        void edit_new_score(double new_score);
        double get_score_at_week(int week);
        double total_points();
        double average_points();
        bool can_play_next_week();
        void pass_week();
        bool is_better_than_in_week(std::shared_ptr<Player> compared_to, int week);
        bool is_better_alphabetically(std::shared_ptr<Player> compared_to);

        std::string team_of_the_week_output(int week);
        std::string players_of_the_team_output();
        std::string fantasy_squad_output();
    private:
        std::string full_name;
        std::vector<double> ratings_each_week;
        int injury = NOT_INJURED;
        int yellow_card = 0;
        bool missed_next_match = false;
        
        void add_new_point();
        void pass_one_week_of_injury();
        void reset_misses_next_match_status();
};
#endif
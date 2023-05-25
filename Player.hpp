#ifndef __PLAYER__
#define __PLAYER__
#include <string>
#include <vector>

class Player{
    public:
        Player(std::string _full_name);
        virtual std::string get_position() = 0;
        void print();
        bool has_certain_name(std::string name);
        void injured();
        void add_yellow_card();
        void add_red_Card();
        void add_new_point();
        void edit_new_score(double new_score);
        void pass_one_week_of_injury();
        void reset_misses_next_match_status();
    private:
        std::string full_name;
        std::vector<double> ratings_each_week;
        int injury = 0;
        int yellow_card = 0;
        bool missed_next_match = false;
};
#endif
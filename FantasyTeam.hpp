#ifndef __FANTASY__TEAM__
#define __FANTASY__TEAM__

#include <vector>
#include <string>
#include <memory>
#include "Player.hpp"

class FantasyTeam {
    public:
        FantasyTeam(std::string _username, std::string password);
        bool has_certain_password(std::string _password);
        bool has_certain_username(std::string _username);
        void add_player(std::shared_ptr<Player> new_player);
        void delete_player(std::shared_ptr<Player> new_player);

        void pass_week(int new_week);
        void print();
        void squad();
        bool is_better_than(std::shared_ptr<FantasyTeam> compared_to);

        std::string user_ranking_output();
    private:
        std::string username;
        std::string password;
        std::vector<double> points_each_week;
        double points =0;
        std::vector<std::shared_ptr<Player> >  tmp_squad_players_list;
        std::vector<std::vector<std::shared_ptr<Player> > > players_list_each_week;
        int players_bought_this_week =0;
        int players_sold_this_week =0;
        bool once_completed = false;

        void check_if_team_can_sell_player();
        void check_if_team_can_buy_player(std::string post);
        int players_num_in_position(std::string position);
        double calculate_total_score(int week);
        std::vector<std::shared_ptr<Player> > get_player_with_position(std::string post);

};
#endif
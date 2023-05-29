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

        void print();
    private:
        std::string username;
        std::string password;
        std::vector<double> points_each_week;
        double points;
        std::vector<std::shared_ptr<Player> >  tmp_squad_players_list;
        std::vector<std::vector<std::shared_ptr<Player> > > players_list_each_week;
        int players_bought_this_week =0;
        int players_sold_this_week =0;
        bool once_completed = false;
        bool valid_team = false;

        bool can_sell_player();

};
#include <vector>
#include <string>
#include <memory>
#include "Player.hpp"

class FantasyTeam {
    public:
        FantasyTeam(std::string _username, std::string password);
        bool has_certain_password(std::string _password);
        bool has_certain_username(std::string _username);
    private:
        std::string username;
        std::string password;
        std::vector<double> points_each_week;
        double points;
        std::vector<std::shared_ptr<Player> >  tmp_squad_players_list;
        std::vector<std::vector<std::shared_ptr<Player> > > players_list_each_week;
        bool once_completed = false;
        bool valid_team = false;
    
};
#ifndef __PRINTER__
#define __PRINTER__
#include "WeekMatchResults.hpp"
#include <memory>
#include <vector>
#include <string>

class Printer{
    public:
        void print_matches_result_league(std::shared_ptr<WeekMatchResults> selected_week);
        void print_fantasy_squad(std::string username, std::vector<std::shared_ptr<Player> >& goalkeepers,
                std::vector<std::shared_ptr<Player> >& defenders, std::vector<std::shared_ptr<Player> >& midfielders,
                std::vector<std::shared_ptr<Player> >& forwards);
                
    private:

};
#endif
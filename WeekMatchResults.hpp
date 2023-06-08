#ifndef __WEEK_MATCH__RESULT__
#define __WEEK_MATCH__RESULT__
#include <vector>
#include <memory>
#include "MatchResult.hpp"

class WeekMatchResults{
    public:
        void add_result(std::shared_ptr<MatchResult> new_match_result);
        std::string match_result_league_output(int number);
        int size() {return results_list.size();};
    private:
        std::vector<std::shared_ptr<MatchResult> > results_list;

};


#endif
#ifndef __WEEK_MATCH__RESULT__
#define __WEEK_MATCH__RESULT__
#include <vector>
#include <memory>
#include "MatchResult.hpp"

class WeekMatchResults{
    public:
        void add_result(std::shared_ptr<MatchResult> new_match_result);
        void print();
    private:
        std::vector<std::shared_ptr<MatchResult> > results_list;

};


#endif
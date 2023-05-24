#include "WeekMatchResults.hpp"
#include <memory>

using namespace std;


void WeekMatchResults::add_result(shared_ptr<MatchResult> new_match_result){
    results_list.push_back(new_match_result);
}

void WeekMatchResults::print(){
    for(shared_ptr<MatchResult> tmp : results_list){
        tmp->print();
    }
}

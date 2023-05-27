#ifndef __PRINTER__
#define __PRINTER__
#include "WeekMatchResults.hpp"
#include <memory>
#include <vector>
#include <string>

class Printer{
    public:
        void print_matches_result_league(std::shared_ptr<WeekMatchResults> selected_week);
    private:

};
#endif
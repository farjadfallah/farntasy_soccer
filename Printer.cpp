#include "Printer.hpp"
#include "Exceptions.hpp"

#include <iostream>

using namespace std;
void Printer::print_matches_result_league(std::shared_ptr<WeekMatchResults> selected_week){
    for(int i=0; i<selected_week->size(); i++){
        cout << selected_week->return_game_summary(i) << endl;
    }
}

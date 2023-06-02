#include "Printer.hpp"
#include "Exceptions.hpp"
#include "Player.hpp"
#include <iostream>

using namespace std;
void Printer::print_matches_result_league(std::shared_ptr<WeekMatchResults> selected_week){
    for(int i=0; i<selected_week->size(); i++){
        cout << selected_week->return_game_summary(i) << endl;
    }
}
void Printer::print_fantasy_squad(std::string username, std::vector<std::shared_ptr<Player> >& goalkeepers,
                        std::vector<std::shared_ptr<Player> >& defenders, std::vector<std::shared_ptr<Player> >& midfielders,
                        std::vector<std::shared_ptr<Player> >& forwards){
    
    
    cout << "fantasy_team: " << username << endl;
    // cout << "Goalkeeper: " ;


}

void Printer::print_request_successful(){
    cout << SUCCESS_MESSAGE << endl;
}

void Printer::print_error(Exceptions& err){
    cout << err.error_message() << endl;
}
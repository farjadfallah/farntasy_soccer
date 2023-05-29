#include "FantasyFootball.hpp"
#include "ReadFileUtil.hpp"
#include <string>
#include <iostream>
#include "Exceptions.hpp"

using namespace std;

void handle_POST_command();
void handle_GET_command();
void handle_PUT_command();
void handle_delete_command();

enum {
    POST,
    GET,
    PUT,
    DELETE
};

enum {
    TEAM_OF_THE_WEEK,
    PLAYERS,
    LEAGUE_STANDINGS,
    USER_RANKING,
    MATHCES_RESULT_LEAGUE,
    SQUAD
};

enum {
    SIGNUP,
    LOGIN,
    LOGOUT,
    SELL_PLAYER,
    BUY_PLAYER,
    CLOSE_TRANSFER_WINDOW,
    OPEN_TRANSFER_WINDOW,
    PASS_WEEK
};


int main(){
    FantasyFootball fantasy_football;
    fantasy_football.add_admin("admin" , "123456");
    fantasy_football.register_admin("admin" , "123456");
    fantasy_football.get_initial_data();
    // fantasy_football.print();
    for(int i=0;i<19;i++){
        fantasy_football.pass_week();
    }
    
    fantasy_football.logout();
    fantasy_football.signup("farjad" , "Farjad83");
    fantasy_football.open_transfer_window();
    fantasy_football.buy_player("D. Sadi");
    fantasy_football.buy_player("Tommi O'reilly");
    fantasy_football.buy_player("J. Manquillo");
    fantasy_football.sell_player("J. Manquillo");
    fantasy_football.logout();
    fantasy_football.login("farjad" , "Farjad83");
    fantasy_football.sell_player("Tommi O'reilly");
    // fantasy_football.sell_player("D. Sadi");
    // fantasy_football.matches_result_league(19);
    // fantasy_football.get_players_of_team("Arsenal FC", "fw", 1);
    // fantasy_football.team_of_the_week(1);

    // fantasy_football.signup("farjad" , "Farjad83");
    // fantasy_football.print_weeks_resutls();
    // fantasy_football.print_clubs_standings();
    // fantasy_football.print_players_resutls();
    int command_type;
    // while(read_file_util.get_command_type(command_type)){
    //     switch (command_type)
    //     {
    //     case POST:
    //         handle_POST_command();
    //         break;
    //     case GET:
    //         handle_GET_command();
    //         break;
    //     case PUT:
    //         handle_PUT_command();
    //         break;
    //     case DELETE:
    //         handle_delete_command();
    //     default:
    //         break;
    //     }
    // }
}

// void handle_POST_command(ReadFileUtil& read_file_util, FantasyFootball& fantasy_football){
//     int command;
//     while(read_file_util.get_POST_command(command)){
//         switch (command)
//         {
//         case SIGNUP:
//             fantasy_football.signup();
//             break;
//         case LOGIN:
//             fantasy_football.login();
//             break;
//         case LOGOUT:
//             fantasy_football.logout();
//             break;
//         case SELL_PLAYER:
//             fantasy_football.sell_player();
//         case BUY_PLAYER:
//             fantasy_football.buy_player();
//             break;
//         case CLOSE_TRANSFER_WINDOW:
//             fantasy_football.close_transfer_window();
//             break;
//         case OPEN_TRANSFER_WINDOW:
//             fantasy_football.open_transfer_window();
//             break;
//         case PASS_WEEK:
//             fantasy_football.pass_week();
//         default:
//             break;
//         }
//     }
// }

// void handle_GET_command(ReadFileUtil& read_file_util, FantasyFootball& fantasy_football){
//     int command;
//     while(read_file_util.get_GET_command(command)){
//         switch (command)
//         {
//         case TEAM_OF_THE_WEEK:
//             fantasy_football.team_of_the_week();
//             break;
//         case PLAYERS:
//             fantasy_football.players();
//             break;
//         case LEAGUE_STANDINGS:
//             fantasy_football.league_standings();
//             break;
//         case USER_RANKING:
//             fantasy_football.user_ranking();
//         case MATHCES_RESULT_LEAGUE:
//             fantasy_football.matches_result_league();
//             break;
//         case SQUAD:
//             fantasy_football.squad();
//             break;
//         default:
//             break;
//         }
//     }
// }
#include "FantasyFootball.hpp"
#include "DataProvider.hpp"
#include <string>

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
    fantasy_football.get_initial_data();
    int command_type;
    // while(data_provider.get_command_type(command_type)){
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

// void handle_POST_command(DataProvider& data_provider, FantasyFootball& fantasy_football){
//     int command;
//     while(data_provider.get_POST_command(command)){
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

// void handle_GET_command(DataProvider& data_provider, FantasyFootball& fantasy_football){
//     int command;
//     while(data_provider.get_GET_command(command)){
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
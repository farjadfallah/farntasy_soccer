#include <string>
#include<fstream>

class DataProvider{
    public:
        DataProvider(std::string file_path);
        ~DataProvider();
        bool get_team_name_from_initial_file(std::string& team_name);
        bool get_Player_from_initiail_file(std::string& player_name);
    private:
        std::ifstream file;
};
#ifndef __DATA__PROVIDER__
#define __DATA__PROVIDER__
#include <string>
#include<fstream>

class DataProvider{
    public:
        DataProvider(std::string file_path);
        ~DataProvider();
        bool get_team_name_from_initial_file(std::string& team_name);
        bool get_Player_from_initiail_file(std::string& player_name);
        bool get_word_untill_delimiter(std::string& word, char delimiter, char first_end_sign, char second_end_sign = EOF);
        void get_header();
    private:
        std::ifstream file;
};
#endif
#include <iostream>
#include <string>
#include <vector>

class CommandProvider{
    public:
        bool get_command(std::vector<std::string>& words);
    private:
        std::vector<std::string> parse_word_by_word(std::string line);
        std::string prepare_raw_line();
};
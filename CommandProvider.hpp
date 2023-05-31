#include <iostream>
#include <string>
#include <vector>

class CommandProvider{
    public:
        std::vector<std::string> get_command();
    private:
        std::vector<std::string> parse_word_by_word(std::string line);
        std::string prepare_raw_line();
};
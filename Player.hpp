#include <string>
#include <vector>

class Player{
    public:
        Player(std::string _full_name);
        virtual std::string get_position() = 0;
        void print();
    private:
        std::string full_name;
        std::vector<double> ratings_each_week;
        int injured = 0;
        int yellow_card = 0;
        bool missed_next_match = false;
};
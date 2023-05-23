#include "Player.hpp"
#include <string>

class GoalKeeper : public Player {
    std::string get_position();
};

class Defender : public Player {
    std::string get_position();
};

class Midfeilder : public Player {
    std::string get_position();
};

class Forward : public Player {
    std::string get_position();
};
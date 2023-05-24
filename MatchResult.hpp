#ifndef __MATCH__RESULT__
#define __MATCH__RESULT__

#include<string>

class MatchResult{
    public:
        MatchResult(std::string _first_team, std::string _second_team, int _first_team_goals,int _second_team_goals);
        void print();
    private:
        std::string first_team;
        std::string second_team;
        int first_team_goals;
        int second_team_goals;
};

#endif
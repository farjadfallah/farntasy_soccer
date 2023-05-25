#ifndef __MATCH__RESULT__
#define __MATCH__RESULT__

#include<string>

class MatchResult{
    public:
        MatchResult(std::string _first_team, std::string _second_team, int _first_team_goals,int _second_team_goals);
        void print();
        std::string first_team();
        std::string second_team();
        int first_team_points();
        int second_team_points();
        int first_team_goals_for();
        int second_team_goals_for();
        int first_team_goals_against();
        int second_team_goals_against();
    private:
        std::string first_team_name;
        std::string second_team_name;
        int first_team_goals;
        int second_team_goals;
};

#endif

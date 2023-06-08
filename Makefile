Build=build

a.out: main.cpp ${Build}/FantasyFootball.o ${Build}/CommandDelegator.o  ${Build}/CommandProvider.o  ${Build}/ReadFileUtil.o ${Build}/Positions.o ${Build}/MatchResult.o ${Build}/FileReader.o Exceptions.hpp
	g++ main.cpp ${Build}/FantasyFootball.o ${Build}/CommandDelegator.o ${Build}/CommandProvider.o  ${Build}/Admin.o  ${Build}/FantasyTeam.o ${Build}/Printer.o  ${Build}/FileReader.o ${Build}/ReadFileUtil.o ${Build}/Positions.o ${Build}/MatchResult.o ${Build}/WeekMatchResults.o ${Build}/Player.o ${Build}/SoccerClub.o -o a.out

${Build}/FantasyFootball.o : FantasyFootball.hpp FantasyFootball.cpp ${Build}/Admin.o ${Build}/Printer.o ${Build}/FantasyTeam.o   ${Build}/FileReader.o ${Build}/WeekMatchResults.o  ${Build}/MatchResult.o ${Build}/ReadFileUtil.o ${Build}/Positions.o ${Build}/Player.o ${Build}/SoccerClub.o Exceptions.hpp
	g++ -c FantasyFootball.cpp -o ${Build}/FantasyFootball.o

${Build}/FileReader.o : FileReader.hpp FileReader.cpp ${Build}/WeekMatchResults.o  ${Build}/MatchResult.o ${Build}/ReadFileUtil.o ${Build}/Positions.o ${Build}/Player.o ${Build}/SoccerClub.o Exceptions.hpp
	g++ -c FileReader.cpp -o ${Build}/FileReader.o

${Build}/ReadFileUtil.o : ReadFileUtil.hpp ReadFileUtil.cpp Exceptions.hpp
	g++ -c ReadFileUtil.cpp -o ${Build}/ReadFileUtil.o

${Build}/Positions.o : Positions.hpp Positions.cpp ${Build}/Player.o Exceptions.hpp
	g++ -c Positions.cpp -o ${Build}/Positions.o

${Build}/Player.o : Player.hpp Player.cpp Exceptions.hpp
	g++ -c Player.cpp -o ${Build}/Player.o

${Build}/SoccerClub.o : SoccerClub.hpp SoccerClub.cpp Exceptions.hpp
	g++ -c SoccerClub.cpp -o ${Build}/SoccerClub.o

${Build}/MatchResult.o : MatchResult.hpp MatchResult.cpp  Exceptions.hpp
	g++ -c MatchResult.cpp -o ${Build}/MatchResult.o

${Build}/WeekMatchResults.o : WeekMatchResults.hpp WeekMatchResults.cpp ${Build}/MatchResult.o Exceptions.hpp
	g++ -c WeekMatchResults.cpp -o ${Build}/WeekMatchResults.o

${Build}/Printer.o : Printer.hpp Printer.cpp Exceptions.hpp ${Build}/Player.o ${Build}/SoccerClub.o ${Build}/FantasyTeam.o
	g++ -c Printer.cpp -o ${Build}/Printer.o

${Build}/FantasyTeam.o : FantasyTeam.hpp FantasyTeam.cpp ${Build}/Player.o Exceptions.hpp 
	g++ -c FantasyTeam.cpp -o ${Build}/FantasyTeam.o

${Build}/Admin.o : Admin.hpp Admin.cpp Exceptions.hpp
	g++ -c Admin.cpp -o ${Build}/Admin.o

${Build}/CommandProvider.o : CommandProvider.hpp CommandProvider.cpp 
	g++ -c CommandProvider.cpp -o ${Build}/CommandProvider.o

${Build}/CommandDelegator.o : CommandDelegator.hpp CommandDelegator.cpp FantasyFootball.cpp
	g++ -c CommandDelegator.cpp -o ${Build}/CommandDelegator.o

clear:
	rm -rf ${Build} && mkdir -p ${Build} && rm ./a.out
Build=build

a.out: main.cpp ${Build}/FantasyFootball.o ${Build}/ReadFileUtil.o ${Build}/Positions.o ${Build}/MatchResult.o ${Build}/FileReader.o
	g++ main.cpp ${Build}/FantasyFootball.o ${Build}/Printer.o  ${Build}/FileReader.o ${Build}/ReadFileUtil.o ${Build}/Positions.o ${Build}/MatchResult.o ${Build}/WeekMatchResults.o ${Build}/Player.o ${Build}/SoccerClub.o -o a.out

${Build}/FantasyFootball.o : FantasyFootball.hpp FantasyFootball.cpp ${Build}/Printer.o  ${Build}/FileReader.o ${Build}/WeekMatchResults.o  ${Build}/MatchResult.o ${Build}/ReadFileUtil.o ${Build}/Positions.o ${Build}/Player.o ${Build}/SoccerClub.o
	g++ -c FantasyFootball.cpp -o ${Build}/FantasyFootball.o

${Build}/FileReader.o : FileReader.hpp FileReader.cpp ${Build}/WeekMatchResults.o  ${Build}/MatchResult.o ${Build}/ReadFileUtil.o ${Build}/Positions.o ${Build}/Player.o ${Build}/SoccerClub.o
	g++ -c FileReader.cpp -o ${Build}/FileReader.o

${Build}/ReadFileUtil.o : ReadFileUtil.hpp ReadFileUtil.cpp 
	g++ -c ReadFileUtil.cpp -o ${Build}/ReadFileUtil.o

${Build}/Positions.o : Positions.hpp Positions.cpp ${Build}/Player.o 
	g++ -c Positions.cpp -o ${Build}/Positions.o

${Build}/Player.o : Player.hpp Player.cpp 
	g++ -c Player.cpp -o ${Build}/Player.o

${Build}/SoccerClub.o : SoccerClub.hpp SoccerClub.cpp 
	g++ -c SoccerClub.cpp -o ${Build}/SoccerClub.o

${Build}/MatchResult.o : MatchResult.hpp MatchResult.cpp 
	g++ -c MatchResult.cpp -o ${Build}/MatchResult.o

${Build}/WeekMatchResults.o : WeekMatchResults.hpp WeekMatchResults.cpp ${Build}/MatchResult.o
	g++ -c WeekMatchResults.cpp -o ${Build}/WeekMatchResults.o

${Build}/Printer.o : Printer.hpp Printer.cpp 
	g++ -c Printer.cpp -o ${Build}/Printer.o

clear:
	rm -rf ${Build} && mkdir -p ${Build} && rm ./a.out
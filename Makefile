Build=build

a.out: main.cpp ${Build}/FantasyFootball.o ${Build}/DataProvider.o ${Build}/Positions.o
	g++ main.cpp ${Build}/FantasyFootball.o ${Build}/DataProvider.o ${Build}/Positions.o ${Build}/Player.o ${Build}/SoccerClub.o -o a.out

${Build}/FantasyFootball.o : FantasyFootball.hpp FantasyFootball.cpp ${Build}/DataProvider.o ${Build}/Positions.o ${Build}/Player.o ${Build}/SoccerClub.o
	g++ -c FantasyFootball.cpp -o ${Build}/FantasyFootball.o

${Build}/DataProvider.o : DataProvider.hpp DataProvider.cpp 
	g++ -c DataProvider.cpp -o ${Build}/DataProvider.o

${Build}/Positions.o : Positions.hpp Positions.cpp ${Build}/Player.o 
	g++ -c Positions.cpp -o ${Build}/Positions.o

${Build}/Player.o : Player.hpp Player.cpp 
	g++ -c Player.cpp -o ${Build}/Player.o

${Build}/SoccerClub.o : SoccerClub.hpp SoccerClub.cpp 
	g++ -c SoccerClub.cpp -o ${Build}/SoccerClub.o


clear:
	rm -rf ${Build} && mkdir -p ${Build} && rm ./a.out
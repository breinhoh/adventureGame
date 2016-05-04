CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = Final_P.o Room.o MineRoom.o MazeRoom.o WaterRoom.o Ends.o Abyss.o DeadEnd.o WaterFall.o Outside.o Obstacle.o Rocks.o Gate.o Boulder.o Object.o Pick.o Tank.o LockPick.o Grenade.o

SRCS = Final_P.cpp Room.cpp MineRoom.cpp MazeRoom.cpp WaterRoom.cpp Ends.cpp Abyss.cpp DeadEnd.cpp WaterFall.cpp Outside.cpp Obstacle.cpp Rocks.cpp Gate.cpp Boulder.cpp Object.cpp Pick.cpp Tank.cpp LockPick.cpp Grenade.cpp

HEADERS = Room.hpp MineRoom.hpp MazeRoom.hpp WaterRoom.hpp Ends.hpp Abyss.hpp DeadEnd.hpp WaterFall.hpp Outside.hpp Obstacle.hpp Rocks.hpp Gate.hpp Boulder.hpp Object.hpp Pick.hpp Tank.hpp LockPick.hpp Grenade.hpp

Final_P: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o Final_P

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f *.o Final_P
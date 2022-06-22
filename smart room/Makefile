CXX = g++
CXXFLAGS = -std=c++2a -Wall -I h -I /usr/local/include/gtest/ -c
LXXFLAGS = -std=c++2a -Ih -pthread
OBJECTS = ./obj/room.o ./obj/dht11.o ./obj/main.o ./obj/aphw2_unittest.o
GTEST = /usr/local/lib/libgtest.a
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) -o $(TARGET) $(OBJECTS) $(GTEST)
./obj/room.o: ./cpp/room.cpp
	$(CXX) $(CXXFLAGS) ./cpp/room.cpp -o ./obj/room.o
./obj/dht11.o: ./cpp/dht11.cpp
	$(CXX) $(CXXFLAGS) ./cpp/dht11.cpp -o ./obj/dht11.o
./obj/aphw2_unittest.o: ./cpp/aphw2_unittest.cpp
	$(CXX) $(CXXFLAGS) ./cpp/aphw2_unittest.cpp -o ./obj/aphw2_unittest.o
./obj/main.o: ./cpp/main.cpp
	$(CXX) $(CXXFLAGS) ./cpp/main.cpp -o ./obj/main.o
clean:
	rm -fv $(TARGET) $(OBJECTS)

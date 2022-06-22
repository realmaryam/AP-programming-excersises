CXX = g++
CXXFLAGS = -std=c++2a -Wall -I h -I /usr/local/include/gtest/ -c
LXXFLAGS = -std=c++2a -Ih -pthread
OBJECTS = ./obj/triangle.o ./obj/square.o ./obj/rectangle.o ./obj/prism.o ./obj/pyramid.o ./obj/main.o ./obj/aphw4_unittest.o
GTEST = /usr/local/lib/libgtest.a
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) -o $(TARGET) $(OBJECTS) $(GTEST)
./obj/triangle.o: ./cpp/triangle.cpp
	$(CXX) $(CXXFLAGS) ./cpp/triangle.cpp -o ./obj/triangle.o
./obj/square.o: ./cpp/square.cpp
	$(CXX) $(CXXFLAGS) ./cpp/square.cpp -o ./obj/square.o
./obj/rectangle.o: ./cpp/rectangle.cpp
	$(CXX) $(CXXFLAGS) ./cpp/rectangle.cpp -o ./obj/rectangle.o
./obj/prism.o: ./cpp/prism.cpp
	$(CXX) $(CXXFLAGS) ./cpp/prism.cpp -o ./obj/prism.o
./obj/pyramid.o: ./cpp/pyramid.cpp
	$(CXX) $(CXXFLAGS) ./cpp/pyramid.cpp -o ./obj/pyramid.o
./obj/aphw4_unittest.o: ./cpp/aphw4_unittest.cpp
	$(CXX) $(CXXFLAGS) ./cpp/aphw4_unittest.cpp -o ./obj/aphw4_unittest.o
./obj/main.o: ./cpp/main.cpp
	$(CXX) $(CXXFLAGS) ./cpp/main.cpp -o ./obj/main.o
clean:
	rm -fv $(TARGET) $(OBJECTS)

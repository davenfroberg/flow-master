CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = src/Node.cpp src/solve.cpp src/LinkedGrid.cpp
OBJS = $(SRCS:src/%.cpp=obj/%.o)

TARGET = solve

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

obj/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

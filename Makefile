CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = Node.cpp solve.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = solve

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

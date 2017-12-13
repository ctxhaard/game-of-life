TARGET := game-of-life
CROSS_COMPILE ?= 
CXXFLAGS := -std=c++14 -O0 -ggdb 
LIBS := -L/usr/lib/i386-linux-gnu -lncurses
OBJS := main.o Gameplay.o

.cpp.o:
	$(CROSS_COMPILE)$(CXX) $(CXXFLAGS) -o $@ -c $< 

$(TARGET): $(OBJS)
	$(CROSS_COMPILE)$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LIBS)
	
clean:
	rm $(OBJS) $(TARGET)

# Settings
CXX := clang++
CXXFLAGS := -g -Wall -std=c++1z -stdlib=libc++

# Utility variables
OBJS := ssatan ssatan.o

# Utility targets
all: ssatan

clean:
	$(RM) $(OBJS)

# Binary targets
ssatan: ssatan.o
	$(CXX) $(CXXFLAGS) -g -o $@ $^

# Mark utility targets as phony
.PHONY: all clean
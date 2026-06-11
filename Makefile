CXX = g++
CXXFLAGS = -g -Wall -Wextra -std=c++17

# Automatically find all lecture directories so make can find source files
VPATH = $(sort $(wildcard lecture*/))

# Generic rule: make <name> compiles and runs <name>.cc or <name>.cpp
# With VPATH above, also finds sources in lecture06/, lecture07/, etc.
# FORCE ensures it always runs the program, even if already compiled
%: %.cc FORCE
	$(CXX) $(CXXFLAGS) -o $@ $<
	./$@

%: %.cpp FORCE
	$(CXX) $(CXXFLAGS) -o $@ $<
	./$@

FORCE:

# Multi-file programs — compile and link all .cpp files together
ex3: $(wildcard lecture08/exercise3/*.cpp)
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@

# Clean: delete compiled binaries, .dSYM folders, and .txt files
# Keeps .cc files, Makefile, build.sh, .vscode, .git, and any hidden files
.PHONY: clean
clean:
	find . -type d -name "*.dSYM" -exec rm -rf {} + 2>/dev/null
	find . -type f ! -name "*.*" ! -name "Makefile" -not -path "./.git/*" -delete
	rm -f *.txt

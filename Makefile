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
ex3: $(wildcard lecture08/exercise3/*.cpp) FORCE
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@

# Generic rule: make lec<NN> compiles all .cpp files in lecture<NN>/
# and links them together. Works for standard multi-file lectures like lec08.
lec%: FORCE
	$(CXX) $(CXXFLAGS) -o $@ $(wildcard lecture$*/*.cpp)
	./$@

# Override: lec09 uses a "header includes .cpp" template pattern,
# so bounded_value.cpp must NOT be compiled separately.
lec09: FORCE
	$(CXX) $(CXXFLAGS) -o $@ lecture09/main.cpp
	./$@

# Clean: delete compiled binaries, .dSYM folders, and .txt files
# Keeps .cc files, Makefile, build.sh, .vscode, .git, and any hidden files
.PHONY: clean
clean:
	find . -type d -name "*.dSYM" -exec rm -rf {} + 2>/dev/null
	find . -type f ! -name "*.*" ! -name "Makefile" -not -path "./.git/*" -delete
	rm -f *.txt

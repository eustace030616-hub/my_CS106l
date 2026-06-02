CXX = g++
CXXFLAGS = -g -Wall -Wextra

# Generic rule: make <name> compiles and runs <name>.cc or <name>.cpp
# FORCE ensures it always runs the program, even if already compiled
%: %.cc FORCE
	$(CXX) $(CXXFLAGS) -o $@ $<
	./$@

%: %.cpp FORCE
	$(CXX) $(CXXFLAGS) -o $@ $<
	./$@

FORCE:

# Clean: delete all compiled binaries and .dSYM folders
# Keeps .cc files, Makefile, build.sh, .vscode, and any hidden files
.PHONY: clean
clean:
	rm -rf *.dSYM
	find . -maxdepth 1 -type f ! -name "*.*" ! -name "Makefile" -delete

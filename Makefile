# Comp 15: Data Structures
# Tufts University
# Makefile Template
#

#
# Makefile for proj2
#
# proj2 (fall 2019)
#

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11


example: copy_con_assignment_op_example.cpp ArrayPoint.o
		${CXX} -o $@ $^
	
%.o: %.cpp $(shell echo *.h)
	${CXX} ${CXXFLAGS} -c $<


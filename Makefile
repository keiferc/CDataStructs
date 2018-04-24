#
#       filename:       Makefile
#       author:         @keiferchiang
#       date:           23 Apr. 2018
#       version:        0.0.1
# 
#       description:    Makefile for custom C data structures
# 

#######################################
# Variables                           #
#######################################
CC = gcc

IFLAGS  = -I./api
CFLAGS  = -g -std=c99 -Wall -Wextra -Werror -pedantic $(IFLAGS)
LDFLAGS = -g -L. -L./lib
LDLIBS  = 

EXECS   = test_vector

#######################################
# Main Rule                           #
#######################################
all: $(EXECS)

#######################################
# Compilation Rules                   #
#######################################
#------ Compilation Stage ------#
./obj/test_vector.o: ./test/test_vector.c
	$(CC) $(CFLAGS) -c $< -o $@

./obj/vector.o: ./src/vector.c ./api/vector.h
	$(CC) $(CFLAGS) -c $< -o $@

#------- Linking Stage ------#
test_vector: ./obj/test_vector.o ./obj/vector.o
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

#######################################
# Custom Rules                        #
#######################################
clean:
	rm -rf $(EXECS) *.o *.dSYM




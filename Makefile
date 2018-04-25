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

IFLAGS  = -I. -I./api/admin -I./api/datastructs
CFLAGS  = -g -std=c99 -Wall -Wextra -Werror -Wfatal-errors -pedantic \
	  $(IFLAGS)
LDFLAGS = -g -L. -L./lib
LDLIBS  = -lcmods

EXECS   = test_vector

ADMIN	= ./api/admin
DS	= ./api/datastructs
OBJS	= ./obj/vector.o

#######################################
# Main Rule                           #
#######################################
all: $(EXECS)

#######################################
# Compilation Rules                   #
#######################################
#------ Compilation Stage ------#
test_vector.o: ./test/test_vector.c
	$(CC) $(CFLAGS) -c $< -o $@

./obj/vector.o: ./src/vector.c $(DS)/vector.h
	$(CC) $(CFLAGS) -c $< -o $@

#------- Linking Stage ------#
test_vector: test_vector.o ./obj/vector.o
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

#######################################
# Custom Rules                        #
#######################################
lib: $(OBJS)
	ar rc ./lib/libcmods.a $^; ranlib ./lib/libcmods.a

clean:
	rm -rf $(EXECS) *.o *.dSYM $(OBJS)




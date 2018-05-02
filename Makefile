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

IFLAGS  = -I. -I./include
CFLAGS  = -g -std=c99 -Wall -Wextra -Werror -Wfatal-errors -pedantic \
	  $(IFLAGS)
LDFLAGS = -g -L. -L./lib
LDLIBS  = #-lcdatastructs

EXECS   = test_vector test_list
OBJS	= ./obj/vector.o ./obj/linkedlist.o

#######################################
# Main Rule                           #
#######################################
all: $(EXECS)

#######################################
# Compilation Rules                   #
#######################################
#------ Compilation Stage ------#
# Test Files
test_vector.o: ./test/test_vector.c
	$(CC) $(CFLAGS) -c $< -o $@

test_list.o: ./test/test_list.c
	$(CC) $(CFLAGS) -c $< -o $@

# Data Structures
./obj/vector.o: ./src/vector.c ./include/vector.h
	$(CC) $(CFLAGS) -c $< -o $@

./obj/linkedlist.o: ./src/linkedlist.c ./include/linkedlist.h
	$(CC) $(CFLAGS) -c $< -o $@

#------- Linking Stage ------#
test_vector: test_vector.o ./obj/vector.o
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

test_list: test_list.o ./obj/linkedlist.o
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

#######################################
# Custom Rules                        #
#######################################
lib: $(OBJS)
	ar rc ./lib/libcdatastructs.a $^; ranlib ./lib/libcdatastructs.a

clean:
	rm -rf $(EXECS) *.o *.dSYM $(OBJS)

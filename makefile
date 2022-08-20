OPTS=-Wall -g -std=c++11
OBJS=main.o bot.o util.o
CC=g++

main: $(OBJS)
	$(CC) $(OPTS) $(OBJS) -o aaa

main.o: main.cc util.h bot.h
	$(CC) $(OPTS) -c main.cc

bot.o:  bot.cc bot.h util.h util.cc
	$(CC) $(OPTS) -c bot.cc

util.o: util.cc util.h
	$(CC) $(OPTS) -c util.cc

clean:
	rm $(OBJS)

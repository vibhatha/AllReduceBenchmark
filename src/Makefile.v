# This is a makefile.

PROG = allreduce
OBJ = main.o Initializer.o Util.o

#flags. -I /home/vibhatha/tools/blass/build/include/ -L/home/vibhatha/tools/blass/build/lib -lopenblas
CC = mpic++ -std=c++11 -I/usr/include/openblas
LFLAG = -lopenblas -lpthread -ftree-vectorize -ftree-vectorizer-verbose=2 -msse -ffast-math
CFLAG = -c
OFLAG = -o
GFLAG = -g
OPFLAG = -OFast

all: $(PROG)

$(PROG) : $(OBJ)
	$(CC) $(GFLAG) $(OPFLAG) $(OFLAG) $(PROG) $(OBJ) $(LFLAG)
%.o : %.cpp
	$(CC) -c $(CFLAG)  $< -o $@

clean:
	rm -f *.o


#-I /home/vibhatha/tools/blass/build/include/ -L /home/vibhatha/tools/blass/build/lib/

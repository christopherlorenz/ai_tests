# use "gcc" to compile source files.
CC = gcc
# the linker is also "gcc". It might be something else with other compilers.
LD = gcc
# Compiler flags go here.
CFLAGS = -g -Wall -std=c99
# Linker flags go here. Currently there aren't any, but if we'll switch to
# code optimization, we might add "-s" here to strip debug info and symbols.
LDFLAGS =
# use this command to erase files.
RM = /bin/rm -f
# list of generated object files.
OBJS = main.o createDataset.o initializeWeights.o rescaleData.o calcPredicted.o
# program executable file name.
PROG = ANN_test

# top-level rule, to compile everything.
all: $(PROG)

# rule to link the program
$(PROG): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(PROG)

# rule for file "main.o".
main.o: main.c createDataset.c createDataset.h initializeWeights.c initializeWeights.h rescaleData.c rescaleData.h calcPredicted.c calcPredicted.h
	$(CC) $(CFLAGS) -c main.c

# rule for file "file1.o".
createDataset.o: createDataset.c createDataset.h
	$(CC) $(CFLAGS) -c createDataset.c

initializeWeights.o: initializeWeights.c initializeWeights.h
	${CC} $(CFLAGS) -c initializeWeights.c

rescaleData.o: rescaleData.c rescaleData.h
	${CC} $(CFLAGS) -c rescaleData.c

calcPredicted.o: calcPredicted.c calcPredicted.h
	${CC} $(CFLAGS) -c calcPredicted.c

# rule for cleaning re-compilable files.
clean:
	$(RM) $(PROG) $(OBJS)

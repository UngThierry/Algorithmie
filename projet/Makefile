CC = gcc
GLOUTON = AlgoGlouton.c
ALGO1 = Algo1.c
OPTIMISE = AlgoOptimise.c
COMPATIBLE = TestGloutonCompatible.c
CFLAGS = 

all : glouton algo1 algo_optimise compatible

glouton : $(GLOUTON)
	$(CC) $(CFLAGS) -o $@ $<

algo1 : $(ALGO1)
	$(CC) $(CFLAGS) -o $@ $<

algo_optimise : $(OPTIMISE)
	$(CC) $(CFLAGS) -o $@ $<

compatible : $(COMPATIBLE)
	$(CC) $(CFLAGS) -o $@ $<

clean :
	rm -f *~ *.o glouton algo1 algo_optimise compatible
	cd res_opti && rm -f *~ *.o 
	cd res_glouton && rm -f *~ *.o 
	cd res_compatible && rm -f *~ *.o
$(CC) = gcc
appln: main.o mean.o sub.o
	$(CC) main.o mean.o sub.o -o appln

main.o:	main.c calc_mean.h
	$(CC) -c main.c
mean.o: mean.c calc_mean.h
	$(CC) -c mean.c
sub.o: sub.c calc_mean.h
	$(CC) -c sub.c
clean:
	rm -f *.o

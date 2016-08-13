descompresor : main.o read.o Pilas.o
		gcc -o descompresor main.o read.o Pilas.o
main.o: main.c read.h Pilas.h
		gcc -c main.c
read.o: read.c read.h
		gcc -c read.c
Pilas.o: Pilas.c Pilas.h
		gcc -c Pilas.c

clean: 
		rm main.o read.o Pilas.o

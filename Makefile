
result: main.o compute.o validate.o errorhandler.o display.o
	gcc -o result main.o compute.o validate.o errorhandler.o display.o

main.o: main.c
	gcc -c main.c

compute.o: compute.c
	gcc -c compute.c

validate.o: validate.c
	gcc -c validate.c

errorhandler.o: errorhandler.c
	gcc -c errorhandler.c

display.o: display.c
	gcc -c display.c

run: result
	./result input.txt output.txt
	cat output.txt

clean:
	rm -f *.o result

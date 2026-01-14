result: main.c students.c compute.c validate.c errorhandler.c
	gcc -o result main.c students.c compute.c validate.c errorhandler.c

run:
	./result input.txt output.txt
	cat output.txt

clean:
	rm -f result

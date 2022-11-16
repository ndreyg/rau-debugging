prog: example.o
	gcc example.o --coverage -o prog

example.o: example.c
	gcc -c -g --coverage -Wall -Werror example.c

coverage: prog
	lcov --no-external --capture --initial --directory . --output-file coverage.info
	valgrind ./prog Username AAA
	valgrind ./prog; echo $?
	valgrind ./prog Username AAAA bbb
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-dir html

clean:
	rm -rf *.gcno *.gcda coverage.info *.o prog html

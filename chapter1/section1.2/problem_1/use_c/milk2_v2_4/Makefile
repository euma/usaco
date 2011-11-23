filename=milk2
all:
	gcc -Wall -Wextra $(filename).c
	mv a.out ~
	sudo chmod u+x ~/a.out
	~/a.out
	rm ~/a.out
	diff sample_$(filename).out $(filename).out

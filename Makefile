
compile: 
	gcc -g -o bin/tempo_de_resposta src/tempo_de_resposta.c -lm

test: compile
	./bin/tempo_de_resposta < input/testcase_1.data

clean:
	rm -r bin/*

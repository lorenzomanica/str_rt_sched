
compile: 
	gcc -g -o bin/tempo_de_resposta src/tempo_de_resposta.c -lm

test: compile
	./bin/tempo_de_resposta < input/testcase_1.data > result/testcase_1.data
	./bin/tempo_de_resposta < input/tresp_1 > result/tresp_1
	./bin/tempo_de_resposta < input/tresp_2 > result/tresp_2
	./bin/tempo_de_resposta < input/tresp_3 > result/tresp_3
	./bin/tempo_de_resposta < input/tresp_4 > result/tresp_4
	./bin/tempo_de_resposta < input/tresp_5 > result/tresp_5
	./bin/tempo_de_resposta < input/tresp_6 > result/tresp_6
	./bin/tempo_de_resposta < input/tresp_7 > result/tresp_7
	./bin/tempo_de_resposta < input/tresp_8 > result/tresp_8
	

clean:
	rm -r bin/*

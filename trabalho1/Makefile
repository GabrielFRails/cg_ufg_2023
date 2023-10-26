run_escala:
	gcc -c escala.c -lGL -lGLU -lglut && \
	gcc -o escala escala.c -lGL -lGLU -lglut && \
	./escala

run_translacao:
	gcc -c translacao.c -lGL -lGLU -lglut && \
	gcc -o translacao translacao.c -lGL -lGLU -lglut && \
	./translacao

run_rotacao:
	gcc -c rotacao.c -lGL -lGLU -lglut && \
	gcc -o rotacao rotacao.c -lGL -lGLU -lglut -lm && \
	./rotacao

runall: run_escala run_translacao run_rotacao
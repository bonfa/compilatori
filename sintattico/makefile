sintattico: sintattico.o lessicale.o
	cc -g -o sintattico sintattico.o lessicale.o

sintattico.o: sintattico.c def.h
	cc -g -c sintattico.c

lessicale.o: lessicale.c def.h
	cc -g -c lessicale.c

lessicale.c: lessicale.lex def.h
	flex -o lessicale.c lessicale.lex

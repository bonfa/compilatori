sintattico: sintattico.o lessicale.o albero.o
	cc -g -o sintattico sintattico.o lessicale.o albero.o

sintattico.o: sintattico.c def.h
	cc -g -c sintattico.c

albero.o: def.h albero.c
	cc -g -c albero.c

lessicale.o: lessicale.c def.h
	cc -g -c lessicale.c

lessicale.c: lessicale.lex def.h
	flex -o lessicale.c lessicale.lex

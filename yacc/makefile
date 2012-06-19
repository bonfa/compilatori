parser: parser.o lessicale.o albero.o solo_sintassi
	cc -g -o parser parser.o lessicale.o albero.o

solo_sintassi: parser_solo_sintassi.o lessicale.o albero.o
	cc -g -o solo_sintassi parser_solo_sintassi.o lessicale.o 

lessicale.o: lessicale.c def.h parser.h
	cc -g -c lessicale.c

parser.o: parser.c def.h
	cc -g -c parser.c
	cc -g -c parser_solo_sintassi.c

albero.o: def.h albero.c
	cc -g -c albero.c

lessicale.c: lessicale.lex def.h parser.y parser.h parser.c
	flex -o lessicale.c lessicale.lex

parser.c: parser.y def.h
	bison -vd -o parser.c parser.y
	bison -vd -o parser_solo_sintassi.c parser_solo_sintassi.y	

objects =  main.o TextQuery.o QueryResult.o NotQuery.o OrQuery.o AndQuery.o

edit: $(objects)
	g++ -o edit $(objects)

TextQuery.o: TextQuery.cpp TextQuery.h QueryResult.h
	g++ -c -std=c++14 TextQuery.cpp
QueryResult.o: QueryResult.cpp QueryResult.h TextQuery.h
	g++ -c -std=c++14 QueryResult.cpp
NotQuery.o: NotQuery.cpp NotQuery.h Query_base.h Query.h
	g++ -c -std=c++14 NotQuery.cpp
OrQuery.o: OrQuery.cpp OrQuery.h BinaryQuery.h Query.h
	g++ -c -std=c++14 OrQuery.cpp
AndQuery.o: AndQuery.cpp AndQuery.h BinaryQuery.h Query.h
	g++ -c -std=c++14 AndQuery.cpp
main.o: main.cpp Query.h QueryResult.h TextQuery.h
	g++ -c -std=c++14 main.cpp

clean:
	rm edit $(objects)


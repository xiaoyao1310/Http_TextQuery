#include "QueryResult.h"
#include "Query.h"
#include "AndQuery.h"
#include "OrQuery.h"
#include "NotQuery.h"
#include "connect.h"

int main(int argc, char ** argv) {
	connect(argv[1]); // host name, eg: blog.sina.com.cn
	
	std::string s;
	std::cout << "input file name" << std::endl;
	std::cin >> s;
	std::ifstream ifs(s);
	TextQuery tq(ifs);
	
	std::string s1, s2;
	std::cout << "input word one" << std::endl;
	std::cin >> s1;
	std::cout << "input word two" << std::endl;
	std::cin >> s2;
	Query q1(s1);
	Query q2(s2);

	print(std::cout, q1.eval(tq));
	print(std::cout, (~q2).eval(tq));
	print(std::cout, (q1 & q2).eval(tq));
	print(std::cout, (q1 | q2).eval(tq));

	return 0;
}


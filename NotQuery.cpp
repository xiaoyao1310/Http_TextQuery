#include "NotQuery.h"

QueryResult NotQuery::eval(const TextQuery& text) const {
	// virtual call, return QueryResult
	auto result = query.eval(text);

	auto ret_lines = std::make_shared<std::set<line_no>>();
	auto beg = result.begin(), end = result.end();
	auto sz = result.get_file()->size();
	// for each line in the input file (vector<string>)
	for (size_t n = 0; n != sz; n++) {
		// check if current line # n is in result
		if (beg == end || *beg != n)
			ret_lines->insert(n); // if not, write down n
		else if (beg != end)
			++beg; // if so, pass and check with next # in result
	}
	
	return QueryResult(rep(), ret_lines, result.get_file());
}

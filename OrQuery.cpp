#include "OrQuery.h"

QueryResult OrQuery::eval(const TextQuery& text) const {
	// virtual calls, Query members lhs rhs
	auto right = rhs.eval(text), left = lhs.eval(text); // QueryResult
	auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());  // left query lines
	ret_lines->insert(right.begin(), right.end()); // left or right
	return QueryResult(rep(), ret_lines, left.get_file());
}

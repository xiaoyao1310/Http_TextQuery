#ifndef QUERYRESULT_H
#define QUERYRESULT_H

//#include <string>
#include "TextQuery.h"

class QueryResult {
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> p, std::shared_ptr<std::vector<std::string>> f): sought(s), lines(p), file(f) {}
	auto begin() { return lines -> begin(); } // deduced return type c++14
	auto end() { return lines -> end(); }
	std::shared_ptr<std::vector<std::string>> get_file() { return file; }
private:
	std::string sought;	// the word
	std::shared_ptr<std::set<TextQuery::line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file; // input
};

#endif

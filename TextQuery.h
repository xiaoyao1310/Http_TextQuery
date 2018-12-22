#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <iostream>
#include <fstream>
#include <memory>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <algorithm> // find


class QueryResult;

class TextQuery {
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
private:
	std::shared_ptr<std::vector<std::string>> file; //input
	// map word to lines
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

#endif

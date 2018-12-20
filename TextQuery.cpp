#include "TextQuery.h"

// read input file and build the map
TextQuery::TextQuery(std::ifstream &is) : file(new std::vector<std::string>){
	std::string text;
	while (getline(is, text)) {
		file -> push_back(text);
		int n = file -> size() - 1; // current line number
		std::istringstream line(text); //separate into words
		std::string word;
		while (line >> word) {
			auto &lines = wm[word]; // lines is reference to that shared_ptr
			if (!lines)
				lines.reset(new std::set<line_no>);
			lines -> insert(n);
		}
	}
}

QueryResult TextQuery::query(const std::string& sought) const {
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file); // (string, ptr<set<line_no> ptr<vector<string>>)
	else
		return QueryResult(sought, loc -> second, file);
}

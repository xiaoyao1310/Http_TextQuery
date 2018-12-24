#include "QueryResult.h"

std::string make_plural(size_t ctr, const std::string& word, const std::string& ending) {
	return (ctr > 1) ? word + ending : word;
}

std::ostream& print(std::ostream &os, const QueryResult &qr) {
	os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << std::endl;
	// print each line #  and the line content
	for (auto num : *qr.lines)
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << std::endl;
	os << std::endl;
	return os;
}


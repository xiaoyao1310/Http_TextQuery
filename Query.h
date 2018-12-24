#ifndef QUERY_H
#define QUERY_H

#include "WordQuery.h"

class Query {
	// there operator need access to the shared_ptr constructor
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	Query(const std::string&);	// build a new WordQuery
	// interface fuctions: call corresponding Query_base operation
	QueryResult eval(const TextQuery &t) const { return q->eval(t); }
	std::string rep() const { return q->rep(); }
private:
	Query(std::shared_ptr<Query_base> query): q(query) {}
	std::shared_ptr<Query_base> q;
};

inline Query::Query(const std::string &s): q(new WordQuery(s)) {}

#endif

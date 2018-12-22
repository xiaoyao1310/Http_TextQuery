#ifndef QUERY_BASE_H
#define QUERY_BASE_H

#include "QueryResult.h"

// virtual class
class Query_base {
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0;
	// string representation
	virtual std::string rep() const = 0;
};

#endif

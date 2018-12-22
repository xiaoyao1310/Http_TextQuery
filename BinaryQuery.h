#ifndef BINARYQUERY_H
#define BINARYQUERY_H

#include "Query_base.h"
#include "Query.h"

// abstract class : not defining eval(...)
class BinaryQuery : public Query_base {
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s): lhs(l), rhs(r), opSym(s) {}
	std::string rep() const { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }

	Query lhs, rhs; // l and r operands
	std::string opSym;
};

#endif

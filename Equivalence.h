#ifndef EQUIVALENCE_H
#define EQUIVALENCE_H

#include "BoolExpr.h"

class Equivalence : public BoolExpr
{
public:
	Equivalence(Expr* left, Expr* right): BoolExpr(left, right) {};
	
	virtual bool compute()
	{
		return( getLeftOperand()->compute() == getRightOperand()->compute());
	};
	
	//virtaul void accept(Exprvisitor* v) {v->visitEquivalence(this); };
};



#endif

#ifndef EQUIVALENCE_H
#define EQUIVALENCE_H

#include "BoolExpr.h"
#include "ExprVisitor.h"

class Equivalence : public BoolExpr
{
public:
	Equivalence(Expr* left, Expr* right): BoolExpr(left, right) {};
    
    /*test to get the type*/
    std::string getType() {return "eq";};
	
	virtual bool compute()
	{
		return( getLeftOperand()->compute() == getRightOperand()->compute());
	};
	
	virtual void accept(ExprVisitor* v) {v->visitEquivalence(this); };
};



#endif

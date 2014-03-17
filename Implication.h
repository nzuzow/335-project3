#ifndef IMPLICATION_H
#define IMPLICATION_H

#include "ExprVisitor.h"

/*class Implication: public BoolExpr{
public:
	Implication(Expr* left, Expr* right): BoolExpr(left, right) {};
	virtual bool compute () {return ( getLeftOperand()->compute() > getRightOperand()->compute() ); } // may just need to add a condition -- if result > 1 then result = 1
	virtual void accept(ExprVisitor* v) {v->visitImplication(this)}

};*/

class Implication: public BoolExpr{

public:

    Implication(Expr* left, Expr* right): BoolExpr(left, right) {};

    virtual bool compute ()

   {

		bool lop = getLeftOperand()->compute();

		bool rop = getRightOperand()->compute();

		return (lop > rop);
   };

    virtual void accept(ExprVisitor* v) {v->visitImplication(this);};

};




#endif

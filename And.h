#ifndef AND_H
#define AND_H

#include "BoolExpr.h"
#include "ExprVisitor.h"


/*class And: public BoolExpr
{
public:
	And( Expr* left, Expr* right): BoolExpr(left, right) {};
	
	virtual bool compute() 
	{
		return( getLeftOperand()->compute()*getRightOperand()->compute());
	};
	
	virtual void accept(ExprVisitor* v){v->visitMultiply(this);};
};*/

class And: public BoolExpr

{

public:

   And( Expr* left, Expr* right): BoolExpr(left, right) {};

   virtual bool compute()

   {

       bool lop = getLeftOperand()->compute();

       bool rop = getRightOperand()->compute();

		return (lop*rop);
   };


   virtual void accept(ExprVisitor* v){v->visitAnd(this);};

};


#endif

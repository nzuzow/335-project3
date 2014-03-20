#ifndef OR_H
#define OR_H

#include "BoolExpr.h"
#include "ExprVisitor.h"

/*class Or: public BoolExpr{
public:
	Or(Expr* left, Expr* right): BoolExpr(left, right) {};
	virtual bool compute () {return ( getLeftOperand()->compute() + getRightOperand()->compute() ); } // may just need to add a condition -- if result > 1 then result = 1
	virtual void accept(ExprVisitor* v) {v->visitOr(this)}

};*/


class Or: public BoolExpr{

public:

   Or(Expr* left, Expr* right): BoolExpr(left, right) {};
    
    /*Test to allow us to get its type*/
    std::string getType() {return "or";};

    virtual bool compute ();

   /*{

		bool lop = getLeftOperand()->compute();

		bool rop = getRightOperand()->compute();
		
		return (lop + rop);
   };*/

   virtual void accept(ExprVisitor* v) {v->visitOr(this);};

};




#endif

#ifndef IMPLICATION_H
#define IMPLICATION_H

#include "ExprVisitor.h"

class Implication: public BoolExpr{

public:

    Implication(Expr* left, Expr* right): BoolExpr(left, right) {};
    
    /*Test to get type*/
    std::string getType() {return "imp";};

    virtual bool compute ();

   /*{

		bool lop = getLeftOperand()->compute();

		bool rop = getRightOperand()->compute();
       
       //implication is equivalent to ~x|y
       
        if( lop == false)
        {
            lop = true;
        }
        else
        {
           lop = false;
        }

        bool result = rop + lop;

        return result;
		//return (lop > rop);
   };*/

    virtual void accept(ExprVisitor* v) {v->visitImplication(this);};

};




#endif

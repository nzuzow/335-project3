#ifndef EXPR_H
#define EXPR_H

#include "ExprVisitor.h"

class Expr
{
public:
    /*Test to get type*/
    virtual std::string getType()=0;
	virtual bool compute()=0;
	virtual void accept(ExprVisitor*)=0;
};



#endif

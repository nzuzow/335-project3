#ifndef BOOLEANEXPR_H
#define BOOLEANEXPR_H

#include "Expr.h"
#include "ExprVisitor.h"


class BoolExpr: public Expr
{
private:
	Expr* m_leftPtr;
	Expr* m_rightPtr;

protected:
	BoolExpr(Expr* left, Expr* right):m_leftPtr(left),m_rightPtr(right) {};
	virtual ~BoolExpr(); // {delete m_leftPtr; delete m_rightPtr;};

public:
	Expr* getLeftOperand() {return m_leftPtr;};
	Expr* getRightOperand() {return m_rightPtr;};

};


#endif

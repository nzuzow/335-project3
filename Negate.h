#ifndef NEGATE_H
#define NEGATE_H

#include "ExprVisitor.h"
#include "Expr.h"

class Negate: public Expr{
private:
	Expr* m_opPtr;
public:
	Negate (Expr* opr):m_opPtr(opr){};
	virtual ~Negate() {delete m_opPtr;}
	Expr* getOperand() {return m_opPtr;}
	
	virtual bool compute() {return -(m_opPtr->compute());}
	virtual void accept(ExprVisitor* v) {v->visitNegate(this);}
};
	





#endif



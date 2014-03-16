#ifndef NEGATE_H
#define NEGATE_H

class Negate: public Expr{
private:
	Expr* m_opPtr;
public:
	Negate (Expr* opr);
	virtual ~Negate() {delete m_opr;}
	Expr* getOperand() {return m_opr;}
	
	//virtual bool compute() {return -(m_opPtr->compute());}
	//virtual void accept(ExprVisitor* v) {v->visitNegate(this);}
};
	





#endif



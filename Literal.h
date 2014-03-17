#ifndef LITERAL_H
#define LITERAL_H

#include "ExprVisitor.h"

class Literal: public Expr{
private:
	bool m_lit;
	
public:
	Literal (bool lit) {m_lit = lit;};
	~Literal ();
	bool getLiteral() {return m_lit;}

	virtual bool compute() {return m_lit;}

	virtual void accept(ExprVisitor* v) { v->visitLiteral(this); }

};





#endif

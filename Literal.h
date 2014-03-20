#ifndef LITERAL_H
#define LITERAL_H

#include "ExprVisitor.h"
#include "Expr.h"

class Literal: public Expr{
private:
	bool m_lit;
	
public:
	Literal (bool lit) {m_lit = lit;};
	~Literal ();
	bool getLiteral() {return m_lit;}
    
    /*Test to allow us to see if its a variable or literal*/
    std::string getType() {return "lit";};

	virtual bool compute() {return m_lit;}

	virtual void accept(ExprVisitor* v) { v->visitLiteral(this); }

};





#endif

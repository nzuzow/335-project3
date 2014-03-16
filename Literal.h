#ifndef LITERAL_H
#define LITERAL_H

class Literal: public Expr{
private:
	bool m_value;
	
public:
	Literal (bool val);
	~Literal (bool val);
	bool getValue() {return m_value;}

	virtual bool compute() {return m_value;}

	//virtual void accept(ExprVisitor* v) { v->visitLiteral(this); }

};





#endif

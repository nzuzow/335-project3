#ifndef VARIABLE_H
#define VARIABLE_H

class Variable: public Expr{
private:
	bool m_var;

public: 
	Variable (bool var);
	~Variable (bool var);

	bool Assign(bool var) {m_var = var;}
	bool getVar() {return m_var;}

	virtual bool compute() {return m_var;}
	
	
	//virtual void accept(ExprVisitor* v) { v->visitVariable(this); }
};







#endif

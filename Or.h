#ifndef OR_H
#define OR_H

class Or: public BoolExpr{
public:
	Or(Expr* left, Expr* right): BoolExpr(left, right) {};
	virtual bool compute () {return ( getLeftOperand()->compute() + getRightOperand()->compute() ); } // may just need to add a condition -- if result > 1 then result = 1
	virtual void accept(ExprVisitor* v) {v->visitOr(this)}

};







#endif

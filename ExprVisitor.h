#ifndef EXPRVISITOR_H
#define EXPRVISITOR_H
#include <stack>

//forward declaration
class Literal;
class Negate;
class Or;
class And;
class Variable;
class Implication;
class Equivalence;

class ExprVisitor{
public: 
	virtual void visitLiteral(Literal*)=0;
	virtual void visitNegate(Negate*)=0;
	virtual void visitOr(Or*)=0;
	virtual void visitAnd(And*)=0;
	virtual void visitVariable(Variable*)=0;
	virtual void visitImplication(Implication*)=0;
	virtual void visitEquivalence(Equivalence*)=0;
};

#endif

#ifndef PRINTVISITOR_H
#define PRINTVISITOR_H

#include "ExprVisitor.h"
#include "Literal.h"
#include "Negate.h"
#include "And.h"
#include "Or.h"
#include "Implication.h"
#include "Equivalence.h"
#include "Variable.h"

class PrintVisitor: public ExprVisitor
{
public:
	virtual void visitLiteral( Literal* lit)
	{
		std::cout << lit->getLiteral();
	};

	virtual void visitVariable( Variable* var);
	/*{
		if( var->getVarStr() != "GotValue")
        {
            std::cout << var->getVarStr();
        }
        else
        {
            std::cout << var->getVar();
        }
	};*/
	
	virtual void visitNegate( Negate* neg);
	/*{
        std::cout << "~(";
		neg->getOperand()->accept(this);
        std::cout << ")";
	};*/

	virtual void visitAnd( And* and1);
	/*{
		std::cout << "(";
		and1->getLeftOperand()->accept(this);
		std::cout << "&";
		and1->getRightOperand()->accept(this);
		std::cout << ")";
	};*/
	
	virtual void visitOr( Or* or1);
	/*{
		std::cout << "(";
		or1->getLeftOperand()->accept(this);
		std::cout << "|";
		or1->getRightOperand()->accept(this);
		std::cout << ")";
	};*/
	
	virtual void visitImplication( Implication* imp);
	/*{
		std::cout << "(";
		imp->getLeftOperand()->accept(this);
		std::cout << ">";
		imp->getRightOperand()->accept(this);
		std::cout << ")";
	};*/
	
	virtual void visitEquivalence( Equivalence* equal);
	/*{
		std::cout << "(";
		equal->getLeftOperand()->accept(this);
		std::cout << "=";
		equal->getRightOperand()->accept(this);
		std::cout << ")";
	};*/
	
};




#endif

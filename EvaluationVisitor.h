#ifndef EVALUATIONVISITOR_H
#define EVALUATIONVISITOR_H

#include <stack>
#include "ExprVisitor.h"
#include "Literal.h"
#include "Negate.h"
#include "And.h"
#include "Or.h"
#include "Implication.h"
#include "Negate.h"

class EvaluationVisitor: public ExprVisitor {

private:

    std::stack <bool> m_stack;

public:

    //bool getValue() {return  m_stack.top(); m_stack.pop();};
    bool getValue();
    /*{
        bool result = m_stack.top();
        m_stack.pop();
        return result;
    }*/

    virtual void visitLiteral (Literal* lit); //{m_stack.push(lit->getLiteral());};

    virtual void visitVariable (Variable* var);
    /*{
        m_stack.push(var->getBoolVal());
    };*/

    virtual void visitNegate (Negate* neg); /*{

       neg->getOperand()->accept(this);

       bool val = m_stack.top(); m_stack.pop();
       
       if( val == 0)
       {
           val = 1;
       }
       
       else
       {
           val = 0;
       }
       
       m_stack.push(val);

   };*/

    virtual void visitOr (Or* o); /*{

       o->getLeftOperand()->accept(this);

       o->getRightOperand()->accept(this);

       bool rval = m_stack.top(); m_stack.pop();

       bool lval = m_stack.top(); m_stack.pop();

       m_stack.push(lval + rval);

   };*/

   

    virtual void visitAnd (And* a);
    /*{
       a->getLeftOperand()->accept(this);

       a->getRightOperand()->accept(this);

       bool rval = m_stack.top(); m_stack.pop();

       bool lval = m_stack.top(); m_stack.pop();

       m_stack.push(lval * rval);

   };*/

   

    virtual void visitImplication (Implication* imp); /*{

       imp->getLeftOperand()->accept(this);

       imp->getRightOperand()->accept(this);

       bool rval = m_stack.top(); m_stack.pop();

       bool lval = m_stack.top(); m_stack.pop();
       
       /*This is equivalent to ~X|Y */
       
       /*if( lval == false)
       {
           lval = true;
       }
       
       else
       {
           lval = false;
       }
       
       bool result = rval + lval;
       
       m_stack.push(result);
       

       //m_stack.push(lval > rval);

   };*/

   

    virtual void visitEquivalence (Equivalence* eq); /*{

       eq->getLeftOperand()->accept(this);

       eq->getRightOperand()->accept(this);

       bool rval = m_stack.top(); m_stack.pop();

       bool lval = m_stack.top(); m_stack.pop();
       
       bool result = rval == lval;
       

       m_stack.push(result);
	};*/

};

#endif

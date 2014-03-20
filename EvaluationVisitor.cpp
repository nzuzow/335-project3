#include <iostream>
#include "EvaluationVisitor.h"

using namespace std;

bool EvaluationVisitor::getValue()
{
    bool result = m_stack.top();
    m_stack.pop();
    return result;
}

void EvaluationVisitor::visitLiteral(Literal* lit)
{
    m_stack.push(lit->getLiteral());
}

void EvaluationVisitor::visitVariable(Variable* var)
{
    m_stack.push(var->getBoolVal());
}

void EvaluationVisitor::visitNegate(Negate* neg)
{
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
}

void EvaluationVisitor::visitOr(Or* o)
{
    o->getLeftOperand()->accept(this);
    
    o->getRightOperand()->accept(this);
    
    bool rval = m_stack.top();
    m_stack.pop();
    
    bool lval = m_stack.top();
    m_stack.pop();
    
    m_stack.push(lval + rval);
}

void EvaluationVisitor::visitAnd (And* a)
{
    a->getLeftOperand()->accept(this);
    
    a->getRightOperand()->accept(this);
    
    bool rval = m_stack.top();
    m_stack.pop();
    
    bool lval = m_stack.top();
    m_stack.pop();
    
    m_stack.push(lval * rval);
}

void EvaluationVisitor::visitImplication (Implication* imp)
{
    imp->getLeftOperand()->accept(this);
    
    imp->getRightOperand()->accept(this);
    
    bool rval = m_stack.top(); m_stack.pop();
    
    bool lval = m_stack.top(); m_stack.pop();
    
    /*This is equivalent to ~X|Y */
    
    if( lval == false)
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
}

void EvaluationVisitor::visitEquivalence ( Equivalence* eq)
{
    eq->getLeftOperand()->accept(this);
    
    eq->getRightOperand()->accept(this);
    
    bool rval = m_stack.top(); m_stack.pop();
    
    bool lval = m_stack.top(); m_stack.pop();
    
    bool result = rval == lval;
    
    
    m_stack.push(result);
}











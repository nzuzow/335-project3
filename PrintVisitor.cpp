#include <iostream>
#include "PrintVisitor.h"

using namespace std;

void PrintVisitor::visitVariable( Variable* var)
{
    if( var->getVarStr() != "GotValue")
    {
        cout << var->getVarStr();
    }
    else
    {
        cout << var->getVar();
    }
}

void PrintVisitor::visitNegate( Negate* neg)
{
    cout << "~";
    neg->getOperand()->accept(this);
    //cout << ")";
}

void PrintVisitor::visitAnd( And* and1)
{
    cout << "(";
    and1->getLeftOperand()->accept(this);
    cout << "&";
    and1->getRightOperand()->accept(this);
    cout << ")";
}

void PrintVisitor::visitOr( Or* or1)
{
    cout << "(";
    or1->getLeftOperand()->accept(this);
    cout << "|";
    or1->getRightOperand()->accept(this);
    cout << ")";
}

void PrintVisitor::visitImplication( Implication* imp)
{
    cout << "(";
    imp->getLeftOperand()->accept(this);
    cout << ">";
    imp->getRightOperand()->accept(this);
    cout << ")";
}

void PrintVisitor::visitEquivalence( Equivalence* equal)
{
    cout << "(";
    equal->getLeftOperand()->accept(this);
    cout << "=";
    equal->getRightOperand()->accept(this);
    cout << ")";
}





#ifndef SIMPLIFYVISITOR_H
#define SIMPLIFYVISITOR_H

#include "ExprVisitor.h"
#include "Literal.h"
#include "Negate.h"
#include "And.h"
#include "Or.h"
#include "Implication.h"
#include "Equivalence.h"
#include "Variable.h"

class SimplifyVisitor: public ExprVisitor
{
public:
    virtual void visitLiteral( Literal* lit)
    {
        std::cout << lit->getLiteral();
    };
    
    virtual void visitVariable( Variable* var);
    /*{
        if (var->getVarStr() != "GotValue")
        {
            std::cout << var->getVarStr();
        }
        else
        {
            std::cout << var->getVar();
        }
    };*/
    
    virtual void visitNegate( Negate* neg);
    
    
    virtual void visitAnd( And* and1);
    /*{
        if (and1->getLeftOperand()->getType() != "lit" and and1->getRightOperand()->getType() != "lit") // dont want to simplify yet.
        {
            if (and1->getLeftOperand()->compute() == true)
            {
                //cout << endl << "Simplifies to: " << endl;
                and1->getRightOperand()->accept(this);
            }
            else if (and1->getRightOperand()->compute() == true)
            {
                //cout << endl << "Simplifies to: " << endl;
                and1->getLeftOperand()->accept(this);
            }
            
            else if (and1->getLeftOperand()->getType() == "lit" and and1->getLeftOperand()->compute() == false)
            {
                cout << endl << "Simplifies to: " << endl <<"false";
            }
            else if (and1->getRightOperand()->getType() == "lit" and and1->getRightOperand()->compute() == false)
            {
                cout << endl << "Simplifies to: " << endl <<"false";
            }
            else {} // does not simplify
            
            cout << "(";
            and1->getLeftOperand()->accept(this);
            cout << " & ";
            and1->getRightOperand()->accept(this);
            cout << ")";
            
        }
        else if (and1->getLeftOperand()->compute() == true)
        {
            //cout << endl << "Simplifies to: " << endl;
            and1->getRightOperand()->accept(this);
        }
        else if (and1->getRightOperand()->compute() == true)
        {
            //cout << endl << "Simplifies to: " << endl;
            and1->getLeftOperand()->accept(this);
        }
        else if (and1->getLeftOperand()->getType() == "lit" and and1->getLeftOperand()->compute() == false)
        {
            //cout << endl << "Simplifies to: " << endl;
            and1->getLeftOperand()->accept(this);
            
        }
        else if (and1->getRightOperand()->getType() == "lit" and and1->getRightOperand()->compute() == false)
        {
            //cout << endl << "Simplifies to: " << endl;
            and1->getRightOperand()->accept(this);
        }
        else {} // does not simplify
        
    };*/
    
    virtual void visitOr( Or* or1);
    
    virtual void visitImplication( Implication* imp);
    //{
        /*if (imp->getLeftOperand()->getType() != "lit" and imp->getRightOperand()->getType() != "lit") // dont want to simplify yet.
        {*/
            
            /*cout << "(";
             and1->getLeftOperand()->accept(this);
             cout << " & ";
             and1->getRightOperand()->accept(this);
             cout << ")";*/
            
            //cout << "left type1: " << and1->getLeftOperand()->getType() << endl;
            //cout << "right type1: " << and1->getRightOperand()->getType() << endl;
            
            /*if (imp->getLeftOperand()->compute() == true)
            {
                //cout << endl << "Simplifies to: " << endl;
                imp->getRightOperand()->accept(this);
            }
            else if (imp->getRightOperand()->compute() == true)
            {
                //cout << endl << "Simplifies to: " << endl;
                imp->getLeftOperand()->accept(this);
            }
            else if (imp->getLeftOperand()->getType() == "lit" and imp->getLeftOperand()->compute() == false)
            {
                cout << endl << "Simplifies to: " << endl <<"false";
            }
            else if (imp->getRightOperand()->getType() == "lit" and imp->getRightOperand()->compute() == false)
            {
                cout << endl << "Simplifies to: " << endl <<"false";
            }
            
            else {} // does not simplify
            
            cout << "(";
            imp->getLeftOperand()->accept(this);
            cout << " & ";
            imp->getRightOperand()->accept(this);
            cout << ")";
            
        }
        
        else if (imp->getLeftOperand()->compute() == true)
        {
            //cout << endl << "Simplifies to: " << endl;
            imp->getRightOperand()->accept(this);
        }
        else if (imp->getRightOperand()->compute() == true)
        {
            //cout << endl << "Simplifies to: " << endl;
            imp->getLeftOperand()->accept(this);
        }
        else if (imp->getLeftOperand()->getType() == "lit" and imp->getLeftOperand()->compute() == false)
        {
            //This should equaluate to True
            //cout << endl << "Simplifies to: " << endl <<"false";
            //imp->;
        }
        else if (imp->getRightOperand()->getType() == "lit" and imp->getRightOperand()->compute() == false)
        {
            //return ~ left operand
            imp->getLeftOperand()->compute() = !imp->getLeftOperand()->compute();
            imp->getLeftOperand()->accept(this);
            //cout << endl << "Simplifies to: " << endl <<"false";
        }
        
        else {} // does not simplify*/
    //};
    
    virtual void visitEquivalence( Equivalence* equal);
    /*{
        if (equal->getLeftOperand()->getType() != "lit" and equal->getRightOperand()->getType() != "lit") // dont want to simplify yet.
        {
            cout << "(";
            equal->getLeftOperand()->accept(this);
            cout << " & ";
            equal->getRightOperand()->accept(this);
            cout << ")";
        }
    };*/
    
    
    
    
};








#endif
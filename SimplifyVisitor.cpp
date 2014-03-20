#include <iostream>
#include "SimplifyVisitor.h"

using namespace std;

void SimplifyVisitor::visitVariable( Variable* var)
{
    if (var->getVarStr() != "GotValue")
    {
        cout << var->getVarStr();
    }
    else
    {
        cout << var->getVar();
    }
}

void SimplifyVisitor::visitNegate( Negate* neg)
{
    if (neg->getOperand()->getType() == "lit")
    {
        neg->getOperand()->accept(this);
    }
    else if (neg->getOperand()->getType() == "var")
    {
        cout << "~";
        neg->getOperand()->accept(this);
    }
    else
    {
        cout << "~";
    }

}

void SimplifyVisitor::visitAnd( And* and1)
{
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
            //cout << endl << "Simplifies to: " << endl <<"false";
            cout << endl << "false" << endl;
        }
        else if (and1->getRightOperand()->getType() == "lit" and and1->getRightOperand()->compute() == false)
        {
            //cout << endl << "Simplifies to: " << endl <<"false";
            cout << endl << "false" << endl;
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
    
}

void SimplifyVisitor::visitOr( Or* or1)
{
    //cout << "left type : " << or1->getLeftOperand()->getType() << endl;
    //cout << "right type : " << or1->getRightOperand()->getType() << endl;

    if (or1->getLeftOperand()->getType() != "lit" and or1->getRightOperand()->getType() != "lit") // dont want to simplify yet.
    {
        if (or1->getLeftOperand()->compute() == true)
        {
        //cout << "7" << endl;
        //or1->getLeftOperand()->accept(this);
        cout << endl << "Simplifies to: " << endl <<"true";

        }
        else if (or1->getRightOperand()->compute() == true)
        {
        //cout << "6" << endl;
        or1->getRightOperand()->accept(this);
        }
        /*else if (or1->getLeftOperand()->compute() == false)
        {
            //if (or1->getLeftOperand()->getType() == "var")
            //{

            //cout << "5" << endl;
            //or1->getLeftOperand()->accept(this);
            }
         }
        
        else if (or1->getRightOperand()->compute() == false)
        {
            //or1->getRightOperand()->accept(this);
            //cout << "4" << endl;
        }*/


        else
        {
            cout << "(";
            or1->getLeftOperand()->accept(this);
            cout << " | ";
            or1->getRightOperand()->accept(this);
            cout << ")";
        }


    }
    else if (or1->getLeftOperand()->compute() == true)
    {
        //cout << "3" << endl;
        or1->getLeftOperand()->accept(this);
    }
    else if (or1->getRightOperand()->compute() == true)
    {
        //cout << "2" << endl;
        or1->getRightOperand()->accept(this);
    }
    else if (or1->getLeftOperand()->getType() == "lit" and or1->getLeftOperand()->compute() == false)
    {
        //cout << "fish" << endl;
        or1->getRightOperand()->accept(this);
    }
    else if (or1->getRightOperand()->getType() == "lit" and or1->getRightOperand()->compute() == false)
    {
        or1->getLeftOperand()->accept(this);
    }
    else
    {
    } //do nothing

    /*cout << "(";
    or1->getLeftOperand()->accept(this);
    cout << " | ";
    or1->getRightOperand()->accept(this);
    cout << ")";*/

}

void SimplifyVisitor::visitImplication( Implication* imp)
{
    if (imp->getLeftOperand()->getType() != "lit" and imp->getRightOperand()->getType() != "lit") //neither is lit, so you have either imps or vars
    {
        if (imp->getLeftOperand()->getType() != "var") //checking for imp/and/or/negate it will get broken down again recursively
        {
            imp->getLeftOperand()->accept(this);
        }
        else if (imp->getRightOperand()->getType() != "var") //ditto
        {
            imp->getRightOperand()->accept(this);
        }
        else if (imp->getLeftOperand()->getType() == "var" and imp->getRightOperand()->getType() == "var")//cannot be simplified, so print dat shit
        {
            cout << "(";
            imp->getLeftOperand()->accept(this);
            cout << " > ";
            imp->getRightOperand()->accept(this);
            cout << ")";
        }
    }
    
    //now you have at least 1 lit, so you can simplify
    else if ( imp->getLeftOperand()->getType() == "lit")
    {
        if (imp->getLeftOperand()->compute() == 0) // should return true in any case
        {
            cout << "simplifies to: True" << endl; //need to be done here
        }
        else // (imp->getLeftOperand()->compute() == 1)
        {
            //if the right operand is a lit0 return FALSE
            if(imp->getRightOperand()->getType() == "lit" and imp->getLeftOperand()->compute() == 0)
            {
                cout << "simplifies to: False" << endl; //need to be done here
            }
            else //else it is an imp/and/or/negate or a var so we return the right operand IF its an imp/and/or/negate, if its a var then we're done.
            {
                if (imp->getRightOperand()->getType() == "var") //its 1 --> var which is == var, so print var
                {
                    cout << "simplifies to: ";
                    imp->getRightOperand()->accept(this);
                }
                else // must be and/or/imp/negate type so keep going
                {
                    imp->getRightOperand()->accept(this);
                }
            }
        }
    }
    else if ( imp->getRightOperand()->getType() == "lit") // right operand must be a lit, left operand is not
    {
        if (imp->getRightOperand()->compute() == 1) // should return true in any case
        {
            cout << "simplifies to: " << endl; //need to be done here
        }
        else // right is 0
        {
            if (imp->getLeftOperand()->getType() == "var") // its var --> 0, so depends on the var
            {
                cout << "simplifies to: ";
                imp->getLeftOperand()->accept(this);
            }
            else  // left operand is not a lit or a var. so it is an imp/and/or/negate. need to return
            {
                imp->getLeftOperand()->accept(this);
            }
        }
    }

}

void SimplifyVisitor::visitEquivalence( Equivalence* equal)
{
    if ( equal->getLeftOperand()->getType() != "var" and equal->getLeftOperand()->getType() != "lit") // left is neg/imp/and/or/etc
    {
        equal->getLeftOperand()->accept(this);
    }
    else if ( equal->getRightOperand()->getType() != "var" and equal->getRightOperand()->getType() != "lit") // right is neg/imp/and/or/etc
    {
        equal->getRightOperand()->accept(this);
    }
    else //hopefully left and right are both either vars or lits
    {
        cout << "(";
        equal->getLeftOperand()->accept(this);
        cout << " = ";
        equal->getRightOperand()->accept(this);
        cout << ")";
    }

}




















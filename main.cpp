using namespace std;


#include <iostream>

#include "Expr.h"
#include "Literal.h"
#include "Variable.h"
#include "Negate.h"
#include "And.h"
#include "Or.h"
#include "Implication.h"
#include "Equivalence.h"
#include "EvaluationVisitor.h"
#include "PrintVisitor.h"
#include "SimplifyVisitor.h"


int main()
{

    /*Expr* ex= new And(new Literal(true), new Literal(false));

    Expr* ex2 = new Or(new Literal(true), new Literal(false));

    Expr* eximp = new Implication(ex, ex2);
    
    Expr* exnot = new Negate(ex2);
    
    Expr* exequal = new Equivalence(exnot, new Literal(true));
    
    Expr* exvar = new Negate(new Or(new Variable("salad"), new And(new Variable("x"), new Variable("y"))));*/
    
    Expr* exsimp = new And(new And(new Literal(true), new Literal(false)), new Variable("X"));
    Expr* eximp = new Equivalence(new Implication(new And(new Variable("x"), new Literal(true)), new Or(new Literal(false), new Variable("y"))), new Variable("z"));
    
    EvaluationVisitor ev;
    PrintVisitor pv;
    SimplifyVisitor sp;
    /*
    //call accept of And
    ex->accept(&ev);
    ex->accept(&pv);

    cout << endl;
    cout << ex->compute() << endl;
    
    //call accept of Or
    ex2->accept(&ev);
    ex2->accept(&pv);
    
    cout << endl;
    cout << ex2->compute() << endl;
    
    //call accept of Implication
    eximp->accept(&ev);
    eximp->accept(&pv);
    
    cout << endl;
    cout << eximp->compute() << endl;
    
    //call accept of Equivalence
    exequal->accept(&ev);
    exequal->accept(&pv);
    
    cout << endl;
    cout << exequal->compute() << endl;
    
    //call accept of Variable
    exvar->accept(&pv);
    exvar->accept(&ev);
    exvar->accept(&pv);
    
    cout << endl;
    cout << exvar->compute() << endl;
    
    */
    
    //call accept of And with simplify
    //exsimp->accept(&pv);
    exsimp->accept(&pv);
    cout << endl;
    cout << "Simplified version: ";
    exsimp->accept(&sp);
    exsimp->accept(&ev);
    //exsimp->accept(&pv);
    
    cout << endl;
    cout << "Evaluation Result: " << endl;
    cout << exsimp->compute() << endl;
    
    //for test case 2.1
    eximp->accept(&pv);
    cout << endl;
    cout << "Simplified version: ";
    eximp->accept(&sp);
    eximp->accept(&ev);
    //exsimp->accept(&pv);
    
    cout << endl;
    cout << "Evaluation Result: " << endl;
    cout << eximp->compute() << endl;
    
    delete eximp;
    cout << endl;
}

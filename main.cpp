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


int main()
{

Expr* ex= new And(new Literal(true), new Literal(true));

cout << ex->compute() << endl;

EvaluationVisitor ev;
PrintVisitor pv;
ex->accept(&ev);
ex->accept(&pv);

delete ex;
cout << endl;
}

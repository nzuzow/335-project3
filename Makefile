project3: main.o And.o BoolExpr.o EvaluationVisitor.o Equivalence.h\
    Implication.o Negate.o Or.o PrintVisitor.o Variable.o SimplifyVisitor.o\
    Expr.h ExprVisitor.h
	g++ main.o -o project3
main.o: main.cpp
	g++ -c main.cpp
And.o: And.cpp And.h
	g++ -c And.cpp
BoolExpr.o: BoolExpr.cpp BoolExpr.h
	g++ -c BoolExpr.cpp
EvaluationVisitor.o: EvaluationVisitor.cpp EvaluationVisitor.h
	g++ -c EvaluationVisitor.cpp
Implication.o: Implication.cpp Implication.h
	g++ -c Implication.cpp
Negate.o: Negate.cpp Negate.h
	g++ -c Negate.cpp
Or.o: Or.cpp Or.h
	g++ -c Or.cpp
PrintVisitor.o: PrintVisitor.cpp PrintVisitor.h
	g++ -c PrintVisitor.cpp
Variable.o: Variable.cpp Variable.h
	g++ -c Variable.cpp
SimplifyVisitor.o: SimplifyVisitor.cpp SimplifyVisitor.h
	g++ -c SimplifyVisitor.cpp
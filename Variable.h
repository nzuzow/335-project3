#ifndef VARIABLE_H
#define VARIABLE_H

#include "Expr.h"
#include "ExprVisitor.h"

class Variable: public Expr{

private:

   bool m_var;

   std::string m_str;

public:  

   Variable (std::string str) {m_str = str;};

   ~Variable ();

   bool Assign(bool var) {m_var = var;};

   bool getVar() {return m_var;};

   bool getBoolVal(std::string str);

   

   virtual bool compute() {return m_var;};

   

   

   virtual void accept(ExprVisitor* v) { v->visitVariable(this); };
};





#endif

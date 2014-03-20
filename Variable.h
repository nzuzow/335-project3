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
    
    /*Test to allow us to see if its a variable or literal*/
    std::string getType() {return "var";};
    
    std::string getVarStr() {return m_str;};
    
    bool getBoolVal();
    /*{
        std::cout << std::endl << "Enter boolean value for " << m_str << ": ";
        bool variable;
        cin >> variable;
        Assign(variable); //pointer get__operand() switches to correct variable
        m_str = "GotValue";
        return variable;
    };*/


    virtual bool compute() {return m_var;};
   

    virtual void accept(ExprVisitor* v) { v->visitVariable(this); };
};





#endif

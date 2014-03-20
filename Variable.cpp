#include <iostream>
#include "Variable.h"

using namespace std;


bool Variable::getBoolVal (std::string str)

{

   cout << "Enter boolean value for " << str << ": ";

   bool variable;

   cin >> variable;
    
    Assign(variable);
    
    m_str = "GotValue";

   return variable;

}

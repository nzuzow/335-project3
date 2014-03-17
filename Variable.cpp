#include "Variable.h"


/*bool Variable::Variable (std::string var)

{

   cout << "Enter boolean value for " << var << ": ";

   bool variable;

   cin >> variable;

}*/


bool Variable::getBoolVal (std::string str)

{

   cout << "Enter boolean value for " << str << ": ";

   bool variable;

   cin >> variable;

   return variable;

}

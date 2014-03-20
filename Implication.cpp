#include <iostream>
#include "Implication.h"

using namespace std;

bool Implication::compute()
{
    bool lop = getLeftOperand()->compute();
    
    bool rop = getRightOperand()->compute();
    
    //implication is equivalent to ~x|y
    
    if( lop == false)
    {
        lop = true;
    }
    else
    {
        lop = false;
    }
    
    bool result = rop + lop;
    
    return result;
    //return (lop > rop);
}
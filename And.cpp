#include <iostream>
#include "And.h"

using namespace std;

bool And::compute()
{
    bool lop = getLeftOperand()->compute();
    
    bool rop = getRightOperand()->compute();
    
    return (lop*rop);
}
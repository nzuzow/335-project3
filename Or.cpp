#include <iostream>
#include "Or.h"

using namespace std;

bool Or::compute()
{
    bool lop = getLeftOperand()->compute();
    
    bool rop = getRightOperand()->compute();
    
    return (lop + rop);
}
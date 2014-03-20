#include <iostream>
#include "Negate.h"

using namespace std;

bool Negate::compute()
{
    if( m_opPtr->compute() == 0)
    {
        return 1;
    }
    
    else
    {
        return 0;
    }
}
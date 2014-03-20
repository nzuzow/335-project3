using namespace std;

#include <iostream>
#include "BoolExpr.h"

BoolExpr::~BoolExpr()
{
    delete m_leftPtr;
    delete m_rightPtr;
}
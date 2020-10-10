#ifndef PARAMETER_H
#define PARAMETER_H

#include "Rule.h"
#include "Predicate.h"
#include <iostream>
#include <string>

class Parameter {
private:

public:
	Parameter(void) {}
	~Parameter(void) {}

	virtual bool setParameter(unsigned int& tracker, vector<Token> tokenList, bool& pass) = 0;

	
	virtual string toString() = 0;
};

#endif
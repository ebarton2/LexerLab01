#pragma once
#include "Parameter.h"
#include "Predicate.h"
#include "DatalogProgram.h"
#include "SimplePara.h"
#include "ExpressionPara.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Rule{
private:
	Predicate headPredicate;
	vector<Predicate> predicateList;

public:
	Rule(void) {};
	~Rule(void) {};

	bool setRule(unsigned int& tracker, vector<Token> tokenList, bool& pass) {
		if ((&tokenList.at(tracker) != NULL) && tokenList.at(tracker).getTokenCode() == 13) {
			headPredicate.setPredicateScheme(tracker, tokenList, pass);
			//++tracker;
		} // Checks for ID
		else {
			pass = false;
			return pass;
		}
		if ((tokenList.at(tracker).getTokenCode() != NULL) && tokenList.at(tracker).getTokenCode() == 6) { 
			++tracker;
		}// Checks for COLON_DASH
		else {
			pass = false;
			return pass;
		}

		if ((tokenList.at(tracker).getTokenCode() != NULL) && tokenList.at(tracker).getTokenCode() == 13) { // Checks for ID
			while ((&tokenList.at(tracker) != NULL) && (tokenList.at(tracker).getTokenCode() != 1)) { // While it isn't a PERIOD
				Predicate tempPredicate;
				if ((&tokenList.at(tracker) != NULL) && (tempPredicate.setPredicate(tracker, tokenList, pass))) {
					predicateList.push_back(tempPredicate);
					++tracker;
					if ((&tokenList.at(tracker) != NULL) && (tokenList.at(tracker).getTokenCode() == 0)) {
						++tracker;
						continue;
					}
					else if ((&tokenList.at(tracker) != NULL) && (tokenList.at(tracker).getTokenCode() == 1)) {
						++tracker;
						break;
					}
				}
				else { // Double check, might be wrong
					pass = false;
					return pass;
				}
			}
		}
		else {
			pass = false;
			return pass;
		}
		return pass;
	}

};
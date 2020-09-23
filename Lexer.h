#ifndef LEXER_H
#define LEXER_H
using namespace std;
#include "Tokenizer.h"
#include "Token.h"
#include <string>
#include <vector>
#include <iostream>

class Lexer
{
private:
	vector<Token> tokens;
	string inputString;
	int line;
	int tokenCount;
	Tokenizer myTokenizer;
public:
	Lexer() { line = 0; tokenCount = 0; }
	~Lexer() {}

	void getTokens(string& input, int& lineNum) { // Generate Tokens from input
		inputString = input;
		line = lineNum;

		while (input.size() > 0) {
			if (input[0] == '\n') {
				input = input.substr(1, input.size() - 1);
				++lineNum;
				line = lineNum;
			}
			else if (input[0] == ' ') {
				input = input.substr(1, input.size() - 1);
			}
			else if (input[0] == '\t') {
				input = input.substr(1, input.size() - 1);
			}
			else {
				tokens.push_back(myTokenizer.getNextToken(input, lineNum));
				++tokenCount;
			}
		}


	}

	void endOfFile() {
		++tokenCount;
		tokens.push_back(myTokenizer.endOfTimes(line));
	}

	void printTokens() {
		for (unsigned int i = 0; i < tokens.size(); ++i) {
			cout << tokens.at(i).toString() << endl;
		}
		cout << "Total Tokens = " << to_string(tokenCount) << endl;
	}
};
#endif

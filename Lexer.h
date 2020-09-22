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
	string input;
	int line;
	int tokenCount;
public:
	Lexer() { line = 0; tokenCount = 0; }
	~Lexer() {}

	void setLine(string& input, int& line) {
		this->input = input;
		this->line = line;
	}

	void getTokens() { // Generate Tokens from input
		Tokenizer myTokenizer(input, line);
		do {
			if (input[0] == '\n') {
				input = input.substr(1, input.size() - 1);
				++line;
			}
			else if (isspace(input[0])) {
				input = input.substr(1, input.size() - 1);
			}
			else {
				tokens.push_back(myTokenizer.getNextToken(input, line));
				++tokenCount;
			}
		} while (input.size() > 0);
	}

	void endOfFile() {
		++tokenCount;
		//++line;
		string tempString = "";
		Tokenizer caller(tempString, line);
		tokens.push_back(caller.endOfTimes(tempString, line));
	}

	void printTokens() {
		for (unsigned int i = 0; i < tokens.size(); ++i) {
			cout << tokens.at(i).toString() << endl;
		}
		cout << "Total Tokens = " << to_string(tokenCount) << endl;
	}
};
#endif

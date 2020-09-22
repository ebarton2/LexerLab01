#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>

#include "Lexer.h"
using namespace std;

int main(int argc, char* argv[]) {
	VS_MEM_CHECK;
	//cout << "Input file: " << argv[1] << endl;
	ifstream in(argv[1]);
	if (!in) {
		cerr << "Unable to open " << argv[1] << " for input";
		return 2;
	}

	int lineNum = 1;

	Lexer myLexer;
	string line;
	string tempLine;

	while (getline(in, tempLine)) {
		if (in.eof()) {
			line = line + tempLine;
		}
		else {
			line = line + tempLine;
			line.push_back('\n');
		}
	}
	myLexer.setLine(line, lineNum);
	myLexer.getTokens();
	myLexer.endOfFile();
	myLexer.printTokens();

	return 0;
}
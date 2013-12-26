#ifndef SCANNER_H 
#define SCANNER_H 
/** 
 * Scanner class that scan given expression  
 * for tokens. 
 */ 
class Scanner 

{

	public: 
		//Requests next token for parsing
		const char *getNextToken(); 
		//scans given expression for tokens 
		void scanExpression(char*); 

	private: 
		//Returns true if token is "\n" or " " 
		bool isEmpty(char); 
		//Checks if given token is operator
		bool isOperator(char); 
                bool isParentheses(char); 
		bool isDigit(char); 
		//Checks if operator consists of two signs (e.g. <=) 
		bool isTwoSignOperator(char*); 
		const char*  stream; 

}; 
#endif 

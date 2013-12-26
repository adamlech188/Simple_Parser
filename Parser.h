#ifndef PARSER_H 
#define PARSER_H 
#include "Scanner.h" 
/**
 * Structure that holds the subtotal and value 
 * of given expression in the parse tree. 
 */ 
struct expr { 
	int st; 
	int val; 
};  
/*
 * Parser class that evaluates tokens 
 * provided by scanner.  
 */
class Parser { 

	public: 

		void connect_Scanner(Scanner); 
		//evalutes expression passed down by the scanner
	 	void evaluate_expression(); 
		//value of given expression
		int getExpression_Value(); 

	private: 
		Scanner scanner; 
		void evaluate_S(struct expr*, char*); 
                void evaluate_A(struct expr*, char*); 
                void evaluate_B(struct expr*, char*); 
		void evaluate_D(struct expr*, char*); 
		void evaluate_E(struct expr*, char*); 
		void evaluate_F(struct expr*, char*); 
		//gets integer value for F statement
                int integer_value(char*); 
}; 
#endif 

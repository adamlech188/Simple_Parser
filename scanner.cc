#include "Scanner.h" 
#include <stdio.h>
#include <string.h>
void Scanner::scanExpression(char* expr) { 

    stream = expr; 
} 
const char* Scanner::getNextToken() 
{   
	char *token =new char[2] ; 
	strncpy(token , stream, 2);  
	if(isTwoSignOperator(token)) { 
		stream = stream +2; 
		return token; 
	}
	else { 
		if(isDigit(token[0]))
		{ 
			token[1] ='\0'; 
			++stream; 
			return token;  
		}
		else if(isOperator(token[0])) 
		{ 
			token[1] = '\0'; 
			++stream; 
			return token; 
		} 
		else if(isParentheses(token[0])) 
		{
			token[1] = '\0'; 
			++stream; 
			return token; 
		}
		else if (isEmpty(token[0])) 
		{ 
			delete token; 
			return ""; 
		} 
		else { 

			fprintf(stderr, "%s is not a valid token\n", token); 
			return NULL; 
		} 


	} 
	return stream; 
} 
bool Scanner::isEmpty(char c) 
{ 
	if(c == '\n' || c == '\t' || c == ' ' || c =='\0' ) 
	{ 
		return true; 
	} 
	return false;  
} 
bool Scanner::isOperator(char c) 
{ 
	switch(c) 
	{ 
		case '!': 
			return true; 
		case '>': 
			return true; 
		case '<':
			return true; 
		default:
			return false; 

	} 
} 
bool Scanner::isParentheses(char c) 
{
	if(c == '(' ||  c ==')') 
		return true; 
	return false; 
} 
bool Scanner::isDigit(char c) 
{
	switch(c) 
	{ 
		case '0':
			return true;  
		case '1':
			return true;  
		case '2':
			return true;  
		case '3':
			return true;  
		case '4':
			return true;  
		case '5':
			return true;  
		case '6':
			return true;  
		case '7':
			return true;  
		case '8':
			return true;  
		case '9':
			return true;  

		default:  
			return false; 
	}

}
bool Scanner::isTwoSignOperator(char* op) 
{ 
	if(strcmp(op,"!=")==0) 
		return true; 

	if(strcmp(op,"==")==0) 
		return true; 

	if(strcmp(op,"<=")==0) 
		return true; 

	if(strcmp(op,">=")==0) 
		return true; 
	if(strcmp(op,"||")==0) 
		return true; 
	if(strcmp(op,"&&")==0) 
		return true; 
	return false; 
} 

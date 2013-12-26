#include "Parser.h" 
#include <string.h> 
#include <stdlib.h>
int Integer_Value; 
void Parser::connect_Scanner(Scanner scanner) 
{ 
	Parser::scanner =scanner; 
} 
void Parser::evaluate_expression() 
{ 
	struct expr *S = new struct expr; 
	char *currToken = (char*)scanner.getNextToken(); 
	evaluate_S(S, currToken); 
	Integer_Value = S->val; 
} 
int Parser::getExpression_Value() 
{ 

	return Integer_Value; 
} 
void Parser::evaluate_S(struct expr* S_expr, char *currToken) 
{ 
	if(strlen(currToken)==0) 
	{ 
		S_expr->val = S_expr->st; 
	} 
	else if(strcmp("||" , currToken) == 0) { 
		struct expr *A = new struct expr; 
		struct expr *SS = new struct expr; 
		currToken = (char*) scanner.getNextToken(); 

		evaluate_A(A, currToken); 
		SS->st = S_expr->st || A->val; 
		currToken =(char*) scanner.getNextToken(); 
		evaluate_S(SS, currToken); 
		S_expr->val = SS->val; 

	} 
	else { 
		struct expr *A = new struct expr; 
		struct expr *SS = new struct expr; 
		evaluate_A(A, currToken); 
		currToken =(char*) scanner.getNextToken(); 
		SS->st = A->val; 	
		evaluate_S(SS, currToken); 
		S_expr->val = SS->val; 	
	} 

} 
void Parser::evaluate_A(struct expr* A_expr, char *currToken) 
{ 

	if(strlen(currToken) == 0) { 
		A_expr->val = A_expr->st; 
	} 
	else if(strcmp("&&" , currToken) == 0){ 
		struct expr *AA = new struct expr;  
		struct expr *B = new struct expr; 

		currToken = (char*) scanner.getNextToken(); 
		evaluate_B(B, currToken); 
		AA->st = A_expr->st&&B->val; 	
		currToken = (char*) scanner.getNextToken(); 
		evaluate_A(AA, currToken); 	
	} 
	else { 

		struct expr *B = new struct expr; 
		struct expr *AA = new struct expr; 
		evaluate_B(B , currToken); 
		currToken = (char*) scanner.getNextToken(); 
		AA->st = B->val; 
		evaluate_A(AA, currToken);  
		A_expr->val = AA->val;     	    
	} 

} 
void Parser::evaluate_B(struct expr* B_expr, char* currToken)
{ 
	if(strlen(currToken)==0) { 

		B_expr->val = B_expr->st; 
	} 
	else if(strcmp("!=", currToken) == 0) { 
		struct expr *D = new struct expr; 
		struct expr *BB = new struct expr; 

		currToken = (char*)scanner.getNextToken(); 
		evaluate_D(D, currToken); 
		BB->st = B_expr->st == D->val; 
		currToken = (char*)scanner.getNextToken(); 
		evaluate_B(BB,currToken); 	        	
		B_expr->val = BB->val; 

	} 

	else if(strcmp("==", currToken) == 0) { 
		struct expr *D = new struct expr; 
		struct expr *BB = new struct expr; 

		currToken = (char*)scanner.getNextToken(); 
		evaluate_D(D, currToken); 
		BB->st =  B_expr->st ==D->val; 
		currToken = (char*)scanner.getNextToken(); 
		evaluate_B(BB,currToken); 	        	
		B_expr->val = BB->val; 
	} 

	else  { 
		struct expr *D = new struct expr; 
		struct expr *BB = new struct expr; 

		evaluate_D(D, currToken); 
		BB->st =  D->val; 
		currToken = (char*)scanner.getNextToken(); 
		evaluate_B(BB,currToken); 	        	
		B_expr->val = BB->val; 
	} 

} 
void Parser::evaluate_D(struct expr *D_expr, char* currToken) 
{ 


	if(strlen(currToken)==0) { 
		D_expr->val = D_expr->st; 
	} 
	else if(strcmp(">", currToken) == 0) { 
		struct expr *E = new struct expr; 
		struct expr *DD = new struct expr; 

		currToken = (char*)scanner.getNextToken(); 
		evaluate_E(E, currToken); 
		DD->st = D_expr->st > E->val; 
		currToken = (char*)scanner.getNextToken(); 
		evaluate_D(DD,currToken); 	        	
		D_expr->val = DD->val; 

	} 
	else if(strcmp("<", currToken) == 0) { 
		struct expr *E = new struct expr; 
		struct expr *DD = new struct expr; 

		currToken = (char*)scanner.getNextToken(); 
		evaluate_E(E, currToken); 
		DD->st = D_expr->st <E->val;
		currToken = (char*)scanner.getNextToken(); 
		evaluate_D(DD,currToken); 	        	
		D_expr->val = DD->val; 

	} 
	else if(strcmp("<=", currToken) == 0) { 
		struct expr *E = new struct expr; 
		struct expr *DD = new struct expr; 

		currToken = (char*)scanner.getNextToken(); 
		evaluate_E(E, currToken); 
		DD->st = D_expr->st <= E->val; 
		currToken = (char*)scanner.getNextToken(); 
		evaluate_D(DD,currToken); 	        	
		D_expr->val = DD->val; 

	} 
	else if(strcmp(">=", currToken) == 0) { 
		struct expr *E = new struct expr; 
		struct expr *DD = new struct expr; 

		currToken = (char*)scanner.getNextToken(); 
		evaluate_E(E, currToken); 
		currToken = (char*)scanner.getNextToken(); 
		evaluate_D(DD,currToken); 	        	
		DD->st = D_expr->st >= E->val; 
		D_expr->val = DD->val; 

	} 

        else if(strcmp("==", currToken) == 0 || strcmp("!=" , currToken)==0) 
         { 
             evaluate_B(D_expr, currToken); 
	    
         } 
	else   { 
		struct expr *E = new struct expr; 
		struct expr *DD = new struct expr; 

		evaluate_E(E, currToken); 
		DD->st = E->val; 
		currToken = (char*)scanner.getNextToken(); 
		evaluate_D(DD,currToken); 	        	
		D_expr->val = DD->val; 
	} 
}
void Parser::evaluate_E(struct expr *E_expr, char *currToken) 
{ 
	if(strcmp("!" , currToken)==0) 
	{ 
		struct expr *E = new struct expr; 
		currToken = (char*)scanner.getNextToken(); 
		evaluate_E(E,currToken); 
		E_expr->val = !E->val; 
	} 
	else { 
		struct expr *F = new struct expr; 
		evaluate_F(F, currToken); 
		E_expr->val = F->val; 
	} 
} 
void Parser::evaluate_F(struct expr *F_expr, char *currToken) 
{ 
	if(strcmp(currToken, "(") == 0)
	{ 
		currToken = (char*)scanner.getNextToken(); 
		struct expr *S = new struct expr; 
		evaluate_S(S, currToken); 
		F_expr->val = S->val; 
	} 
	else { 

		F_expr->val = integer_value(currToken); 
	} 
} 
int Parser::integer_value(char *str) 
{ 

	return atoi(str); 

} 

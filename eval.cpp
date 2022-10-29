//***************************************************************************
//
//  eval.cpp
//  CSCI 241 Assignment 8 
//
//  Created by Noah Allen (z1888906)
//
//***************************************************************************
#include <iostream>
#include <string> 
#include <sstream>
#include "mystack.h"


using std::string;
using std::stringstream; 

//scans postfix string froom left to right.
int evaluate(const string& postfix)
{
	string op; 
	stringstream ss(postfix);
    int left_op, right_op;
    mystack eval_stack;

	while(ss >> op)
	{
		//if token id an integar, pushes him on eval_ stack.
		if (isdigit(op[0]))
		{
			eval_stack.push(stoi(op));
		}
		//if token is avriable, the value is calculated pushing value in eval_stack. 
		else if(islower(op[0]))
		{
			//will not reward points.
			eval_stack.push(op[0] - 'a');
		}
		//operator gets top item from eval stacj and pops applies the oterator pushig result to eval_stack.
		else if (op =="~")
		{
		    right_op = eval_stack.top();
            eval_stack.pop();
		    eval_stack.push(-right_op);

        }

		//if any other operator, obtain right operand by getting top item of the eval_stack and poping the stack.
	    else
	    {
		    right_op = eval_stack.top();
            eval_stack.pop();        
		    left_op = eval_stack.top();
            eval_stack.pop();
            int result;
        
            // Do the math
            if (op == "^")
            {
                result = 1;
                while (right_op > 0)
                {
                    result = result * left_op;
                    right_op--;
                }
            }

		     //checks for operands and repeats
            else if (op == "+")
            {
		        result = left_op + right_op; 
            }
            else if (op == "-")
            {
			    result = left_op - right_op; 
            }
            else if (op == "*")
            {
			    result = left_op * right_op; 
            }
		     else if (op == "/")
		     {
                if (right_op == 0)
                {
   			        std:: cout<< "*** Division by 0 ***\n";
                    result = 0;
                }
                else
                {
                    result = left_op / right_op; 
                }
            }
			
            eval_stack.push(result);
		}
    }
        return eval_stack.top();
}

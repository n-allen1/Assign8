//***************************************************************************
//
//  inpost.cpp
//  CSCI 241 Assignment 8
//
//  Created by Noah Allen (z1888906)
//
//***************************************************************************

#include"inpost.h"
#include"mystack.h"

/**
 * @brief The convert function takes a const string infix expression and returns a postfix expression
 * 
 * @param infix 
 * @return std::string a postfix expression
 */
std::string convert(const std::string& infix)
{
    mystack stack;
    stack.reserve(10);
    
    std::string output;
    size_t i = 0;
    
    while (i < infix.size())
    {
        if (isalpha(infix[i]))
        {
            output += infix[i];
            output += ' ';
            i++;
        }
        else if (isdigit(infix[i]))
        {
            while (isdigit(infix[i]))
            {
                output += infix[i];
                i++;
            }

            output += ' ';
        }
        else if (infix[i] == ' ')
        {
            i++;
        }
        else if (infix[i] == '(')
        {
            stack.push(infix[i]);
            i++;
        }
        else if (infix[i] == ')')
        {
            while (!stack.empty() && stack.top() != '(')
            {
                output += stack.top();
                output += ' ';
                stack.pop();
            }

            if (!stack.empty())
                stack.pop();

            i++;
        }
        else
        {
            while (!stack.empty() && precedence(infix[i]) <=
                precedence(stack.top()))
            {
                output += stack.top();
                output += ' ';
                stack.pop();
            }
            stack.push(infix[i]);
            i++;
        }
    }
    
    while (!stack.empty())
    {
        output += stack.top();
        output += ' ';
        stack.pop();
    }
    
    output.pop_back();

    return output;
}

/**
 * @brief Checks the precedence of operators
 * 
 * @param x 
 * @return int 
 */
int precedence(char x)
{
    switch(x)
    {
        case '+':
        case '-':
            return 1;
            
        case '*':
        case '/':
            return 2;
            
        case '^':
        case '~':
            return 3;
            
        default : 
            return 0;
    }
}
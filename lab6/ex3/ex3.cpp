/*

Menu driven program to convert infix expression to postfix and evaluate with
following options
1. Get Infix expression
2. Convert to Postfix
3. Evaluate Postfix Expression
4. Exit

*/

#include "sll.h"
#include <limits>
#include <iostream>

using namespace std;

int precedence(char);
string infixToPostfix(string);
int evalPostfix(string);

int main()
{
  int ch;
  string instr="",pstr="";
  do
  {
    cout<<"\n\tMENU\n1.Input infix expression\n2.Convert Infix to Postfix\n3.Evaluate postfix\n4.Exit\n";
    cout<<"Enter choice: ";
    cin>>ch;
    if (cin.fail())
      {
          cin.clear(); 
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Invalid input.\n";
          continue;
      }
    switch(ch)
    {
      case 1:
      {
        cout<<"Enter expression: ";
        cin>>instr;
        break;
      }
      case 2:
      {
        if (instr=="")
        {
          cout<<"Enter infix expression first.\n";
          break;
        }
        pstr=infixToPostfix(instr);
        cout<<pstr;
        break;
      }
      case 3:
      {
        if (pstr=="")
        {
          cout<<"Convert to postfix first.\n";
          break;
        }
        cout<<"Evaluated result is "<<evalPostfix(pstr)<< endl;
        break;
      }
      case 4:
      {
        cout<<"Exiting...\n";
        break;
      }
      default:
      {
        cout<<"Invalid input.\n";
      }
    }
  } while (ch!=4);
  
  return 0;
}

// returns number of precedence of operator, returns 0 for numbers
int precedence(char op)
{
  if (op == '=')
    return 1;
  if (op == '+' || op == '-')
    return 2;
  if (op == '*' || op == '/' || op == '%')
    return 3;
  return 0;
}

// Convert infix expression to postfix
// Returns postfix string
string infixToPostfix(string infix)
{
  stack s;
  string postfix = "";
  int len = infix.length();
  char ch;
  int i = 0;
  while (i < len)
  {
    ch = infix.at(i);
    if (ch == ' ')
    {
      i++;
      continue;
    }
    if (precedence(ch) == 0)
    {
      while (i < len && precedence(ch = infix.at(i)) == 0)
      {
        postfix += ch;
        i++;
      }
      postfix += ' ';
      continue;
    }
    else
    {
      while (!s.is_empty() && (precedence(ch) < precedence(s.peek())))
      {
        postfix += s.pop();
        postfix += ' ';
      }
      s.push(ch);
      i++;
    }
  }

  while (!s.is_empty())
  {
    postfix += s.pop();
    postfix += ' ';
  }

  return postfix;
}

// Evaluate a given postfix expression
// returns integer value of result
int evalPostfix(string postfix)
{
  stack s;
  int len = postfix.length();
  int i = 0;

  while (i < len)
  {
    char ch = postfix[i];

    if (ch == ' ')
    {
      i++;
      continue;
    }
    if (isdigit(ch))
    {
      int num = 0;
      while (i < len && isdigit(postfix[i]))
      {
        num = num * 10 + (postfix[i] - '0');
        i++;
      }
      s.push(num);
    }
    else
    {
      int operand2 = s.pop();
      int operand1 = s.pop();

      switch (ch)
      {
        case '+':
          s.push(operand1 + operand2);
          break;
        case '-':
          s.push(operand1 - operand2);
          break;
        case '*':
          s.push(operand1 * operand2);
          break;
        case '/':
          s.push(operand1 / operand2);
          break;
        case '%':
          s.push(operand1 % operand2);
          break;
      default:
        cout << "Invalid operator: " << ch << endl;
        exit(1);
      }
      i++;
    }
  }

  if (!s.is_empty())
  {
    return s.pop();
  }
  else
  {
    cout << "Invalid postfix expression" << endl;
    exit(1);
  }
}

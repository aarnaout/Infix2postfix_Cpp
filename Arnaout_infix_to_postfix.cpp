#include <iostream.h>
#include <string.h>
 
struct stack
{
	int ptr;
	char arr[50];
	stack()
	{
		ptr=0;
		arr[0];
	}
	char top()
	{
		return arr[ptr];
	}
	void push(char ch)
	{
		ptr++;
		arr[ptr]=ch;
	}
	void pop()
	{
		ptr--;
	}
};
void Convert(char[50], char[50]);
bool IsOperand(char ch);
bool TakesPrecedence(char OperatorA, char OperatorB);
void main()
   {
   char Reply;
   do
      {
		char Infix[50], Postfix[50]=""; 

      cout << "Enter an infix expression (e.g. (a+b)/c^2, with no spaces):"<< endl;
      cin >> Infix;

      Convert(Infix, Postfix);
      cout << "The equivalent postfix expression is:" << endl<< Postfix << endl;
      cout << endl << "Do another (y/n)? ";
      cin >> Reply;
      }
   while (Reply == 'y');
   }


bool IsOperand(char ch)
   {
   if (((ch >= 'a') && (ch <= 'z')) ||
      ((ch >= 'A') && (ch <= 'Z')) ||
      ((ch >= '0') && (ch <= '9')))
      return true;
   else
      return false;
   };

bool TakesPrecedence(char OperatorA, char OperatorB)
   {
   if (OperatorA == '(')
      return false;
   else if (OperatorB == '(')
      return false;
   else if (OperatorB == ')')
      return true;
   else if ((OperatorA == '^') && (OperatorB == '^'))
      return false;
   else if (OperatorA == '^')
      return true;
   else if (OperatorB == '^')
      return false;
   else if ((OperatorA == '*') || (OperatorA == '/'))
      return true;
   else if ((OperatorB == '*') || (OperatorB == '/'))
      return false;
   else
      return true;
   };

void Convert(char Infix[50], char Postfix[50])
   {
   stack OperatorStack;
   char TopSymbol, Symbol;
   int L;
   for (unsigned k = 0; k < strlen(Infix); k++)
      {
      Symbol = Infix[k];
      if (IsOperand(Symbol))
	  {
		 L=strlen(Postfix);
		 Postfix[L]=Symbol;
		 Postfix[L+1]='\0';
	  }
      else
         {
  while((OperatorStack.ptr)&&(TakesPrecedence(OperatorStack.top(), Symbol)) )
            {
            TopSymbol = OperatorStack.top();
            OperatorStack.pop();
		    L=strlen(Postfix);
		    Postfix[L]=TopSymbol;
		    Postfix[L+1]='\0';
            }
         if (( OperatorStack.ptr) && (Symbol == ')'))
            OperatorStack.pop();   // discard matching (
         else
            OperatorStack.push(Symbol);
         }
      }

	while ( OperatorStack.ptr)
      {
      TopSymbol = OperatorStack.top();
      OperatorStack.pop();
		 L=strlen(Postfix);
		 Postfix[L]=TopSymbol;
		 Postfix[L+1]='\0';
      }
   }


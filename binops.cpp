#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class binops
{
private:
  float opnd1;
  float opnd2;
  char op;

public:
  binops() : opnd1(0), opnd2(0), op('+') {}; // default constructor

  binops(float in_opnd1, float in_opnd2, char in_op) : opnd1(in_opnd1), opnd2(in_opnd2), op(in_op) {};

  float getOpnd1()
  {
    return opnd1;
  }

  float getOpnd2()
  {
    return opnd2;
  }

  char getOp()
  {
    return op;
  }

  void setOpnd1(float in_opnd1)
  {
    opnd1 = in_opnd1;
  }

  void setOpnd2(float in_opnd2)
  {
    opnd2 = in_opnd2;
  }

  void setOp(char in_op)
  {
    op = in_op;
  }

  float evaluate()
  {
    if (op == '+')
    {
      return opnd1 + opnd2;
    }
    else if (op == '-')
    {
      return opnd1 - opnd2;
    }
    else if (op == '*')
    {
      return opnd1 * opnd2;
    }
    else if (op == '/')
    {
      if (opnd2 == 0)
      {
        throw "You cannot divide by zero";
      }
      return opnd1 / opnd2;
    }
    else
    {
      throw "Operator not supported";
    }
  }
};

int main()
{
  constexpr int SIZE = 3;
  binops *expressions = new binops[SIZE];
  ofstream file("expressions.txt");

  float opnd1, opnd2;
  char op;
  string line;

  for (int i = 0; i < SIZE; i++) // inputting the expressions and parsing them
  {

    cout << "Please enter expression " << i + 1 << endl; // for clarity during execution

    while (!(cin >> opnd1 >> op >> opnd2))
    {
      cout << "Invalid input, try again: " << endl;
      cin.clear();            // resets the stream state to 'good bit'
      cin.ignore(1000, '\n'); // clear the stream

      // buffer: [___\n]
    }

    //  \n

    expressions[i].setOpnd1(opnd1);
    expressions[i].setOpnd2(opnd2);
    expressions[i].setOp(op);
  }

  for (int i = 0; i < SIZE; i++) // traverse and output
  {
    try
    {
      file << expressions[i].getOpnd1() << " " << expressions[i].getOp() << " " << expressions[i].getOpnd2() << " -> " << expressions[i].evaluate() << endl;
    }
    catch (const char *error)
    {
      cerr << error;
    }
  }
}
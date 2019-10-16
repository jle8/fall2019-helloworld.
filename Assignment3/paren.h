#include <iostream>

using namespace std;

class Genstack{
public:
  Genstack();//constructor
  Genstack(int maxSize); //overload constructor
  ~Genstack(); //destructor

  void push(char d);
  char pop();
  char peek(); //AKA top()

  bool isFull();
  bool isEmpty();

  int size;
  int top;

  char *myArray;
};

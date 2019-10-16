#include <stack>
#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include <paren.h>


using namespace std;

bool SyntaxChecker() {
    stack<char> S;
    int stopbro = 0;
    ifstream infile;
    infile.open(file.c_str());

    while (getline(infile, text)) {
        if(text.empty){
            cout << "Empty input. " << endl;
        }
        else
        {
            for (int i = 0; i < commands.size(); i++) {
                if (commands[i] == '(') {
                    S.push(commands[i]);
                  }
                    else if (commands[i] == ')') {
                      if (S.empty() || !S.top() == '(') {
                        stopbro = 1;
                        return false;
                      }
                      else {
                        S.pop();
                      }
                    }
                  }
                      if (stopbro == 0) {
                        if (S.empty()) {
                          return true;
                        }
                        else {
                          return false;
                        }
                      }
                    }

              int parenCounter(string s) {
                int counter = 0;

                if (SyntaxChecker()) { //checking for parenthesis
                  for (unsigned i = 0; i < s.size(); i++) {
                    if (s[i] == '(' || s[i] == ')') {
                      counter++;
                    }
                  }
                  return counter;
                }
                else { //checking for parenthesis
                  counter = -1;
                  return counter;
                }
              }

int main() {
  stack<char> S;
  int stopbro;

}

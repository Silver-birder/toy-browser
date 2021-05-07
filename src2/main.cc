#include <iostream>
using namespace std;

void printMyMessageToOut() {
  cout << "Print My Message!!";
}

void inputAndOutFunc() {
  char str[16];
  cout << "Please Input:";
  cin >> str;
  cout << "ようこそ" << str << "さん";
}

//int compileErrrorFunc() {
//  cout << "Compile?";
//  return;
//}

void loopfunc() {
 for(int i = 0 ; i < 10 ; i++) {
   cout << i;
 }
}

struct S_TAG {
  int i;
};

union U_TAG {
  int i;
  double d;
};

enum E_TAG { A, B, C };

int main(int argc, char **argv) {
  S_TAG s_obj;
  U_TAG u_obj;
  E_TAG e_obj;
  return 0;
}

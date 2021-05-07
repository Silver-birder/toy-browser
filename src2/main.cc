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

bool boolFunc() {
  bool a = true, b = false, c = 0;
  return(a && (b || !c));
}

struct S_TAG {
  int i;
};

union U_TAG {
  int i;
  double d;
};

enum E_TAG { A, B, C };

class Kitty {
  private:
    int point;
  public:
    Kitty(int p);
    ~Kitty();
    void setPoint(int p);
    int getPoint();
};

void Kitty::setPoint(int p) {
  point = p;
}

int Kitty::getPoint() {
  return Kitty::point;
}

Kitty::Kitty(int p) {
  point = p;
}

Kitty::~Kitty() {
	cout << "Kitty on your lap\n";
}

void createKitty() {
	Kitty obj(1);
}

int useKittyPoint() {
  Kitty obj(3);
  obj.setPoint(1);
  return obj.getPoint();
}

class Sitty {
public:
	char *str;
	Sitty(char *ch);
};

Sitty::Sitty(char *ch) {
	str = ch;
}

//void useSitty() {
//  Sitty obj("Sitty");
//  cout << obj.str;
//}

int main(int argc, char **argv) {
  return 0;
}

#include <iostream>
using namespace std;
#include <memory>

class Rectangle {
  int length;
  int breadth;

public:
  Rectangle(int l = 1, int b = 1) {
    length = l;
    breadth = b;
  }

  ~Rectangle() { cout << "Deconstructor\n"; }

  int area() { return length * breadth; }
};

int main() {

  unique_ptr<Rectangle> P1(new Rectangle(10, 5));
  cout << "P1 = " << P1->area() << endl; // This'll print 50

  // unique_ptr<Rectangle> P2(P1);
  unique_ptr<Rectangle> P2(new Rectangle());
  P2 = move(P1);

  // This'll print 50
  cout << "P2 = " << P2->area() << endl;

  // cout << "P1 = " << P1->area() << endl; // This'll print 50

  // cout<<P1->area()<<endl;
  return 0;
}

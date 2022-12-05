#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <cstdlib>
#include <iostream>
using namespace std;

class SmartPtr {
  int *ptr; // Actual pointer
public:
  // Constructor: Refer https:// www.geeksforgeeks.org/g-fact-93/
  // for use of explicit keyword
  explicit SmartPtr(int *p = NULL) { ptr = p; }

  // Destructor
  ~SmartPtr() {
    cout << "Deconstruct ptr\n";
    delete (ptr);
  }

  // Overloading dereferencing operator
  int &operator*() { return *ptr; }
};

void signalHandler(int signum) {
  cout << "Interrupt signal (" << signum << ") received.\n";

  // cleanup and close up stuff here
  // terminate program

  exit(signum);
}

SmartPtr ptr(new int());

int main() {

  // register signal SIGINT and signal handler
  signal(SIGINT, signalHandler);

  // SmartPtr ptr(new int());
  *ptr = 20;
  cout << *ptr << endl;

  // We don't need to call delete ptr: when the object
  // ptr goes out of scope, the destructor for it is automatically
  // called and destructor does delete ptr.
  while (1) {
    sleep(1);
  }
  return 0;
}

#include <iostream>
#include "includes/sandbox.cpp"

using std::cout;
using std::endl;

int main()
{
  cout << (isSwingSetAvailable() ? "Go to the park now" : "You'd better wait") << endl;

  return 0;
}

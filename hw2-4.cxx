#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int num = 9009;
  string numStr = to_string(num);

  cout << "Number string: " << numStr << endl;
  
  string numStrRev = reverse(numStr.begin(), numStr.end());
  bool ans = (numStr == numStrRev);

  cout << "Is " << numStr << " a palindrome? " << ans;
}

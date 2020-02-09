#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


/*Program to find the largest palindromic number that is a product of
  two three-digit numbers. */



//list all discovered palindromes in the console
void printPalindromes(vector<int> vec) {
  cout << "Printing all palindromes.\n\n";
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << endl;
  };
  cout << endl;
}


//reverse the order of characters in a string
string reverseString(string str) {
  string strRev;
  for (int i = str.size() - 1; i >= 0; i--) {
    strRev.append(1, str[i]);
  }
  return strRev;
}


//compare number with its reversed form to determine whether it's a palindrome
bool isPalindrome(int num) {
  string numString = to_string(num);
  return numString == reverseString(numString);
}



int main(int argc, char **argv) {  
  vector<int> palindromes;
  vector<vector<int>> abValues;
  vector<int> ab;
  int product;

  //loop through all combinations of three-digit numbers and record palindromes
  for (int a = 999; a > 99; a--) {
    for (int b = a; b > 99; b--) {
      product = a*b;
      if (isPalindrome(product)) {
	palindromes.push_back(product);
	abValues.push_back({a, b});
      }
    }
  }

  //use option "show" to print all palindromes to the console
  if (argc > 1) {
    if (string(argv[1]) == "show") {
      printPalindromes(palindromes);
    }
  }

  //find the largest palindrome and the pair of numbers that produced it
  vector<int>::iterator maxPalindrome = max_element(palindromes.begin(), palindromes.end());
  ab = abValues[distance(palindromes.begin(), maxPalindrome)];
  int a = ab[0];
  int b = ab[1];

  //print results to the console
  cout << "Total palindromes: " << palindromes.size() << endl;
  cout << "Largest palindrome: " << *maxPalindrome << " = " << a << "*" << b << endl;
  
  return 1;
}

#include <iostream>

using namespace std;

//program to find the sum of all natural numbers below 1000 divisible by 3 or 5





//___Method 1___//
/*loops through all integers 3 to 999 and checks the remainder when divided by 3 and 5.
If either remainder is 0, the number is added to a running count.*/

int methodOne() {
	int total = 0;
	for (int n = 3; n < 1000; n++) {
		if ((n % 3 == 0) || (n % 5 == 0)) {
			total += n;
		}
	}
	return total;
}



//___Method 2___//
/*finds the number of multiples of 3, 5, and 15 up to 1000, which are stored in the "num"
variables. It then takes advantage of the formula for the sum of the first
n natural numbers to find the sum of all multiples of 3 and 5. Finally, it subtracts off
all multiples of 15 from this total to account for double-counted values. */


//formula for the sum of first n natural numbers
int sumTo(int n) {
	return n * (n + 1) / 2;
}


int methodTwo() {
  //note that "int" truncates any decimal values, effectively acting as floor division
  int num3 = 999 / 3; int num5 = 999 / 5; int num15 = 999 / 15;
	return 3 * sumTo(num3) + 5 * sumTo(num5) - 15 * sumTo(num15);
}



int main() {
	cout << "___Sum of all multiples of 3 and 5 up to 1000___\n\n";
	cout << "Result of Method 1: " << methodOne() << endl;
	cout << "Result of Method 2: " << methodTwo() << endl;
	return 1;
}

#include <iostream>
#include <vector>
#include <random>

using namespace std;


//print vector to console in readable format, with option to include memory addresses
void printVector(vector<float> vec, bool mem = false) {
  if (mem) {
    cout << "\n(";
    cout << "(" << vec[0] << ", " << &vec[0] << "),\n";
    for (int i = 1; i < vec.size(); i++) {
      cout << " (" << vec[i] << ", " << &vec[i] << ")";
      if (i < vec.size() - 1) {
	cout << "," << endl;
      }
    }
    cout << ")\n\n";
  }
  else {
    cout << "\n(";
    cout << vec[0] << ",\n";
    for (int i = 1; i < vec.size(); i++) {
      cout << " " << vec[i];
      if (i < vec.size() - 1) {
	cout << ",\n";
      }
    }
    cout << ")\n\n";
  }
}

//solicit command from the user
char userCommand() {
  char ans;
  cout << "\n\n\nType 'a' to add new random component. Type 'x' to finish populating your vector.\n\t";
  cin >> ans;
  return ans;
}


//introduce the show
void runIntro() {
  cout << "\n\n\n\nWelcome, and thank you for joining us on today's episode of \"Vectors! What do they hold? Do they hold things? Let's find out!\"" << endl;
  cout << "\nOur patented Voluminous Vector Vendor will give you your very own vector, along with the once-in-a-lifetime opportunity to populate it with random 32-bit values to your heart's content." << endl;
  cout << "\nIn addition, you will be shown each component's address in memory, so you can rest assured that all your new bits and bytes are cozy and safe." << endl;
  cout << "\nAre you ready? Let's get populating! [Press 'Enter' to continue]" << endl;
  cin.get();
}


//confirm with the user before exiting
char askExit() {
  char ans2;
  cout << "Are you sure you're ready to take your vector home? [y/n]   ";
  cin >> ans2;
  if (ans2 != 'y') {
    cout << "Carry on!" << endl;
    return ' ';
  }
  else {
    return 'x';
  }
}


//run main program
int main() {
  random_device rd;
  mt19937 mt(rd());
  uniform_real_distribution<double> dist(0, 1);

  vector<float> vec;
  char ans;
  
  runIntro();
  
  while (ans != 'x') {
    ans = userCommand();

    if (ans == 'a') {
      vec.push_back(dist(mt));
      printVector(vec, true);
    }
    else if (ans == 'x') {
      ans = askExit();	
    }
    else {
      cout << "Sorry? I didn't catch that." << endl;
    }
  }

  cout << "\n\nAll right folks, it's time. I am honored to present to you your Very Own Vector! [Press 'Enter' to continue]" << endl;
  cin.ignore();
  cin.get();
  printVector(vec);
  cout << "\nYour vector holds " << vec.size() << " things. You should be proud of each and every one of them!" << endl;

  return 1;
}

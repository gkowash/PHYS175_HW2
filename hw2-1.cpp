#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

//return sum of vector elements
float vecSum(vector<float> Q) {
	float total = 0;
	for (int i = 0; i < Q.size(); i++) {
		total += Q[i];
	}
	return total;
}

//return mean of vector elements
float vecAvg(vector<float> Q) {
	return vecSum(Q) / Q.size();
}

//return standard deviation of vector elements
float vecStd(vector<float> Q) {
	float mean = vecAvg(Q);
	float sqDiff = 0;
	for (int i = 0; i < Q.size(); i++) {
		sqDiff += pow((Q[i] - mean), 2);
	}
	return pow(sqDiff / Q.size(), 0.5);
}

int main() {
	vector<float> Q;
	Q.push_back(2.3);
	Q.push_back(4.7);
	Q.push_back(0.1);
	Q.push_back(6.4);
	Q.push_back(3.8);
	Q.push_back(9.6);
	Q.push_back(9.0);
	Q.push_back(6.1);
	Q.push_back(7.3);
	Q.push_back(2.2);
	
	cout << "Sum: " << vecSum(Q) << endl;
	cout << "Mean: " << vecAvg(Q) << endl;
	cout << "Standard deviation: " << vecStd(Q) << endl;

	return 1;
	}

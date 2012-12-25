#ifndef KTHSMALLEST
#define KTHSMALLEST

using namespace std;

#include <vector>

class kthsmallest {
private:
	vector<int> S;
	int size;
	int k;
	//private methods:
	void startAlg();
	vector<int> recStartAlg(vector<int>, int);
public:
	kthsmallest(int, int);
};

#endif
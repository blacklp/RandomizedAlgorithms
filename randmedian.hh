#ifndef RANDMEDIAN_H
#define RANDMEDIAN_H

#include <vector>

using namespace std;

class randmedian {
private:
	int sizeS;
	int sizeR;
	int d;
	int u;
	int nd;
	int nu;
	int median;
	vector<int> S;
	vector<int> R;
	vector<int> C;
	util ut;
// private methods:	
	void createR();
	void sortR();
	void sortC();
	void computeD();
	void computeU();
	void createC();
	void computeMedian();
public:
	randmedian(int, char);
	randmedian(vector<int>);
	void startAlg();
	bool isMEnclosed();
	bool isSizeCBig();
	int getMedian();
};

#endif

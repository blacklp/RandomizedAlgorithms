#include <iostream>
#include <stdlib.h>
#include "quickselect.hh"

using namespace std;

quickselect::quickselect(int size, int k) {
	quickselect::size = size;
	util u;
	S = u.createStructure(size, 's');
	int result = startAlg(S, k);
	cout<<"The "<<k<<"th element found by the algorithm is ";
	cout<<result<<endl;
	quickselect::result = result;
}

quickselect::quickselect(vector<int> S, int k) {
	quickselect::S = S;
	quickselect::size = S.size();
	int result = startAlg(S, k);
	cout<<"The "<<k<<"th element found by the algorithm is ";
	cout<<result<<endl;
	quickselect::result = result;
}

int quickselect::startAlg(vector<int> v, int k) {
	int indX = rand() % v.size(); // indX = [0, size - 1]
	int x = v[indX];
	vector<int> L, E, G;
	for(unsigned int i = 0; i < v.size(); i++) {
		if(v[i] < x) {
			L.push_back(v[i]);
		}else if(v[i] > x) {
			G.push_back(v[i]);
		}else { //equal
			E.push_back(v[i]);
		}
	}
	if((unsigned)k <= L.size()) {
		return startAlg(L, k);
	}
	int diff = L.size() + E.size();
	if(k > diff) {
		return startAlg(G, k - diff);
	}
	return x;
}

int quickselect::getResult() {
	return result;
}

#include <iostream>
#include <stdlib.h>
#include "kthsmallest.hh"

using namespace std;

kthsmallest::kthsmallest(int size, int k) {
	kthsmallest::size = size;
	kthsmallest::k = k;
	util u;
	S = u.createStructure(size, 's'); //create set
	startAlg();
}

void kthsmallest::startAlg() {
	vector<int> kthSet = recStartAlg(S, k);
	cout<<"The kth smallest elements are:"<<endl<<"[ ";
	for(int i = 0; i < kthSet.size(); i++)
		cout<<kthSet[i]<<" ";
	cout<<"]"<<endl;
}

vector<int> kthsmallest::recStartAlg(vector<int> set, int kElem) {
	if( kElem == set.size() ) {
		return set;
	}
	int y = set[rand() % set.size()];
	
	vector<int> S1, S2;
	for(int i = 0; i < set.size(); i++) {
		if(set[i] <= y)
			S1.push_back(set[i]);
		else
			S2.push_back(set[i]);
	}
	
	if( kElem <= S1.size() ) {
		return recStartAlg( S1, kElem );
	}else {
		vector<int> v2 = recStartAlg( S2, kElem - S1.size() );
		S1.insert(S1.end(), v2.begin(), v2.end());
		return S1;
	}
}

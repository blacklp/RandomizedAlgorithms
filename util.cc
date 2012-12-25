#include <iostream>
#include <stdlib.h>

using namespace std;

#include "util.hh"

vector<int> util::createStructure(int size, char kind) {
	switch(kind) {
		case 's': //set
			return createSet(size);
		case 'm': //multiset
			return createMultiset(size);
		default: return vector<int>();
	}
}

vector<int> util::createSet(int size) {
	cout<<"S = [ ";
	for(int i = 0; i < size; i++) {
		//create random int:
		int elem = rand() % (size*2); // elem = [0,size*2-1]
		while( setContains(elem) ) { //to make sure S is a set.
			elem = rand() % (size*2); //new element
		}
		S.push_back(elem);
		cout<<S[i]<<" ";
	}
	cout<<"]"<<endl;
	return S;
}

vector<int> util::createMultiset(int size) {
	cout<<"S = [ ";
	for(int i = 0; i < size; i++) {
		//create random int:
		int elem = rand() % (size*2); // elem = [0,size*2-1]
		S.push_back(elem);
		cout<<S[i]<<" ";
	}
	cout<<"]"<<endl;
	return S;
}

bool util::setContains(int element) {
	int i = 0;
	bool found = false;
	while(i < S.size() and !found) {
		found = (S[i] == element);
		i++;
	}
	return found;
}

vector<int> util::mergeSort(vector<int> v) {
	if( v.size() <= 1 ) {
		return v;
	}else {
		int middle = ( v.size() / 2);
		vector<int>::iterator it_end = v.begin() + v.size();
		vector<int> v1 = vector<int>( v.begin(), v.begin() + middle );
		vector<int> v2 = vector<int>( v.begin() + middle, it_end );

		v1 = mergeSort( v1 );
		v2 = mergeSort( v2 );
		v = merge(v1, v2);
		return v;
	}
}

vector<int> util::merge(vector<int> v1, vector<int> v2) {
	vector<int> result;
	int i1 = 0, i2 = 0;
	while(i1 < v1.size() or i2 < v2.size()) {
		if(i1 < v1.size() and i2 < v2.size()) {
			if(v1[i1] <= v2[i2]) {
				result.push_back(v1[i1]);
				i1++;
			}else {
				result.push_back(v2[i2]);
				i2++;
			}
		}else if(i1 < v1.size()) {
			result.push_back(v1[i1]);
			i1++;
		}else if(i2 < v2.size()) {
			result.push_back(v2[i2]);
			i2++;
		}
	}
	return result;
}

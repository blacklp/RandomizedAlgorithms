#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "randmedian.hh"

using namespace std;

randmedian::randmedian(int size, char kind) {
	if(kind != 's' and kind != 'm') {
		cout<<"Error: bad character for set/multi-set"<<endl;
		exit(EXIT_FAILURE);
	}
	sizeS = size;
	//create S:
	S = ut.createStructure(size, kind);
	startAlg();
}

randmedian::randmedian(vector<int> S) {
	sizeS = S.size();
	//create S:
	randmedian::S = S;
	startAlg();
}

void randmedian::createR() {
	sizeR = ceil( pow(sizeS, 0.75) ); // sizeR = sizeS ^ (3/4)
	cout<<"R = [ ";
	for(int i = 0; i < sizeR; i++) {
		int position = rand() % sizeS; // position = [0, sizeS - 1]
		R.push_back(S[position]);
		cout<<S[position]<<" ";
	}
	cout<<"]"<<endl;
}

void randmedian::sortR() {
	R = ut.mergeSort(R);
	cout<<"sorted R = [ ";
	for(int i = 0; i < sizeR; i++) {
		cout<<R[i]<<" ";
	}
	cout<<"]"<<endl;
}

void randmedian::sortC() {
	C = ut.mergeSort(C);
	cout<<"sorted C = [ ";
	for(int i = 0; i < C.size(); i++) {
		cout<<C[i]<<" ";
	}
	cout<<"]"<<endl;
}

void randmedian::computeD() {
	int posD = abs(0.5 * pow(sizeS, 0.75) - pow(sizeS, 0.5));
	posD = floor(posD);
	d = R[posD];
	cout<<"R["<<posD<<"] = d = "<<d<<endl;
}

void randmedian::computeU() {
	int posU = ceil(0.5 * pow(sizeS, 0.75) + pow(sizeS, 0.5));
	if(posU > (sizeR - 1))
		posU = sizeR - 1;
	u = R[posU];
	cout<<"R["<<posU<<"] = u = "<<u<<endl;
}

bool randmedian::isMEnclosed() {
	nd = 0, nu = 0;
	for(int i = 0; i < sizeS; i++) {
		if(S[i] < d)
			nd++;
		if(S[i] > u)
			nu++;
	}
	cout<<"nd = (nbr of elems. in S that are < d) = "<<nd<<endl;
	cout<<"nu = (nbr of elems. in S that are > u) = "<<nu<<endl;
	if( nd > (sizeS / 2) ) {
		cout<<"FAIL: nd > n/2"<<endl;
		return false; //m is not enclosed by d and u
	}else if( nu > (sizeS / 2) ) {
		cout<<"FAIL: nu > n/2"<<endl;
		return false; //m is not enclosed by d and u
	}else {
		cout<<"So, d and u enclose m"<<endl;
	}
	return true;
}

void randmedian::createC() {
	cout<<"C = [ ";
	for(int i = 0; i < sizeS; i++) {
		if( S[i] >= d and S[i] <= u ) {
			C.push_back(S[i]);
			cout<<S[i]<<" ";
		}
	}
	cout<<"]"<<endl;
}

bool randmedian::isSizeCBig() {
	if( C.size() > ( 4 * pow(sizeS,0.75) ) ) {
		cout<<"FAIL: |C| is big ( more than 4*n^(3/4) )"<<endl;
		return true;
	}
	cout<<"|C| is not big ( it is <= 4*n^(3/4) )"<<endl;
	return false;
}

void randmedian::computeMedian() {
	median = C[ (sizeS/2) - nd ];
	cout<<"m = C[ (n/2) - nd ] = "<<median<<endl;
}

void randmedian::startAlg() {
	cout<<"1st step: Create multi-set R with n^(3/4) elems of S"<<endl;
	createR();
	cout<<"2nd step: Sort R with a n*ln(n) algorithm."<<endl;
	sortR();
	cout<<"3rd step: Compute d = R[(1/2)*n^(3/4)-n^(1/2)] and u";
	cout<<" = R[(1/2)*n^(3/4)+n^(1/2)]"<<endl;
	computeD();
	computeU();
	cout<<"4th: Scan S to check whether d and u enclose m."<<endl;
	if( isMEnclosed() ) {
		cout<<"5th: C = { x belongs_to S: d <= x <= u }. Check |C|"<<endl;
		createC();
		if( !isSizeCBig() ) {
			cout<<"6th: Sort C."<<endl;
			sortC();
			cout<<"7th: Compute the median."<<endl;
			computeMedian();
		}
	}
}

int randmedian::getMedian() {
	return median;
}

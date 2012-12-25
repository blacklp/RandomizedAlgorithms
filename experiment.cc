//experiment to get the prob. of failure of randmedian
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
#include "experiment.hh"

experiment::experiment(int maxSize) {
	experiment::maxSize = maxSize;
	startAlg();
}

void experiment::startAlg() {
	cout<<"Enter 1 if you want to perform an experiment with ";
	cout<<"repeated elements."<<endl;
	cout<<"Enter 2 if you want an experiment without reps."<<endl;
	cout<<"Enter 3 if you want an exp. consisting in comparing ";
	cout<<"the case of repeated with the one without repet."<<endl;
	int opt;
	cin>>opt;
	if(opt != 1 and opt != 2 and opt != 3) {
		cout<<"Error: Non-valid option.";
		exit(EXIT_FAILURE);
	}
	if(opt == 3) { //twice
		double probS = computeProbFail('s');
		double probM = computeProbFail('m');
		double diff = (double)probS - (double)probM;
		if(diff < 0) diff = -diff;
		
		if(probS > probM) {
			cout<<"The result using a set ("<<probS<<") is "<<diff;
			cout<<" more than with a multi-set ("<<probM<<")"<<endl;
		}else if(probM > probS){
			cout<<"The result using a multi-set ("<<probM<<") is ";
			cout<<diff<<" more than with a set ("<<probS<<")"<<endl;
		}else {
			cout<<"The probabilities in the cases analized are equal";
			cout<<endl;
		}
	}else if(opt == 1)
		computeProbFail('m');
	 else
		computeProbFail('s');
}

double experiment::computeProbFail(char kind) {
	int trials = 0, fails = 0;
	while(fails == 0) {
		int size = rand() % maxSize + 1; // size = [0, maxSize]
		randmedian randM(size, kind);
		if( !randM.isMEnclosed() or randM.isSizeCBig() ) {
			++fails;
		}
		++trials;
	}
	double probFail = ( (double)fails/(double)trials );
	string structure;
	if(kind == 's')
		structure = "set";
	else if(kind == 'm')
		structure = "multi-set";
	cout<<"Having used a "<<structure<<", ";
	cout<<"the prob. of failure obtained in this experiment is: ";
	cout<<fails<<" / "<<trials<<" = "<<probFail<<endl;
	return probFail;
}

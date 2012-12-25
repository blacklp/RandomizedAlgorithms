#include <iostream>
using namespace std;
#include "util.cc"
#include "randmedian.cc"
#include "experiment.cc"
#include "kthsmallest.cc"
#include "quickselect.cc"
#include "compare.cc"

int main() {
	cout<<"Please indicate the number corresponding to the algorithm";
	cout<<" that you want to execute:"<<endl<<endl;
	cout<<"1. Randomized Median algorithm."<<endl;
	cout<<"2. Experiment to get the prob. of failure of Randomized ";
	cout<<"median."<<endl;
	cout<<"3. Kth smallest elements algorithm."<<endl;
	cout<<"4. Quick-select algorithm."<<endl;
	cout<<"5. Algorithm to compare Randomized Median and Quick-select ";
	cout<<"in terms of performance."<<endl;
	
	int option;
	cin>>option;
	
	cout<<"Please enter the size of the data structure."<<endl;
	int size;
	cin>>size;
	

	switch(option) {
		case 1: { //randmedian
			cout<<"Please enter s if you want to use a set or m if ";
			cout<<"you want to use a multi-set."<<endl;
			char kind;
			cin>>kind;
			randmedian randM(size, kind);
			break;
		}case 2: { //experiment
			experiment exp(size);
			break;
		}case 3: { //kthsmallest
			cout<<"Enter a number less or equal than the size."<<endl;
			int k;
			cin>>k;
			kthsmallest(size, k);
			break;
		}case 4: { //quickselect
			cout<<"Please enter the number of the smallest element ";
			cout<<"to find (2 = 2nd smallest, 1 = 1st, etc.)"<<endl;
			int k;
			cin>>k;
			quickselect qse(size, k);
			break;
		}case 5: {
			cout<<"Please enter the number of the smallest element ";
			cout<<"to find (2 = 2nd smallest, 1 = 1st, etc.) needed";
			cout<<" to perform Quick-select."<<endl;
			int k;
			cin>>k;
			compare(size, k);
			break;
		}default: { //error
			cout<<"Error: Incorrect option!"<<endl;
			exit(EXIT_FAILURE);
			break;
		}
	}
}

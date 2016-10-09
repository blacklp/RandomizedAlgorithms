//compare randmedian with quickselect
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void compare(int size, int k) {
    util u;
    vector<int> S = u.createStructure(size, 's'); //set to be used with both randmedian and quickselect

    vector<int> sorted = u.mergeSort(S);
    int medium = sorted.size()/2 - 1;
    int realMedian1 = sorted[medium];
    int realMedian2 = sorted[medium];
    if( (size % 2) == 0 ) {//if even, position (medium + 1) is also valid:
        realMedian2 = sorted[medium + 1];
    }

    int randMTime0 = clock();
    randmedian randM(S); //randmedian alg. using a set
    int obtMedian = randM.getMedian();

    while(obtMedian != realMedian1 and obtMedian != realMedian2) {
        randmedian randM(S); //execute randmedian again until the obtained median is equal to the real one
        obtMedian = randM.getMedian();
    }

    int randMTimef = clock();
    double randMRunT = (double)(randMTimef-randMTime0)/CLOCKS_PER_SEC;

    int qseRealResult = sorted[k - 1];

    int qseTime0 = clock();
    quickselect qse(S, k);
    //we don't check if quickselect fails because it is a Las Vegas algorithm.
    int qseTimef = clock();
    double qseRunT = (double)(qseTimef - qseTime0)/CLOCKS_PER_SEC;
	
    cout<<"Result: Randomized Median took "<<randMRunT<<" mseconds";
    cout<<" and Quick-select took "<<qseRunT<<" mseconds."<<endl;
    if(randMRunT != qseRunT) {
        string faster;
        if(randMRunT < qseRunT)
            faster = "Randomized Median";
        else {
            faster = "Quick-select";
	}    
        cout<<"So, "<<faster<<" was faster.";
    }else {
        cout<<"So, they took the same."<<endl;
    }
}


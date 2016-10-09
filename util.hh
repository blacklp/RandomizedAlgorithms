#ifndef UTIL_H
#define UTIL_H

#include <vector>

using namespace std;

class util {
private:
    vector<int> S;
    int size;
    //private methods:
    vector<int> createSet(int);
    vector<int> createMultiset(int);
    vector<int> merge(vector<int>, vector<int>);
public:
    vector<int> createStructure(int, char);
    vector<int> mergeSort(vector<int>);
    bool setContains(int);
};

#endif


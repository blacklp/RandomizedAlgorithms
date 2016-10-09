#include <vector>
#include <string>

using namespace std;

class quickselect {
private:
    int size;
    vector<int> S;
    int result;
    //private methods:
    int startAlg(vector<int>, int);
public:
    quickselect(int, int);
    quickselect(vector<int>, int);
    int getResult();
};

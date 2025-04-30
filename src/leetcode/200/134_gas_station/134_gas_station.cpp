#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = 0, dif = 0;
        int total_dif = 0;

        for(int i = 0; i < n; i++) {
            dif += gas[i] - cost[i];
            total_dif += gas[i] - cost[i];
            if(dif < 0) {
                dif = 0;
                start = i + 1;
            }
        }

        return (total_dif < 0) ? -1 : start;
    }
};
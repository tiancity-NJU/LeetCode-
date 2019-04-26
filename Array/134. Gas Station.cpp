/*
author: ypz
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int length = gas.size();
        for(int i = 0; i < length; i++) {
            int tank = gas[i];
            int flag = 1;
            int index = i;
            int index_next = (i + 1 >= length) ? 0 : i + 1;
            while(index_next != i) {
                if(tank < cost[index]) {
                    flag = 0;
                    break;
                }
                tank = tank - cost[index] + gas[index_next];
                index = (index + 1 > length - 1) ? 0 : index + 1;
                index_next = (index_next + 1 > length - 1) ? 0 : index_next + 1;
            }
            if(tank < cost[index]) flag = 0;
            if(flag == 1) return i;
        }
        return -1;
    }
};

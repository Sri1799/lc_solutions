class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double wait = 0, ft = 0;
        for (auto &c:customers)
        {
            wait += max(ft - c[0], 1.0 * 0) + c[1];
            ft = max(ft, 1.0 * c[0]) + c[1];
        }

        return wait/customers.size();
    }
};

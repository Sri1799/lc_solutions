class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double wait = 0, ft = 0;
        for (auto &c:customers)
        {
            ft = max(ft, 1.0 * c[0]) + c[1];
            wait += ft - c[0];
        }

        return wait/customers.size();
    }
};

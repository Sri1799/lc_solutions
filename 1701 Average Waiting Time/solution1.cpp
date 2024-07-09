/*
  tc - O(N)
  sc - O(N)
*/

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0;
        int start, end;
        // in pq set input and end times
        /*
            time, 0 => when new order comes in => start
            time, 1 => when order is completed => end

            ans = 2
            ft = 3
        */  
        int ft = 0;

        for (auto &c:customers)
        {
            if (c[0]>=ft || ft == 0)
            {
                ans += c[1];
                ft = c[0] + c[1];
            }
            else
            {
                ans += ft - c[0] + c[1];
                ft += c[1];
            }
        }

        return ans / customers.size();
    }
};

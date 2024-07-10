class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        int cnt = 0;
        for (auto &log:logs)
        {
            if (log == "./")
                continue;
            else if (log == "../")
                cnt = max(0, cnt - 1);
            else
                cnt++;
        }

        return cnt;
    }
};

/*
  TC - O(N * 2^N)
  SC - O(N)
*/

class Solution {
public:
    int maxss = 1;

    void solve(string &s, int idx, unordered_set<string> &st, string &curr)
    {
        if (idx == s.length())
        {
            bool currAlreadyCounted = st.find(curr) != st.end();
            maxss = max(maxss, (int)st.size() + !currAlreadyCounted);
            return;
        }

        // add to curr
        curr += s[idx];
        solve(s, idx + 1, st, curr);
        curr.pop_back();

        // start a new one
        if (curr.length() > 0 && st.find(curr) == st.end())
        {
            string tempCurr = curr;
            st.insert(curr);
            curr = string(1, s[idx]);

            solve(s, idx + 1, st, curr);

            curr = tempCurr;
            st.erase(curr);
        }
    }

    int maxUniqueSplit(string s) {
        /*
                - find all possible combinations
                - if you reach EOS, get max
        */

        string curr = "";
        unordered_set<string> st;
        solve(s, 0, st, curr);
        return maxss;
    }
};

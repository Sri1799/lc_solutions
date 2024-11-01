/*
  tc - O(N)
  sc - O(N)
*/

class Solution {
public:
    string makeFancyString(string s) {
        /*
            - use stack, keep track of last and before last
            - make string at the end
        */
        char pc = '-', ppc = '-';
        string ans = "";
        for (auto &c:s)
        {
            if (ppc == pc && pc == c)
                continue;

            ans += c;
            ppc = pc;
            pc = c;
        }

        return ans;
    }
};

class Solution {
public:
    string getEncryptedString(string s, int k) {
        string newS = s;
        for (int i=0;i<s.length();i++)
        {
            newS[i] = s[(i + k)%s.length()];
        }

        return newS;
    }
};

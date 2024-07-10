/*
  tc - O(N^2)
  sc - O(N)
*/

class Solution {

    unordered_map<int,int> prev;

    int solve(string &s, int l, int r)
    {
        if (r<l)
            return 0;

        if (s[r] == ')' && prev[r] == l) // for (( ... )) scenarios
            return solve(s, l + 1, r - 1);

        // check for operators ((..)) +/- (..) scenaros 
        for (int i=r;i>=l;i--)
        {
            if (s[i] == ')')
            {
                i = prev[i];
                continue;
            }
            
            if (s[i] == '+' || s[i] == '-')
            {
                int lhs = solve(s, l, i - 1), rhs = solve(s, i + 1, r);
                if (s[i] == '+')
                    return lhs + rhs;
                
                return lhs - rhs;
            }
        }

        // no operators, check for brackets "    ((...))   "
        for (int i=r;i>=l;i--)
        {
            if (s[i] == ')')
            {
                return solve(s, prev[i] + 1, i - 1);
            }
        }
        
        // no operators, no brackets, check for number "   4234...444   "
        int number = 0;
        for (int i=l;i<=r;i++)
        {
            if (s[i] == ' ')
                continue;
            number = number*10 + (s[i] - '0');
        }

        return number;
    }

public:
    int calculate(string s) {
        /*
            (((4) + (3 * 5))) - (3 + 2)
            - need to start from rhs as associativity is left to right
            - brackets should get highest precedence
            - openingbracket map => keeps track of opening based on ending key
            - if (opb[r] == l)
                return solve(s, l+1, r-1);
               
              // search for operator +/-
              for (int i=r;i>=l;i--)
              {
                if (s[i] == ')')
                    i = op[i]; continue;
                else if (s[i] == '+' || s[i] == '-')
                    // return solve(s, l, i - 1) +/i solve(s, i + 1, r)
              }

              // no operators, search for brackets
              for (int i=r;i>=l;i--)
              {
                if (s[i] == ')')
                    return solve(s, op[i] + 1, i - 1);
              }

              // no operators, no brackets return num
              for 9...) 
              return num
        */
        int n = s.length();
        stack<int> st;
        for (int i=n-1;i>=0;i--)
        {
            if (s[i] == ')')
                st.push(i);
            else if (s[i] == '('){
                prev[st.top()] = i;
                st.pop();
            }
        }

        return solve(s, 0, n - 1);
    }
};

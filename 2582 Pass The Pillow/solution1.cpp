/*
  tc - O(1)
  sc - O(1)
*/

class Solution {
public:
    int passThePillow(int n, int time) {
        /*
            no. of hops in 1 run = n-1
            going forward => time/(n-1) is even
            goinf backwrd => time/(n-1) is odd

            gf => 
                1 + time%(n-1)
            gb =>
                n - time%(n-1)
        */

        n--;
        if ((time/n)%2)
            return n + 1 - time%n;
        
        return 1 + time%n;
    }
};

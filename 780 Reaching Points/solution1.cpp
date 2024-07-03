/*
to reach a 'tx', we would have added a ty to the prev tx. at that point, the ty would have been greater than the prev tx (at least by 1). 
hence, we can say that each stage ~ the max val is approx the next_stage_max_val/2 in worst case.
in this was, we reach 1,1 as the base case and the number of stages will the max number of times a max(tx,ty) can be divided by 2. i.e. log(max(tx,ty))
tc - O(log(max(tx,ty)))
sc - O(log(max(tx,ty)))
*/

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (sx == tx && sy == ty)
            return true;
        
        if (tx < sx || ty < sy || tx == ty)
            return false;

        if (sx == tx)
        {
            return (ty - sy)%tx == 0;
        }

        if (sy == ty)
        {
            return (tx - sx)%ty == 0;
        }
        /*
        need to subtract smaller number from greater number
        */
        if (tx > ty)
        {
            tx = tx % ty;
            return reachingPoints(sx, sy, tx, ty);
        }
        else
        {
            ty = ty % tx;
            return reachingPoints(sx, sy, tx, ty);
        }

        return false;
    }
    /*
    max number of states we could get is log2(10^9)
    tc - O(36), i.e. O(log(max(tx, ty))) max is 10^9 so we got 36
    sc - O(36)
    */
};

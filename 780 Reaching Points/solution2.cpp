class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        
        while (tx >= sx && ty >= sy)
        {
            if (sx == tx && sy == ty)
            {
                return true;
            }

            if (tx == ty)
                break;

            if (tx == sx)
                return (ty - sy)%tx == 0;
            
            if (ty == sy)
                return (tx - sx)%sy == 0;

            if (tx > ty)
                tx = tx%ty;
            else
                ty = ty%tx;
        }

        return false;
    }
    /*
    max number of states we could get is log2(10^9)
    tc - O(36), i.e. O(log(max(tx, ty))) max is 10^9 so we got 36
    sc - O(36)
    */
};

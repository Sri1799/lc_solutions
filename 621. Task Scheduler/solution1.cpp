class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        /*
            - min no. of intervals
            - for each label go over the whole set of intervals
                1 * 10^4 * 10^2 = > 10^6
            
            - MAP char to freq
            - pq (max heap) of { freq of a char, char }
            - queue<char> to free a char when it is time
            - time => for (in ti =0; ....) {///}
            - int itl = 0;
            - when do we start using the toFree? 
            - itlWhereStartFree = -1;
            while (pq.top() || toFree.size())
            {
                if (idx >= itlWhereStartFree && toFree.size())
                {
                    char c_ = toFree.front(); toFree.pop();
                    pq.push({ freq[c_], c_ });
                }

                if (pq.top())
                {
                    auto item = pq.top(); pq.pop();
                    int freq_ = item.first;
                    char c = item.second;

                    freq[c]--;

                    if (freq[c])
                    {
                        if (toFree.empty() && idlWhereStartFree == -1) // first time we add the toFree
                        {
                            itlWhereStartFree = idx + n + 1;
                        }

                        toFree.push(c);
                    }
                }

                idx++;
            }

            return idx;

            K - no. of unique lables 
            P - the avg. no of tasks per label
            N - 

            K*P ~ 10^4
            TC - O(K*Plog(K))
            SC - O(K)
        */
        unordered_map<char,int> freq, prevItl;
        priority_queue<pair<int,char>> pq;
        queue<char> tofree;

        int interval = 0;

        for (auto &c:tasks)
            freq[c]++;

        for (auto &item:freq)
            pq.push({item.second, item.first});


        /*
            freq
                A => 1
                B => 2

            pq = {}
            tofree = { B, A }
            interval = 4
            startToFreeItl = 3
        */

        while (pq.size() || tofree.size())
        {
            if (tofree.size())
            {
                bool canUseInCurrentInterval = interval >= prevItl[tofree.front()] + n + 1;
                if (canUseInCurrentInterval)
                {
                    char c = tofree.front();
                    tofree.pop();

                    pq.push({ freq[c], c });
                }
            }

            if (pq.size())
            {
                auto item = pq.top();
                pq.pop();

                char c = item.second;
                freq[c]--;
                prevItl[c] = interval;

                if (freq[c])
                {
                    tofree.push(c);
                }
            }

            interval++;
        }

        return interval;
    }
};

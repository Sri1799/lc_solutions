/*
    let N be the total no. of tasks and K be the number of unique labels

      TC - O(NlogK)
      SC - O(K)
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        /*
            A - 2, B - 1, n = 2

            cycle size = n + 1 = 3
            - populating each cycle, one task at a time
            - if pq.empty() => add the tasks added (we couldn't complete cycle)
              else if cycle == 0 (reached end of cycle) => add n + 1 as that is size of cycle (meaning
              we added tasks throughout that cycle)
            - greedily choose highest freq ones first
        */
        vector<int> freq(26, 0);
        for (auto &c:tasks)
            freq[c - 'A']++;
        
        priority_queue<int> pq; // max heap
        for (auto &item:freq)
        {
            if (item)
                pq.push(item);
        }

        int ans = 0;
        while (pq.size())
        {
            vector<int> nextCycle;
            int tasksAdded = 0, cycle = n + 1;

            while (cycle-- && pq.size())
            {
                int item = pq.top(); pq.pop();
                if (item > 1)
                    nextCycle.push_back(item - 1);

                tasksAdded++;
            }

            for (auto &item:nextCycle)
                pq.push(item);
            
            ans += pq.empty() ? tasksAdded : (n + 1);
        }

        return ans;
    }
};

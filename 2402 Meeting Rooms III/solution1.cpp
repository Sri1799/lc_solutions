/*
  N - number of rooms, M - number of meetings
  tc - O(MlogM + NlogN + MlogN) ~ O((M + N)logN)
  sc - O(N)
*/

#define pii pair<long long,int>

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        /*
        req to sort rooms based on id
        {free_time, id}
        for each meeting
            - if free time > meeting time, meeting start time is postponed
            - if free time < meeting time, pop queue till free time > meeting time
                add the popped ones back into queue
        */
        sort(meetings.begin(), meetings.end());
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (int i=0;i<n;i++)
            pq.push({0, i});
        vector<int> bookings(n, 0);

        for (auto &m:meetings)
        {
            if (pq.top().first > m[0])
            {
                auto item = pq.top();
                pq.pop();
                bookings[item.second]++;
                pq.push({item.first + m[1] - m[0], item.second});
            }
            else
            {
                // room is already unlocked by the time meeting starts
                vector<int> unlockedRooms;
                while (pq.size() && pq.top().first <= m[0])
                {
                    unlockedRooms.push_back(pq.top().second);
                    pq.pop();
                }

                for (auto &ur:unlockedRooms)
                {
                    pq.push({m[0], ur});
                }

                auto item = pq.top();
                pq.pop();
                bookings[item.second]++;
                pq.push({m[1], item.second});
            }
        }

        return max_element(bookings.begin(), bookings.end()) - bookings.begin();
    }
};

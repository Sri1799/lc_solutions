/*  
  let K be number of words, lenK be max length of word, N is len of target
  tc - O(N + K*lenK)
  sc - O(N + K*lenK)
*/

class Trie
{
public:
	vector<Trie *> ch;
	int cost = INT_MAX;
	bool isw = false;

	Trie()
	{
		ch.assign(26, nullptr);
	}

	void addWord(string &word, int cost)
	{
		Trie *ptr = this;
		for (auto &c:word)
		{
			if (ptr->ch[c-'a'] == nullptr)
				ptr->ch[c-'a'] = new Trie();

			ptr = ptr->ch[c-'a'];
		}

		ptr->isw = true;
		ptr->cost = min(cost, ptr->cost);
	}
};

class Solution {
public:
    int n;
    vector<int> dp;
    Trie *trie = nullptr;

    int solve(int idx, string &target)
    {
        if (idx == n)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int minCost = INT_MAX, pidx = idx;	
        Trie *ptr = trie;
        while (pidx < n)
        {
            if (ptr->ch[target[pidx]-'a'])
            {
                ptr = ptr->ch[target[pidx]-'a'];
                pidx++;
            }
            else
            {
                break;
            }

            if (ptr->isw)
            {
                int solveNext = solve(pidx, target);
                if (solveNext != INT_MAX)
                    minCost = min(minCost, solveNext + ptr->cost);
            }
        }		

        return dp[idx] = minCost;
    }
	
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
       	n = target.length();
        dp.assign(n, -1);
        
        trie = new Trie();
        for (int i=0;i<words.size();i++)
            trie->addWord(words[i], costs[i]);	
        
        solve(0, target);

        return dp[0] == INT_MAX ? -1 : dp[0];
    }
};

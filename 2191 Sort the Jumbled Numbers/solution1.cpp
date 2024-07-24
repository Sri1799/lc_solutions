/*
  tc - O(NlogN)
  sc - O(N)
*/

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int,int> mappedValues;
        unordered_map<int,int> relativeOrder;
        for (int i=0;i<nums.size();i++)
        {
            int newValue = 0, pow = 1, num = nums[i];
            relativeOrder[nums[i]] = i;
            do
            {
                int dig = num % 10;
                num /= 10;
                newValue = mapping[dig] * pow + newValue;
                pow *= 10;
            }while (num);

            mappedValues[nums[i]] = newValue; 
        }

        sort(nums.begin(), nums.end(), [&](const int &a, const int &b){
            return mappedValues[a]<mappedValues[b] || mappedValues[a] == mappedValues[b] && relativeOrder[a]<relativeOrder[b];
        });

        return nums;
    }
};

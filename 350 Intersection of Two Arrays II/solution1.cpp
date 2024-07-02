/*
  let N be number of elements in nums1 and M be number of elements in nums2
  tc - O(N + M)
  sc - O(N + M)
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;

        int l = 0, r = 0;
        while (l<nums1.size() && r<nums2.size())
        {
            if (nums1[l]<nums2[r])
                l++;
            else if (nums1[l]>nums2[r])
                r++;
            else
            {
                ans.push_back(nums1[l]);
                l++;
                r++;
            }
        }
        
        return ans;
    }   
};

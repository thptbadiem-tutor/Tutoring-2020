class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> Q;
        for (int i = 0; i < k - 1; ++ i) {
            while (!Q.empty() && nums[Q.back()] <= nums[i]) {
                Q.pop_back();
            }    
            Q.push_back(i);
        }
        for (int i = k - 1; i < nums.size(); ++ i) {
            while (!Q.empty() && Q.front() < i - k + 1) {
                Q.pop_front();
            }
            while (!Q.empty() && nums[Q.back()] <= nums[i]) {
                Q.pop_back();
            }    
            Q.push_back(i);
            result.push_back(nums[Q.front()]);
        } 
        return result;
    }
};

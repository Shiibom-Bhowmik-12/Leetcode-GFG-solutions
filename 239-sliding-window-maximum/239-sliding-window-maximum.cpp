class Solution {
public:
// The solution is quite easy if you understand monotonic queue. Monotonic queue maintains our queue in increasing or decreasing order. Deque data structure gives us the best way to implement them.
// As we want the max value, we need to maintain our queue in such a way such that we can get the maximum value in O(1).
// Eg. the given order is 5 4 3 6 7. The queue in each step will be:

// 5
// 5 4
// 5 4 3
// Now 6 is >3 so pop_back till we get a number greater than 6. In this case        whole of the queue gets popped.
// 6
// 7
// Now as we want our window to be of a particular size k, whenever the difference in current index and the top element's index is >=k , remove that element from the front.
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector <int> ans;
        int n=nums.size();
        deque <int> q; //only indexes are stored
        for(int i=0;i<n;i++)
        {   
            while(!q.empty() && i-q.front()>=k)
                q.pop_front(); //only window size of k is allowed
            while(!q.empty() && nums[q.back()]<nums[i])
                q.pop_back();
            q.push_back(i);
            if(i>=k-1)ans.push_back(nums[q.front()]); //our max value in O(1)
        }
        return ans;
    }
};
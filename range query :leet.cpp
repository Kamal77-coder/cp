//leetcode 303:range sum query-immutable
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
vector<int>pre;
    NumArray(vector<int>& nums) {
        
       pre.push_back(0);
        for(int i=1;i<=nums.size();i++)
          pre.push_back(pre[i-1]+nums[i-1]);
    }
    
    int sumRange(int i, int j) {
        return pre[j+1]-pre[i];
    }



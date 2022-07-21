//Given an integer array nums, return true if there exists a triple of indices //(i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such //indices exists, return false.


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        vector<int> len;
        
        for(int i=0;i<nums.size();i++){
            
            if(len.size()>=3)
                return true;
            if(len.empty()){
                len.push_back(nums[i]);
            }else{
                
                if(len.back()<nums[i]){
                    len.push_back(nums[i]);
                }else{
                    
                    int idx=lower_bound(len.begin(),len.end(),nums[i])-len.begin();
                    if(nums[i]!=len[idx])
                        len[idx]=nums[i];
                    
                    
                }
                
            }
        }
        
        if(len.size()>=3)
            return true;
        return false;
        
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution{
 public:
     int maxProduct(vector<int> & nums){
        int max_soFar = nums[0];
        int min_soFar = nums[0];
        int MaxEnd = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] <0){
                swap(max_soFar, min_soFar);

            }
            max_soFar = max(nums[i], nums[i]*max_soFar);
            min_soFar = min(nums[i], nums[i]*min_soFar);
            MaxEnd = max(MaxEnd, max_soFar);
        }
        return MaxEnd;
     }
};



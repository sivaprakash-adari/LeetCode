#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class SubArray {
public:
   int maxSubArraySum(vector<int>& nums) {
       int max_sum = INT_MIN;
       int sub_sum = 0;
       for(int i=0; i < nums.size(); i++) {
          sub_sum = max(sub_sum+nums[i], nums[i]);
          max_sum = max(max_sum, sub_sum);
       }
       return max_sum;
   }
};

int main()
{
   vector<int> nums = {5,4,-1,7,8};
   SubArray obj;
   cout << obj.maxSubArraySum(nums) << endl;
   return 0;
}
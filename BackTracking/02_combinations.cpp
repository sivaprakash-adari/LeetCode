#include<iostream>
#include<vector>

using namespace std;

void combinations(vector<int> curr, int i,vector<int>& nums, vector<vector<int>>& subsets) {
    if (i > nums.size()) 
        return;
    
    subsets.push_back(curr);
    for(int j=i; j < nums.size(); j++) {
        curr.push_back(nums[j]);
        combinations(curr, j+1, nums,subsets);
        curr.pop_back();
    }
   
}

int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> subsets;
    vector<int> curr = {};
    combinations(curr, 0, nums,subsets);
    for(int i = 0; i < subsets.size(); i++) {
        cout << "[" ;
        for(int j =0; j < subsets[i].size();j++) {
            cout << subsets[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

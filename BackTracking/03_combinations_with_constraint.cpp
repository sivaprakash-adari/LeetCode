/*
Example 3: 77. Combinations

Given two integers n and k, return all combinations of k numbers out of the range [1, n] in any order.

For example, given n = 4, k = 2, return [[2,4],[3,4],[2,3],[1,2],[1,3],[1,4]].

*/

#include<iostream>
#include<vector>

using namespace std;

void combinations(vector<int> curr, int i,vector<int>& nums, vector<vector<int>>& subsets, int k) {
    if (k == curr.size()) {
        subsets.push_back(curr);
        return;
    }
    
    for(int j=i; j < nums.size(); j++) {
        curr.push_back(nums[j]);
        combinations(curr, j+1, nums,subsets,k);
        curr.pop_back();
    }
}

int main()
{
    int n=4, k =2;
    vector<int> nums;

    for(int i = 1; i<=n; i++) {
        nums.push_back(i);
    }

    vector<vector<int>> subsets;
    vector<int> curr = {};
    combinations(curr, 0, nums,subsets,k);
    for(int i = 0; i < subsets.size(); i++) {
        cout << "[" ;
        for(int j =0; j < subsets[i].size();j++) {
            cout << subsets[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

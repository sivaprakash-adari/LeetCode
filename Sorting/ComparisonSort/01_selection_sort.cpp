#include <iostream>
#include <vector>

using namespace std;

class ComparisonSort {
public:
   void SelectionSort(vector<int>& nums) {
        for(int i =0; i < nums.size()-1; i++) {
            int minIndex = i;
            for(int j = i + 1; i < nums.size(); i++) {
                if(nums[j] < nums[minIndex]) {
                      minIndex = j;
                }
            }
            swap(arr[i],arr[minIndex]);
        }
   }
}

int main() {
  vector<int> arr = {8,5,3,2,1,7,9,4,10,6};
  SelectionSort(arr);
  return 0;
}

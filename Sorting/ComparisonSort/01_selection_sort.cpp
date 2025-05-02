#include <iostream>
#include <vector>

using namespace std;

class ComparisonSort {
public:
   void SelectionSort(vector<int>& nums) {
        for(int i =0; i < nums.size()-1; i++) {
            int minIndex = i;
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[j] < nums[minIndex]) {
                      minIndex = j;
                }
            }
            swap(nums[i],nums[minIndex]);
        }
   }

   void print(vector<int>&  nums) {
      cout << "Elements in vector : "; 
      for(int i=0; i < nums.size(); i++) {
          cout << nums[i] << " ";
      }
      cout << endl;
   }
};

int main() {
  vector<int> arr = {8,5,3,2,1,7,9,4,10,6};
  ComparisonSort sort;
  
  sort.print(arr);
  sort.SelectionSort(arr);
  cout << "After Selection sort " << endl;
  sort.print(arr);
  return 0;
}

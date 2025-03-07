#include<iostream>
#include<unordered_map>

using namespace std;

class SubString {

public:

int longestSubString(string s) {
    int n = s.size();
    unordered_map<char,int> charToNextIndex;
    int left = 0, right = 0, longest_substr_len =0;

    for(right = 0; right < n; right++) {
       char ch = s[right];
       if (charToNextIndex[ch] > left) {
           left = charToNextIndex[ch];
       }
       longest_substr_len = max(longest_substr_len, right-left+1);
       charToNextIndex[ch] = right+1;
    }

    return longest_substr_len;
}

};

int main() {
    string input_str = " ";
    while(true) 
    {
      cout << "Input String : "; 
      getline(cin,input_str);

      if(input_str.empty()) 
         break;

      SubString obj;
      cout << "Longest substring : " << obj.longestSubString(input_str) << endl;
    }
}
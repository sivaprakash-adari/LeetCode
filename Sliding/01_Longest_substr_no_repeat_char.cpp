#include<iostream>
#include<unordered_map>

using namespace std;

class SubString {

public:

int longestSubString(string s) {
    int n = s.size();
    int longest_substr_len = 0;
    unordered_map<char,int> chars;
    int left = 0, right = 0;

    while(right < n) {
       char ch = s[right];
       chars[ch]++;

       while(chars[ch]> 1) {
           chars[s[left]]--;
           left++;
       } 
       longest_substr_len = max(longest_substr_len, right-left+1);
       right++;
    }

    return longest_substr_len;
}

};

int main() {
    string s = " ";
    while(s!="\n") 
    {
      cout << "Input String : "; 
      cin >> s;
      SubString obj;
      cout << "Longest substring : " << obj.longestSubString(s) << endl;
    }
}

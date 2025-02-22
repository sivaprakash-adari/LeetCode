#include<iostream>
#include<vector>

using namespace std;

string intToRoman(int num) {
    vector<int> values =   {1000, 900, 500, 400, 100,   90, 50,   40,   10,  9 , 5  , 4,   1};
    vector<string> romans = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X","IX", "V", "IV", "I" };
    string roman_num = "";

    for (int i =0 ; i < values.size(); i++) {
        while(num >= values[i]) {
            num = num - values[i];
            roman_num += romans[i];
        }
    }

    return roman_num;
  
}

int main() 
{ 
   int num;
   while(getchar() != 'z' ) {
     cout << "Enter the number :" ;
     cin >> num;
     cout << intToRoman(num) << endl;
   }

}

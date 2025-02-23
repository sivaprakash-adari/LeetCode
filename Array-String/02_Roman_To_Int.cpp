#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

string IntToRoman(int num) {
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

int RomanToInt(string roman_no) {
    int num = 0;
    unordered_map<char,int> romans = {{'I',1}, {'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int last_char = 0;

    
    for(int i=roman_no.size()-1; i >= 0 ; i--) {
        int current_char = romans[roman_no[i]];
        if (current_char < last_char) 
            num -= current_char;
        else
            num += current_char;

        last_char = current_char;
    }

    return num;
}

int main() 
{ 
   string roman_no;
   int num;
   while(getchar() != 'z' ) {
     cout << "Enter the number :" ;
     cin >> num;
     roman_no = IntToRoman(num);
     cout << "Roman Number" << roman_no << endl;

     cout << "Decimal Number" << RomanToInt(roman_no) << endl;
   }

}

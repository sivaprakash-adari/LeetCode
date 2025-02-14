#include<iostream>

using namespace std;
 
class BitManupulation {

    public:
    int reverseBits(uint32_t num) {
        int power=31;
        int res = 0;

        while (num != 0) {
           res += (num & 1) << power;
           num = num >> 1;
           power--;
        }
        return res;
    }

    void printBinary(uint32_t num) {
        int mask = 0x80000000, power = 31;
        while (power > 0) {
            if (num & mask) 
               cout << "1";
            else
               cout << "0";
            num = num << 1;
            power -= 1;
        }
        cout << endl;
    }
};

int main() {
    BitManupulation obj;
    int in = 32767;
    int op = obj.reverseBits(in);
    cout << "Input  : " ;
    obj.printBinary(in);
    cout << "Output : ";
    obj.printBinary(op);
}
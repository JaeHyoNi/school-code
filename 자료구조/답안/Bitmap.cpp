#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int main()
{
    int i,j;
    long long bitmap[64];
    for (i = 0; i < 64; i++) {
        cin >> bitmap[i];
    }
    bool arr[64][64];
    for(i=0;i<64;i++) {
        bitset<64> bit(bitmap[i]);
        for (int j = 0;j < 64; j++) {
             arr[j][i] = bit.test(63-j);
        }
    }
    bitset<64> bbit(0);
    for (i = 0; i < 64; i++) {
        for (j = 0; j < 64; j++) {
            if (arr[i][j]) {
                bbit.flip(63-j);
            }
        }
        signed long long num = (signed long long)bbit.to_ullong();
        cout << num << endl;
        bbit.reset();
    }
    return 0; 
}

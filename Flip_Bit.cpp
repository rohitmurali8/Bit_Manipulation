#include <iostream>
#include <string>
#include <vector>
using namespace std;

void binary(int num){
    for(int i = 31; i >= 0; i--){
        cout << ((num & (1 << i)) == 0 ? 0: 1) << " ";
    }
    cout << endl;
}

int length_ones(int num){
    int len = 0;
    for(int i = 31; i >= 0; i--){
        int bit = ((num & (1 << i)) == 0 ? 0: 1);
        if(bit == 1)
            len += 1;
    }
    return len;
}

int max_seq(int num){
    vector<int> index;
    int len = 0;
    int max_len = 0;
    int prev_bit = 0;
    for(int i = 31; i >= 0; i--){
        int bit = ((num & (1 << i)) == 0 ? 0: 1);
        if(bit == 1)
            len += 1;
        else
            len = 0;
        if (len>max_len)
            max_len = len;
    }
    return max_len;
}

int main(){
    int a = 5;
    int output = 0;
    binary(1775);
    cout << "Maximum sequence of ones in a number is " << max_seq(1775) << endl;
    //=======================================================================//
    // Finds longest sequence of 1s that can be created by flipping a 0 to 1
    //=======================================================================//
    int seq, long_seq = 0;
    int num = 1775;
    for (int i = 31; i >= 0; i--)
    {
        int temp_num = ((num | (1 << i)));
        seq = max_seq(temp_num);
        if (seq > long_seq){
            long_seq = seq;
        }
        temp_num = num;
    }
    cout << "Maximum sequence of ones by flipping a bit is " << long_seq << endl;
    return 0;
}
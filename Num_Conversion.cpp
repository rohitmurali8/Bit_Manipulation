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

vector<int> bit_vector(int num){
    vector<int> bits;
    for(int i = 31; i>= 0; i--){
        bits.push_back(((num & (1 << i)) == 0 ? 0: 1));
    }
    return bits;
}

int swap_bits(vector<int> a, vector<int> b){
    int num_bits = 0;
    for(int i = 0; i < b.size(); i++){
        if(a.at(i) != b.at(i)){
            num_bits += 1;
        }
    }
    return num_bits;
}

int main(){
    vector<int> num1, num2;
    num1 = bit_vector(64);
    num2 = bit_vector(32);
    int bits = swap_bits(num1, num2);
    cout << "Number of bits to be swapped is " << bits << endl;
}
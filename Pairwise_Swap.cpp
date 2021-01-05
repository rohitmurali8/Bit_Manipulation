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

int swap_even_odd(int *bit1, int *bit2, int *num){
    int temp_bit1 = ((*num & (1 << *bit1)) == 0 ? 0: 1);
    int temp_bit2 = ((*num & (1 << *bit2)) == 0 ? 0: 1);
    if (temp_bit1 != temp_bit2){
        *num = ((*num ^ (temp_bit2 << *bit2)));
        *num = ((*num ^ (temp_bit2 << *bit1)));
    }
    else{
        *num = ((*num | (temp_bit2 << *bit2)));
        *num = ((*num | (temp_bit1 << *bit1)));
    }
    vector<int> nums = bit_vector(*num);     
    return *num; 
}

int main(){
    //=============================================================//
    // Swaps the even and odd bits throughout the number b
    //=============================================================//
    int b = 5;
    int i = 31;
    while(i>0)
    {
        int i_next = i-1;
        int new_b = swap_even_odd(&i, &i_next, &b);
        //cout << "Swap number is " << new_b << endl;
        b = new_b;
        i = i - 2;
    }
    cout << "Value after swapping all the bits is " << b << endl;
    return 0;
}
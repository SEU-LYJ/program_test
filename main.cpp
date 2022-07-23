#include <iostream>
#include <string>
#include <stdio.h>

bool is_prime(long input)
{
    if(input <= 1) {
        return false;
    }

    for(int i = 2; i * i <= input; ++i) {
        if(input % i == 0) {
            return false;
        }
    }
    return true;
}


using namespace std;
int main(void) {
    #ifdef DEBUG_TEST_LYJ
    freopen("input.txt","r", stdin);
    #endif
    int max_number;
    cin >> max_number;
    for(int i = 2; i <= max_number; ++i) {
        if(is_prime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
#include <iostream>
#include <string>
#include <stdio.h>
#include <set>
using namespace std;

int main(void) {
    #ifdef DEBUG_TEST_LYJ
    freopen("input.txt","r", stdin);
    #endif
    string input;
    getline(cin, input);
    int sum = 0;
    for(auto tmp = input.begin(); tmp < input.end(); ++tmp)
    {
        if(isupper(*tmp)) {
            ++sum;
        }
    }
    cout << sum << endl;
    return 0;
} 
#include <iostream>
#include <string>
#include <stdio.h>
#include <set>
#include <string.h>
using namespace std;

int max_palindrome(string &input)
{
    string string_convert;
    char pad_char = '#';
    char start_char = '$';
    char end_char = '@';
    size_t input_len = input.size();
    char * new_string = new char[input_Len * 2 + ];
    cout << input_len << endl;
    for(int index = 0; index < input_len; ++index) {
        new_string[index * 2 + 1] = pad_char;
        new_string[index * 2 + 2] = input[index];
    }
    new_string[0] = start_char;
    new_string[input.size() * 2 + 1] = pad_char;
    new_string[input.size() * 2 + 2] = end_char;
    new_string[input.size() * 2 + 3] = '\0';
    cout << new_string << endl;
    //delete []new_string;
    return 1;
}

int main(void) {
    #ifdef DEBUG_TEST_LYJ
    freopen("input.txt","r", stdin);
    #endif
    string input;
    cin >> input;
    cout << max_palindrome(input) << endl;
    return 0;
} 
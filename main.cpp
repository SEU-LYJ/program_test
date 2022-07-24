#include <iostream>
#include <string>
#include <stdio.h>
#include <set>
#include <string.h>
#include <algorithm>

using namespace std;

int max_palindrome(string &input)
{
    char pad_char = '#';
    char start_char = '$';
    char end_char = '@';
    size_t input_len = input.size();
    size_t malloc_len = input_len * 2 + 5;
    char * new_string = new char[malloc_len];
    int * max_palindrome_len = new int[malloc_len];
    for(int index = 0; index < malloc_len; ++index)
    {
        max_palindrome_len[index] = 0;
    }

    for(int index = 0; index < input_len; ++index) {
        new_string[index * 2 + 1] = pad_char;
        new_string[index * 2 + 2] = input[index];
    }
    new_string[0] = start_char;
    new_string[input.size() * 2 + 1] = pad_char;
    new_string[input.size() * 2 + 2] = end_char;
    new_string[input.size() * 2 + 3] = '\0';

    int max_center_pos = 1;
    int max_right_pos = 1;
    int max_len = 0;
    int max_len_center_pos = 0;
    max_palindrome_len[0] = 1;
    max_palindrome_len[1] = 1;
    for(int index = 2; index < malloc_len; ++index)
    {
        int current_len = 1;
        if(index < max_right_pos) {
            current_len = min(max_right_pos - index, max_palindrome_len[max_center_pos * 2 - index]);
        }

        while(index - current_len >= 0 && new_string[index - current_len] == new_string[index + current_len]) {
            ++current_len;
        }

        max_palindrome_len[index] = current_len;
        if(current_len + index > max_right_pos) {
            max_right_pos = current_len + index;
            max_center_pos = index;
            if(current_len > max_len) {
                max_len = current_len;
                max_len_center_pos = index;
            }
        }
    }

    delete []new_string;
    delete []max_palindrome_len;
    return max_len - 1;
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
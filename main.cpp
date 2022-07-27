#include <iostream>
#include <string>
#include <stdio.h>
#include <set>
#include <string.h>
#include <algorithm>
#include <map>
#include <iterator>
#include <vector>

using namespace std;

bool string_is_same(const string &a, const string &b)
{
    size_t len = a.size();
    if(len != b.size()) {
        return false;
    }
    int cnt[26] = {0};
    for(int i = 0; i < len; ++i)
    {
        ++cnt[a[i] - 'a'];
    }

    for(int i = 0; i < len; ++i)
    {
        --cnt[b[i] - 'a'];
    }

    for(int i = 0; i < 26; ++i)
    {
        if(cnt[i] != 0) {
            return false;
        }
    }
    return true;
};

int main(void)
{
#ifdef DEBUG_TEST_LYJ
    freopen("input.txt", "r", stdin);
#endif
    int cnt;
    vector<string> string_list;
    cin >> cnt;
    for(int index = 0; index < cnt; ++index)
    {
        string data;
        cin >> data;
        string_list.push_back(data);
    }

    string template_string;
    cin >> template_string;
    vector<string> target_list;
    for(auto string_itor = string_list.begin(); string_itor < string_list.end(); ++string_itor)
    {
        if(string_itor->size() != template_string.size()) {
            continue;
        }

            if (*string_itor != template_string)
            {
                if (string_is_same(*string_itor, template_string))
                {
                    target_list.push_back(*string_itor);
                }
            }
    }

    sort(target_list.begin(), target_list.end());
    int index = 0;
    cin >> index;
    if(index > 0 && target_list.size()) {

        cout << target_list.size() << endl << target_list[index - 1] << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
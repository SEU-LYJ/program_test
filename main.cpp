#include <iostream>
#include <string>
#include <stdio.h>
#include <set>
#include <string.h>
#include <algorithm>
#include <map>
#include <iterator>
#include <vector>
#include <ctype.h>
#include <array>
#include <numeric>
#include <stack>
#include <stdbool.h>

using namespace std;

int main(void)
{
#ifdef DEBUG_TEST_LYJ
    freopen("input.txt", "r", stdin);
#endif
    set<int> set_data;
    int num;
    cin >> num;
    for(int i =0; i < num;++i)
    {
        int tmp;
        cin >> tmp;
        if(set_data.find(tmp) == set_data.end()) {
            set_data.insert(tmp);
        }
    }

    for(auto itor = set_data.begin(); itor != set_data.end(); ++itor)
    {
        cout << *itor << endl;
    }
    return 0;
}
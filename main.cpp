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

int max_sub(vector<int> &data)
{
    int len = data.size();
    vector<int> dp(len, 1);
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (data[i] > data[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(),dp.end());
}
int main(void)
{
#ifdef DEBUG_TEST_LYJ
    freopen("input.txt", "r", stdin);
#endif
    int num;
    cin >> num;
    vector<int> num_list(num);
    for (int i = 0; i < num; ++i)
    {
        cin >> num_list[i];
    }
    cout << max_sub(num_list) << endl;
    return 0;
}
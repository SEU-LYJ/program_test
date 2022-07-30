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

struct data_t {
    int len;
    int a_end;
    int b_end;
};

int main(void)
{
#ifdef DEBUG_TEST_LYJ
    freopen("input.txt", "r", stdin);
#endif
    vector<string> m_test{"abc", "def", "ghi"};
    sort(m_test.begin(), m_test.end());
    cout << m_test[0] << " " << m_test[1] << " " << m_test[2] << endl;
    while(next_permutation(m_test.begin(), m_test.end())) {
        cout << m_test[0] << " " << m_test[1] << " " << m_test[2] << endl;
    }
    return 0;
}
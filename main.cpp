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
#include <queue>

using namespace std;
int main(void)
{
#ifdef DEBUG_TEST_LYJ
    freopen("input.txt", "r", stdin);
#endif
    priority_queue<int, vector<int>, less<int>> max_queue;
    priority_queue<int, vector<int>, greater<int>> min_queue;
    max_queue.push(2);
    min_queue.push(2);
    max_queue.push(3);
    min_queue.push(3);
    max_queue.push(5);
    min_queue.push(5);
    max_queue.push(0);
    min_queue.push(0);
    while(max_queue.size() > 0) {
        cout << max_queue.top() << endl;
        max_queue.pop();
    }
    while(min_queue.size() > 0) {
        cout << min_queue.top() << endl;
        min_queue.pop();
    }
    return 0;
}
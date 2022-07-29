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
struct pos_t
{
    int x, y;
};

static void judge_and_record(const char *old_string, map<string, string> & path, pos_t &m_pos, deque<pos_t> &queue)
{
    char new_string[128];
    sprintf(new_string, "(%d,%d)", m_pos.x, m_pos.y);

    path[new_string] = old_string;
    queue.push_back(m_pos);
}

int main(void)
{
#ifdef DEBUG_TEST_LYJ
    freopen("input.txt", "r", stdin);
#endif
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> map_data(rows, vector<int>(cols));
    vector<vector<int>> has_searched(rows, vector<int>(cols, 0));
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < cols; ++col)
        {
            cin >> map_data[row][col];
        }
    }
    map<string, string> path;
    deque<pos_t> node_queue;
    node_queue.push_back({0, 0});
    while (node_queue.empty() == false)
    {
        pos_t current_pos = node_queue.front();
        char buf[128];
        sprintf(buf, "(%d,%d)", current_pos.x, current_pos.y);
        if (current_pos.x == rows - 1 && current_pos.y == cols - 1)
        {
            break;
        }
        node_queue.pop_front();
        has_searched[current_pos.x][current_pos.y] = 1;
        int x = current_pos.x;
        int y = current_pos.y + 1;
        if(y < cols && map_data[x][y] == 0 && has_searched[x][y] == 0) {
            pos_t tmp = {x, y};
            judge_and_record(buf, path, tmp, node_queue);
        }

        x = current_pos.x + 1;
        y = current_pos.y;
        if(x < rows && map_data[x][y] == 0 && has_searched[x][y] == 0) {
            pos_t tmp = {x, y};
            judge_and_record(buf, path, tmp, node_queue);
        }

        x = current_pos.x;
        y = current_pos.y - 1;
        if(y >= 0 && map_data[x][y] == 0&& has_searched[x][y] == 0) {
            pos_t tmp = {x, y};
            judge_and_record(buf, path, tmp, node_queue);
        }
        
        x = current_pos.x - 1;
        y = current_pos.y;
        if(x >= 0 && map_data[x][y] == 0&& has_searched[x][y] == 0) {
            pos_t tmp = {x, y};
            judge_and_record(buf, path, tmp, node_queue);
        }
    }

    char temp_buf[128];
    sprintf(temp_buf,"(%d,%d)", rows-1, cols-1);
    string tmp_pos(temp_buf);
    stack<string> real_path;
    while(tmp_pos != "(0,0)") {
        real_path.push(tmp_pos);
        tmp_pos = path[tmp_pos];
    }

    cout << "(0,0)" << endl;
    while(real_path.size() > 0) {
        cout << real_path.top() << endl;
        real_path.pop();
    }
    return 0;
}
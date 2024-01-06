//
// Created by MingR on 2022/3/3.
//
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        auto solutions = vector<vector<string>>();
        auto queens = vector<int>(n, -1);
        auto columns = unordered_set<int>();
        auto diagonals1 = unordered_set<int>();
        auto diagonals2 = unordered_set<int>();
        backtrack(solutions, queens, n, 0, columns, diagonals1, diagonals2);
        return solutions;
    }

    void backtrack(vector<vector<string>> &solutions, vector<int> &queens, int n, int row, unordered_set<int> &columns, unordered_set<int> &diagonals1, unordered_set<int> &diagonals2) {
        if (row == n) {
            vector<string> board = generateBoard(queens, n);
            solutions.push_back(board);
        } else {
            for (int i = 0; i < n; i++) {
                if (columns.find(i) != columns.end()) {
                    continue;
                }
                int diagonal1 = row - i;
                if (diagonals1.find(diagonal1) != diagonals1.end()) {
                    continue;
                }
                int diagonal2 = row + i;
                if (diagonals2.find(diagonal2) != diagonals2.end()) {
                    continue;
                }
                queens[row] = i;
                columns.insert(i);
                diagonals1.insert(diagonal1);
                diagonals2.insert(diagonal2);
                backtrack(solutions, queens, n, row + 1, columns, diagonals1, diagonals2);
                queens[row] = -1;
                columns.erase(i);
                diagonals1.erase(diagonal1);
                diagonals2.erase(diagonal2);
            }
        }
    }

    vector<string> generateBoard(vector<int> &queens, int n) {
        auto board = vector<string>();
        for (int i = 0; i < n; i++) {
            string row = string(n, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
};

class Solution2 {
public:
    vector<vector<string>> solveNQueens(int n) {
        cout << "Solution2 begin ..." << endl;
        vector<vector<string>> result; // 存储最后结果
        vector<vector<int>> mark; // 标记棋盘是否可以放置皇后的二维数组
        vector<string> location;// 存储某个摆放结果，当完成一次递归找到结果后，将location push进入result

        // 循环初始化attack和queen数组
        for (int i = 0; i < n; i++) {
            // mark：8*8
            mark.push_back(vector<int>());// 将一维vector进行push_back进去
            for (int j = 0; j < n; j++) {
                mark[i].push_back(0);
            }

            // result：8*8
            location.push_back("");
            location[i].append(n, '.');
        }

        backtrack(0, n, location, mark, result);
        return result;
    } // solveNQueens end

    // 自定义处理函数，实现在（x，y）放置皇后，对attack数组更新
    // x，y表示放置皇后的坐标，二位数组attack表示棋盘可否放置皇后
    void put_queen(int x, int y, vector<vector<int>> &mark) {
        // 方向数组，方便对8个方向进行标记
        static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

        mark[x][y] = 1;    // (x,y)位置上放置皇后,进行标记

        // 通过两层循环，将皇后可能攻击到的位置进行标记
        for (int i = 1; i < mark.size(); i++) {// 从皇后位置向1到n-1个距离延伸
            for (int j = 0; j < 8; j++) {// 遍历上下左右斜角8个方向
                int new_x = x + i * dx[j];// 生成新位置行
                int new_y = y + i * dy[j];// 生成新位置列

                // 新位置在棋盘内，标记为攻击1
                if (new_x >= 0 && new_x < mark.size() && new_y >= 0 && new_y < mark.size()) {
                    mark[new_x][new_y] = 1;
                }
            }

        } // for end
    } // put_queen end

    // 回溯法递归函数
    // k代表完成几个皇后的位置（正在放置第k行皇后）
    // n表示N皇后问题
    // location某次结果存储在其中
    // mark标记棋盘的标记数据，皇后攻击位置,0表示未被攻击，1被攻击
    // result存储N皇后全部解法
    void backtrack(int k, int n, vector<string> &location, vector<vector<int>> &mark, vector<vector<string>> &result) {

        //终止条件，当k==n时，代表完成第0至n-1行皇后的位置，所有皇后完成放置后，将记录皇后位置的location数组push进入result
        if (k == n) {
            result.push_back(location);  // 将结果location存储至result中
            return;// 返回
        }

        // 遍历第k行所有位置,回溯试探皇后可放置位置
        for (int i = 0; i < n; i++) {
            if (mark[k][i] == 0) { // 判断当前第k行第i列是否可以放置皇后，如果mark[k][i]==0表示可以放置皇后
                // 处理节点
                vector<vector<int>> tmp_mark = mark;  // 备份回溯前的mark镜像
                location[k][i] = 'Q';    // 记录当前皇后位置
                put_queen(k, i, mark);    // 更新mark数组，放置皇后
                backtrack(k + 1, n, location, mark, result);  // 递归试探k+1行的皇后放置
                // 撤销回溯
                mark = tmp_mark;    // 将mark重新赋值为回溯前状态，这边的原因是该次递归结束后，恢复mark数组，并且尝试下一个可能放皇后的列
                location[k][i] = '.';     // 将当前尝试的皇后位置更新为.

            }
        } // for end
    } // backtrack end

};

static int practice_test() {
    cout << "8 queens question begin ..." << endl;
    Solution2 solution;
    vector<vector<string>> result;
    result = solution.solveNQueens(8);
//    printf("8 queens solve num： %d \n", result.size());
    cout << "8 queens solve num: " << result.size() << endl;
}
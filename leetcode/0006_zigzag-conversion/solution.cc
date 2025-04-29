#include <iostream>
#include <vector>
#include <algorithm> /* std::min */

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1) return s;

        std::vector<std::string> vec(
            std::min( numRows,  int(s.size()) )
        );
        int row = 0;
        bool godown = false;
        for (char c: s) {
            vec[row] += c;
            if (row == 0 || row == numRows - 1)
                godown = !godown;
            row += godown ? 1 : -1;
        }

        std::string res;
        for (std::string v : vec) res += v;
        return res;
    }
};

/* 测试 */
int main(void)
{
    Solution *sln;
    std::string s = sln->convert("LEETCODEISHIRING", 3);
    std::cout << s << std::endl;
    delete sln;
    return 0;
}

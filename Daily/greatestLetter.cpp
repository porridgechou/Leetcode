#include <al_zzh.h>

using namespace std;


/*
大、小写字母的ASCII码值相差32。ASCII码包含字母、数字、通用符号、控制符等。

基本的ASCII码的打印字符部分包括32～126(共95个)是字符：32是空格，其中48～57为0到9十个阿拉伯数字，65～90为26个大写英文字母，97～122号为26个小写英文字母，其余为一些标点符号、运算符号等。第127个字符表示的是键盘上的删除命令。
*/

class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char> ht(s.begin(), s.end());
        for (int i = 25; i >= 0; i++) {
            if (ht.count('a' + i) && ht.count('A' + i)) {
                return string(1, 'A' + i);
            }
            return "";
        }
    }
};
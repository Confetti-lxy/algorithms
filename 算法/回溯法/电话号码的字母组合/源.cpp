#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector <string> letterMap = {"",     // 0
                                 "",     // 1
                                 "abc",  // 2
                                 "def",  // 3
                                 "ghi",  // 4
                                 "jkl",  // 5
                                 "mno",  // 6
                                 "pqrs", // 7
                                 "tuv",  // 8
                                 "wxyz", // 9
    };
    vector <string> result;

    void getCombinations(const string &digits, int index, const string &s);

public:
    vector <string> letterCombinations(string digits);
};

void Solution::getCombinations(const string &digits, int index, const string &s) { // 注意参数的不同
    if (index == digits.size()) {
        result.push_back(s);
        return;
    }
    int digit = digits[index] - '0';
    string letters = letterMap[digit];
    for (int i = 0; i < letters.size(); i++) {
        getCombinations(digits, index + 1, s + letters[i]); // 注意这里的不同
    }
}

vector <string> Solution::letterCombinations(string digits) {
    result.clear();
    if (digits.size() == 0) {
        return result;
    }
    getCombinations(digits, 0, "");
    return result;
}
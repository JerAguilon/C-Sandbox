#include<string>
#include<vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        string solve(string);
};

string Solution::solve(string s) {
    auto n = s.length();
    auto result_l = 0, result_r = 0;

    auto table = vector<vector<bool>>(n, vector<bool>(n, false));

    // a string of length 1 is guaranteed to be palindromic
    for (int i = 0; i < table.size(); i++) {
        table[i][i] = true; 
    }
    // a string of length 2 is palindromic iff s[i] == s[i - 1]
    for (int i = 1; i < table.size(); i++) {
        if (s[i] == s[i - 1]) table[i-1][i] = true;
    }

    for (auto size = 3; size <= s.length(); size++) {
        for (auto left = 0; left < s.length() - size + 1; left++) {
            auto right = left + size - 1;
            if (table[left + 1][right - 1] && s[left] == s[right]) {
                table[left][right] = true;
                if (right - left > result_r - result_l) {
                    result_l = left;
                    result_r = right;
                }
            }              
        }
    }
    cout << "left " << result_l << " right " << result_r << "\n";
    return s.substr(result_l, result_r + 1);
}

int main() {
    Solution s;
    auto test = "bdcddcdboiwjefoiwjeaiojaaa";
    cout << "Attempting to solve " << test << "\n";
    cout << s.solve(test) << "\n";
}

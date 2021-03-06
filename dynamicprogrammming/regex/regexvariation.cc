#include<iostream>
#include<vector>
#include<unordered_map>
#include<assert.h>

using namespace std;
using cache = unordered_map<int, unordered_map<int, bool>>;

namespace helpers {
    vector<string> tokenize(string pattern) {
        vector<string> output;
        auto i = 0;
        while (i < pattern.length()) {
            string curr = string(1, pattern[i]);
            i += 1;
            if (i < pattern.length() && pattern[i] == '*') {
                curr.push_back(pattern[i]);
                i += 1;
            }
            output.push_back(curr);
        }
        return output;
    }

    bool does_match(vector<string> tokens, string str, int i, int j, cache c) {
        auto ifound = c.find(i);
        if (ifound != c.end()) {
            unordered_map<int, bool> inner = ifound->second;
            auto jfound = inner.find(j);
            if (jfound != inner.end()) {
                return c[i][j];
            }
        }

        if (i == tokens.size() && j == str.length()) {
            return true;
        }
        if (i == tokens.size()) {
            c[i][j] = false;
            return false;
        }

        string curr_token = tokens[i];
        if (j == str.length()) {
            if (curr_token.length() == 2) {
                auto result = does_match(tokens, str, i + 1, j, c);
                c[i][j] = result;
                return result;
            } else {
                c[i][j] = false;
                return false;
            }
        }

        char curr_char = str[j];
        bool result;
        if (curr_token.length() == 2) {
            if (curr_char != curr_token[0]) {
                result = does_match(tokens, str, i + 1, j, c);
            } else {
                result = does_match(tokens, str, i + 1, j, c) ||
                         does_match(tokens, str, i, j + 1, c);
            }
        } else {
            if (curr_char != curr_token[0]) {
                result = false;
            } else {
                result = does_match(tokens, str, i + 1, j + 1, c);
            }
        }
        c[i][j] = result;
        return result;
    }
}

class Solution {
    public:
        bool solve(string p, string s);
};


bool Solution::solve(string pattern, string str) {
    vector<string> tokens{helpers::tokenize(pattern)};
    cache c = {};
    return helpers::does_match(tokens, str, 0, 0, {});
}

int main() {
    Solution s;
    assert(s.solve("a*", "") == true);
    assert(s.solve("a*", "aaaaaa") == true);
    assert(s.solve("ca*b", "caaaaaab") == true);
    assert(s.solve("ca*", "caaaaaab") == false);
    assert(s.solve("ca*b*", "caaaaaa") == true);
    cout << "all tests passed :)" << endl;
}

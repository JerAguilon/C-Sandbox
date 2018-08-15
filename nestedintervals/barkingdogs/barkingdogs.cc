#include<string>
#include<iostream>
#include<unordered_set>
#include<unordered_map>

using namespace std;

const unordered_set<char> VALID_CHARS = {'b', 'a', 'r', 'k'};

struct Solution {
    public:
        int solve(const string&);
};

int Solution::solve(const string& s) {
    for (char c : s) {
        if (VALID_CHARS.find(c) == VALID_CHARS.end()) {
            return -1;
        }
    }
    unordered_map<string, int> barking_dogs {

    };
    unordered_map<string, int> next {

    };
    unordered_map<string, int> prev {

    };
    return -1;
}

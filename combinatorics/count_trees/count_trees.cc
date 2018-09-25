#include<iostream>
#include<unordered_map>
#include<assert.h>

using namespace std;
using cache = unordered_map<int, long>;

class Solution {
    public:
        unsigned long count_trees(unsigned int i) {
            return count_trees(i, {});
        }
    private:
        unsigned long count_trees(unsigned int i, cache c) {
            if (i == 0 || i == 1) {
                return 1;
            }
            auto found = c.find(i);
            if (found != c.end()) {
                return found->second;
            }

            unsigned long total = 0;
            for (auto mid = 0; mid < i; mid++) {
                unsigned long left = mid;
                unsigned long right = i - mid - 1;
                total += count_trees(left) * count_trees(right);
            } 
            c[i] = total;
            return total;
        }
};

int main() {
    Solution s;
    assert(s.count_trees(0) == 1);
    assert(s.count_trees(1) == 1);
    assert(s.count_trees(2) == 2);
    assert(s.count_trees(3) == 5);
    assert(s.count_trees(4) == 14);

    cout << "All tests passed :)";
}

#include<vector>
#include<unordered_set>
#include<cmath>

#define MASK 1

using namespace std;

void get_all_subsets(vector<int>& v, vector<unordered_set<int>>& sets) {	
    int num_sets = pow(2, v.size());
    for (int i = 0; i < num_sets; i++) {
        unordered_set<int> curr_set;
        for (int j = 0; j < v.size(); j++) {
            if (i & (MASK << j)) {
                curr_set.insert(v[j]);
            }
        }
        sets.push_back(curr_set);
    }
}

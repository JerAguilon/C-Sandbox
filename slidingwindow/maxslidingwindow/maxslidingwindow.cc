#include<vector>
#include<string>
#include<deque>

using namespace std;

vector<string> find_max_sliding_window(vector<int>& v, int window_size) {
    if (window_size > v.size()) {
        return {};
    }

    vector<int> maximums;
    deque<int> dq;

    int i = 0;
    
    /**
     * First, create your window by iterating through. Usng a deque, you want the
     * first element to always be the index of local max. In addition, we get rid of
     * invalid candidates by making sure that the list is strictly decreasing.
     */
    for ( ; i < window_size; i++) {
        while (!dq.empty() && v[i] >= v[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    /**
     * Now we can perform almost the same logic, but we need to remove the head
     * when the index is out of bounds of the window as well.
     *
     * OVERALL RUNTIME: O(n). There's a nested loop, but note that each element
     * is added to the list at most once and removed to the list at most once.
     *
     * Really this is similar to many sliding window problems, except you need
     * a clever data structure to represent state. Most "common" problems
     * rely on tricky pointers, but no internal data structure.
     */
    for ( ; i < v.size() ; i++) {
        maximums.push_back(v[dq.front()]);

        if (!dq.empty () && dq.front() <= i - window_size)
            dq.pop_front();
        while (!dq.empty() && v[i] >= v[dq.back()])
            dq.pop_back();
        dq.push_back(i);  
    }
    maximums.push_back(v[dq.front()]);

    string line = "";
    auto it = maximums.begin();
    vector<string> result;
    for (size_t i=0; i<maximums.size(); i++)
    {
        result.push_back(to_string(maximums[i]));
    }
    return result;
}

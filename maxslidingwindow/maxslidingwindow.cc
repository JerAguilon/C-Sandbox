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
    for ( ; i < window_size; i++) {
        while (!dq.empty() && v[i] >= v[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
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

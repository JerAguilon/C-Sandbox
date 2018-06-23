#include <vector>
#include <iostream>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int goal = amount;
    vector< vector<int> > arr (coins.size() + 1, vector<int> (goal + 1, 0) );

    for (int i = 0; i <= coins.size(); i++) {
        arr[i][0] = 1;
    }

    for (int i = 1; i < arr.size(); i++) {
        int currCoin = coins[i - 1];
        cout << currCoin;
        cout << "\n";
        for (int j = 0; j < arr[i].size(); j++) {
            arr[i][j] = (j - currCoin >= 0 ? arr[i][j - currCoin] : 0) + arr[i - 1][j];
        }
    }

    for ( const auto &row : arr )
    {
        for ( const auto &s : row ) std::cout << s << ' ';
        std::cout << std::endl;
    }
    return arr[coins.size()][goal];
}

int main() {
    vector<int> coins {1,2,5};
    cout << coinChange(coins, 5);
    cout << "\n";
    return 0;
}

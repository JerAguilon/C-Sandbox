#include<iostream>
#include<vector>

using std::vector;
using std::cout;

#define LEN 10

enum class Direction {
    LEFT, RIGHT, UP, DOWN
};

class State {
    public:
        int x;
        int y;
        State(Direction start): x{LEN/2}, y{LEN/2}, dir{start}, set{LEN, vector<bool>(LEN, false)}, found{0} {};

        void mutate() {
            set[x][y] = true;
            dir = updateDir();
            x = getNextX(dir);
            y = getNextY(dir);
            found += 1;
        }

        bool isDone() {
            return found == LEN * LEN;
        }

    private:
        int found;
        Direction dir;
        vector<vector<bool>> set;

        Direction updateDir() {
            Direction testDirection  = getNextDir();
            int testX = getNextX(testDirection);
            int testY = getNextY(testDirection);
            if (testX < 0 || testY < 0 || set[testX][testY]) {
               return dir; 
            }
            if (set[testX][testY]) {
                throw "Finished traversing";
            }
            return testDirection;
        }

        Direction getNextDir() {
            if (dir == Direction::LEFT) return Direction::UP;
            if (dir == Direction::UP) return Direction::RIGHT;
            if (dir == Direction::RIGHT) return Direction::DOWN;
            return Direction::LEFT;
        }

        int getNextX(Direction dir) {
            if (dir == Direction::LEFT) {
                return x - 1;
            }
            if (dir == Direction::RIGHT) {
                return x + 1;
            }
            return x;

        }

        int getNextY(Direction dir) {
            if (dir == Direction::UP) {
                return y - 1;
            }
            if (dir == Direction::DOWN) {
                return y + 1;
            }
            return y;

        }

};

void solution(vector<vector<double>> arr) {
    State state{Direction::DOWN};
    while (!state.isDone()) {
        cout << arr[state.y][state.x];
        cout << "\n";
        state.mutate();
    }
}

int main() {
    vector<vector<double>> arr;
    arr.resize(LEN);
    for (int i = 0; i < LEN; i++) {
        arr[i].resize(LEN);
        for (int j = 0; j < LEN; j++) {
            arr[i][j] = LEN * i + j;
        }
    }
    solution(arr);
    return 0;
}

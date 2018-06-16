#include<iostream>

using namespace std;


/* struct Vector { */
/*     int sz; */
/*     double* elem; */
/* }; */

class Vector {
    public:
        Vector(int s) { 
            if (s < 0) {
                throw length_error("Arg 0 must be greater than 0");
            }
            elem = new double[s];
            sz = s;
        }
        double& operator[](int i){ return elem[i]; }
        int size() { return sz; }
    private:
        double* elem;
        int sz;
};

double read_and_sum(int);

int main() {
    cout << read_and_sum(6);
    return 0;
}

double read_and_sum(int s) {
    Vector v{s};
    for (int i = 0; i < s; i++) {
        cin >> v[i];
    }

    double sum = 0;
    for (int i = 0; i < s; i++) {
        sum += v[i];
    }
    return sum;
}

#include<iostream>

using namespace std;


/* struct Vector { */
/*     int sz; */
/*     double* elem; */
/* }; */

class Container {
    public:
        virtual double& operator[](int) = 0; // pure virtual, must be defined
        virtual int size() const = 0;
        virtual ~Container() {}
};

class Vector {
    public:
        Vector(int s) { 
            if (s < 0) {
                throw length_error("Arg 0 must be greater than 0");
            }
            elem = new double[s];
            sz = s;
        }
        Vector(std::initializer_list<double> lst): elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())} {
           copy(lst.begin(), lst.end(), elem); 
        }


        ~Vector() { delete[] elem; };

        double& operator[](int i){ 
            return elem[i];
        }
        int size() const { return sz; }

        Vector push_back(double);
    private:
        double* elem;
        int sz;
};

class Vector_container: public Container {
    Vector v;
    public:
    Vector_container(int s): v(s) {}
    ~Vector_container() {}

    double& operator[](int i) { return v[i]; }
    int size() const { return v.size(); }
};

double read_and_sum(int);

int main() {
    cout << read_and_sum(6);
    return 0;
}

double read_and_sum(int s) {
    Vector v(s);
    for (int i = 0; i < s; i++) {
        cin >> v[i];
    }

    double sum = 0;
    for (int i = 0; i < s; i++) {
        sum += v[i];
    }
    return sum;
}

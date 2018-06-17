class complex {
    double re, im;

public:
    complex(double r, double i): re{r}, im{i} {};
    complex(double r): re{r}, im{0} {};
    complex(): re{0}, im{0} {};
    
    double real() const { return re; }
    void real(double d) { re = d; } 

    double imag() const { return im; }
    void imag(double d) { im = d; }

    // return a copy as a reference
    complex& operator+=(complex z) {
        re += z.re;
        im += z.im;
        return *this;
    }

    complex& operator-=(complex z) {
        re -= z.re;
        im -= z.im;
        return *this;
    }

    complex& operator *=(complex);
    complex& operator /=(complex);
};

// an argument passed by value is copied, so you can modify without
// affecting the caller
complex operator+(complex a, complex b) { return a += b; };
complex operator-(complex a, complex b) { return a -= b; };
complex operator-(complex a) { return {-a.real(), -a.imag() }; };
complex operator*(complex a, complex b) { return a *= b; };
complex operator/(complex a, complex b) { return a /= b; };

bool operator==(complex a, complex b) {
    return a.real() == b.real() && a.imag() == b.imag();
}
bool operator!=(complex a, complex b) {
    return !(a==b);
}

complex sqrt(complex);

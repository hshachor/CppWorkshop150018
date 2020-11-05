#pragma once
#include <iosfwd>

class Rational {
private:
    int mone;
    int mechane;
public:

    //constructor
    Rational(int Mone = 1, int Mechane = 1) :mone(Mone), mechane(Mechane) {}
    Rational(const Rational& num) :mone(num.getMone()), mechane(num.getMechane()) {}

    //modify functions
    void setMone(int Mone) { mone = Mone; }
    void setMechane(int Mechane) { mechane = Mechane; }

    //view functions
    int getMone() const { return mone; }
    int getMechane() const { return mechane; }

    //operations
    Rational operator+(const Rational&) const;
    Rational operator-(const Rational&) const;
    Rational operator*(const Rational&) const;
    Rational operator/(const Rational&) const;
    Rational& operator=(const Rational&);
    bool operator==(const Rational&) const;
    friend Rational operator *(const Rational&, int);
    friend Rational operator *(int, const Rational&);

    //input/output
    friend std::ostream& operator<<(std::ostream& os, const Rational& num);
    friend std::istream& operator>>(std::istream& is, Rational& num);

};

#include "Rational.h"
#include <iostream>

using std::ostream;
using std::istream;

Rational Rational::operator +(const Rational& num) const
{
    Rational tmp;
    tmp.setMone(mone * num.getMechane() + num.getMone() * mechane);
    tmp.setMechane(mechane * num.getMechane());
    return tmp;
}

Rational Rational::operator -(const Rational& num) const
{
    Rational tmp;
    tmp.setMone(mone * num.getMechane() - num.getMone() * mechane);
    tmp.setMechane(mechane * num.getMechane()); return tmp;
}

Rational Rational::operator *(const Rational& num) const
{
    Rational tmp;
    tmp.setMone(mone * num.getMone());
    tmp.setMechane(mechane * num.getMechane());
    return tmp;
}

Rational Rational::operator /(const Rational& num) const
{
    Rational tmp;
    tmp.setMone(mone * num.getMechane());
    tmp.setMechane(mechane * num.getMone());
    return tmp;
}

Rational& Rational::operator =(const Rational& num)
{
    mone = num.getMone();
    mechane = num.getMechane();
    return *this;
}

bool Rational::operator ==(const Rational& num) const
{
    return mone == num.getMone() && mechane == num.getMechane(); // bad implementation!
}

Rational operator *(const Rational& rat, int num)
{
    Rational tmp;
    tmp.setMone(rat.mone * num);
    tmp.setMechane(rat.mechane * num);
    return tmp;
}

Rational operator *(int num, const Rational& rat)
{
    return rat * num;
}

ostream& operator<<(ostream& os, const Rational& num)
{
    os << num.mone; os << '/';
    os << num.mechane;
    os << std::endl;
    return os;
}

istream& operator>>(istream& is, Rational& num)
{
    is >> num.mone;
    char slash;
    is >> slash;
    is >> num.mechane;
    return is;
}

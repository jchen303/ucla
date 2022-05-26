#include "ComplexFracs.hpp"


void ComplexFrac::print() const
{
    if (!real.isZero())
    {
        real.print();
        if (imag.isPositive()) { std::cout << "+"; }
    }
    if (!imag.isZero()) { imag.print();  std::cout << "*i"; }
    if ( real.isZero() && imag.isZero() ) { std::cout << 0; }
}

ComplexFrac ComplexFrac::add(const ComplexFrac& secFrac) const
{
    return ComplexFrac(real.add(secFrac.real), imag.add(secFrac.imag));
}

ComplexFrac ComplexFrac::subtract(const ComplexFrac& secFrac) const
{
    return ComplexFrac(real.subtract(secFrac.real), imag.subtract(secFrac.imag));
}

ComplexFrac ComplexFrac::multiply(const ComplexFrac& secFrac) const
{
    Frac rl = ((real.multiply(secFrac.real)).subtract(imag.multiply(secFrac.imag)));
    Frac im = ((real.multiply(secFrac.imag)).add(imag.multiply(secFrac.real)));
    return ComplexFrac(rl, im);
}

ComplexFrac ComplexFrac::divide(const ComplexFrac& secFrac) const
{
    Frac bot1(secFrac.real.multiply(secFrac.real));
    Frac bot2(secFrac.imag.multiply(secFrac.imag));
    Frac rl = secFrac.real.divide(bot1.add(bot2));
    Frac im = (secFrac.imag.multiply(Frac(-1))).divide(bot1.add(bot2));
    const ComplexFrac sec(rl, im);
    return multiply(sec);
}

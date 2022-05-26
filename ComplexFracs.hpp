#ifndef ComplexFracs_hpp
#define ComplexFracs_hpp

#include "Fracs.hpp"

class ComplexFrac {
public:
/**
    constructors from 1-5:
    - no parameter sets the complex # equal to 0
     sets
    - _real makes complex # w/ imaginary # set to 0
    - _real is the frac for the real #, _imag is the frac for imaginary #
    - n is the real # (whole number, not a fraction), imaginary # set to 0
    - reNum and reDen create the fraction for real #, imNum and imDen create
    the fraction for the imaginary #
 */
    ComplexFrac() : real(0), imag(0) {}
    ComplexFrac(Frac _real) : real(_real), imag(0) {}
    ComplexFrac(Frac _real, Frac _imag) : real(_real), imag(_imag) {}
    ComplexFrac(int n) : real(n), imag(0) {}
    ComplexFrac(int reNum, int reDen, int imNum, int imDen) :
                     real(reNum, reDen), imag(imNum, imDen) {}
/**
    @param secFrac : reference to complexFrac which you are comparing to
    - checks whether a=c and b=d for a+bi and c+di
    @return true if the complexFracs are equal, false otherwise
 */
    bool isEqual(const ComplexFrac& secFrac) const
    {
        if (real.isEqual(secFrac.real) && imag.isEqual(secFrac.imag))
        {
            return true;
        }
        return false;
    }
/**
    - prints out the complex fraction, does not modify it in any way
 */
    void print() const;
/**
    @param secFrac : reference to complexFrac you are adding to, subtracting from,
    multiplying by, or dividing by the implicit complexFrac
    - does not modify the original complexFracs
    @return complexFrac that is the result of the arithmetic function
    performed
 */
    ComplexFrac add(const ComplexFrac& secFrac) const;
    ComplexFrac subtract(const ComplexFrac& secFrac) const;
    ComplexFrac multiply(const ComplexFrac& secFrac) const;
    ComplexFrac divide(const ComplexFrac& secFrac) const;

private:
    Frac real;
    Frac imag;
};

#endif /* ComplexFracs_hpp */

#ifndef Fracs_hpp
#define Fracs_hpp

#include <iostream>
#include <cassert>
#include <algorithm>

class Frac {
public:
    Frac(int _num)           : num(_num), den(   1) {                              }
    Frac(int _num, int _den) : num(_num), den(_den) { assert(den != 0);
                                                      makeDenomPos(); Msimplify(); }

    Frac()                   : num(   0), den(   1) {
        std::cout << "You just called the default constructor    " << std::endl;
        std::cout << "for Frac. If you think that you didn't,    " << std::endl;
        std::cout << "ask yourself whether you failed to use an  " << std::endl;
        std::cout << "initializer list when you should have done." << std::endl;
        std::cout << "If you did intend to use the default       " << std::endl;
        std::cout << "constructor, don't! Remember... I broke it!" << std::endl;
        exit(1);
    }

    void print() const { std::cout << num; if(den != 1) { std::cout << "/" << den; } }

    Frac add     (const Frac& other) const;
    Frac subtract(const Frac& other) const;
    Frac multiply(const Frac& other) const;
    Frac divide  (const Frac& other) const;

    // The following functions make use of the fact that
    // all of our fractions have positive denominators
    // and that they are simplified as much as possible.
    bool isEqual (const Frac& other) const { return (num == other.num) && (den == other.den); }

    bool isZero()     const { return num == 0; }
    bool isPositive() const { return num >  0; }

private:
    int num;
    int den;

    void makeDenomPos() { if (den <  0) { num *= -1; den *= -1; } }
    void makeZeroNice() { if (num == 0) {            den  =  1; } }

    void  simplify();
    void Msimplify(); // Michael's simplify - uses the Euclidean algorithm
};

#endif /* Fracs_hpp */

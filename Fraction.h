//
//  Fraction.h
//  Fractions
//
//  Created by Aaron on 9/13/15.
//  Copyright (c) 2015 Aaron. All rights reserved.
//

#ifndef __Fractions__Fraction__
#define __Fractions__Fraction__
#include <stdio.h>
#include <iostream>
using namespace std;
//#include <stdio.h>

class Fraction
{
public:
    Fraction(); // default construction
    Fraction(int numerator, int denominator); // overloaded construction
    
    friend std::ostream &operator<<( std::ostream&, const Fraction&);
    
    // Fraction(const Fraction &original); copy constructor    
    // Assingment x = y is built in
    
    void print();   // prints (to cout) a visual form of the fraction, i.e. x/y
    
    void reduceme(); // ensures that this instance is fully reduced
    
    bool reducible(); // returns a bool indicating value can/cannot be reduced
    
    Fraction reduce();  // returns a new fraction, fully-reduced version of original
    
    
    //returns the sum of two fractions
    static Fraction add(Fraction &x, Fraction &y);
    
    // non-member function returning a bool indicating if x < y
    static bool lessThan(const Fraction &x,const Fraction &y);
    //getters and setters
    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int x);
    void setDenominator(int x);

private:
    int numerator;
    int denominator;
    
};

#endif /* defined(__Fractions__Fraction__) */

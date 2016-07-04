//
//  ProperFraction.hpp
//  Fractions
//
//  Created by Aaron on 10/11/15.
//  Copyright © 2015 Aaron. All rights reserved.
//

#ifndef ProperFraction_hpp
#define ProperFraction_hpp
#include "Fraction.h"
#include <stdio.h>
using namespace std;

class ProperFraction : public Fraction{
    
public:
    ProperFraction(); // default construction
    ProperFraction(int numerator, int denominator); // overloaded construction
    int makeProper(); //returns the whole number if the numerator is higher than the denominator
    void print();
    static ProperFraction add(ProperFraction &x,ProperFraction &y);
    static bool lessThan(ProperFraction &x,ProperFraction &y);
    int getWholeNumber();
    void setWholeNumber(int x);

private:
    int wholeNumber;


};

    
    
    

#endif /* ProperFraction_hpp */

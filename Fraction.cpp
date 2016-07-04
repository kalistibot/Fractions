//
//  Fraction.cpp
//  Fraction
//
//  Created by Aaron on 9/13/15.
//  Copyright (c) 2015 Aaron. All rights reserved.
//

#include "Fraction.h"
#include "FractionMath.h"
#include <iostream>
using namespace std;

Fraction::Fraction(){
    this->numerator = 0;
    this->denominator =1;

} //end default constructor

Fraction::Fraction(int num, int dem){
    this->numerator = num;
    
    if(dem ==0)
    {
        std::cout<<"Divide by zero error : Fraction Created as 0/1 \n";
        this->numerator =0;
        this->denominator = 1;
    }
    else
        this->denominator = dem;
} //end overloaded constructor


/*  definition of implicit copy constructor
 Fraction::Fraction(const Fraction  &original){
    Fraction newFraction;
 newFraction = original;
} //end copy constructor
*/

ostream &operator<<( std::ostream &output , const Fraction &f1){
    
    output<< f1.numerator<<"/"<<f1.denominator;
    return output;
}

void Fraction::print(){

    std::cout<< this->numerator<<"/"<<this->denominator;

}





int Fraction::getNumerator()const{
    return  this->numerator;
}

int Fraction::getDenominator()const{
    return this->denominator;
}

void Fraction::setNumerator(int x){
    this->numerator = x;
}

void Fraction::setDenominator(int x){
    this->denominator = x;
}

// returns true if the fraction is reducible
bool Fraction::reducible(){
    return (GCD(this->numerator,this->denominator)>1);
    
}


// returns true if the first fraction object is less than the second one
bool Fraction::lessThan(const Fraction &x, const Fraction &y){
    
    int xdenom = x.denominator;
    int xnumer = x.numerator;
    int ydenom = y.denominator;
    int ynumer = y.numerator;
    int lcm = LCM(xdenom,ydenom);
    int newxnumer = xnumer *(lcm/xdenom);
    int newynumer = ynumer *(lcm/ydenom);
    if (newxnumer > newynumer){
        return false;
    }
    return true;
}


// Function for reducing the fraction by reference
void Fraction::reduceme(){
    
    
    int gcd = GCD(this->getNumerator(),this->getDenominator());
    if(gcd!=1)
    {
        this->setNumerator(this->getNumerator()/gcd);
        this->setDenominator(this->getDenominator()/gcd);
    }
    
    
}


//returns a reduced fraction object
Fraction Fraction::reduce(){
    Fraction reduced;
    int gcd = GCD(this->numerator,this->denominator);
    if(gcd!=1)
    {
        reduced.setNumerator(this->getNumerator()/gcd);
        reduced.setDenominator(this->getDenominator()/gcd);

        return reduced;
    }
    
    return *this;
}

//add two fraction objects
Fraction Fraction::add(Fraction &x, Fraction &y) {
    Fraction sum;
    //check first if they are the same, if not
    int xdenom = x.Fraction::getDenominator();
    int xnumer = x.Fraction::getNumerator();
    int ydenom = y.Fraction::getDenominator();
    int ynumer = y.Fraction::getNumerator();
    
    if (! (x.Fraction::getDenominator() == y.Fraction::getDenominator())) {
        
        int lcm = LCM(xdenom,ydenom);
        int newxnumer = xnumer *(lcm/xdenom);
        int newynumer = ynumer *(lcm/ydenom);
        int sumnumer = newxnumer +newynumer;
        Fraction newSum(sumnumer, lcm);
        sum = newSum;
    }else{
        int sumnumer = xnumer +ynumer;
        Fraction newSum(sumnumer, xdenom);
        sum = newSum;
    }
    return sum;
}

/*  a different way
 Fraction add(const Fraction &x, const Fraction &y) {
 Fraction sum;
 int xdenom = x.denominator;
 int xnumer = x.numerator;
 int ydenom = y.denominator;
 int ynumer = y.numerator;
 //check first if they are the same, if not
 if (! (x.denominator == y.denominator)){
 
 int lcm = LCM(xdenom,ydenom);
 int newxnumer = xnumer *(lcm/xdenom);
 int newynumer = ynumer *(lcm/ydenom);
 int sumnumer = newxnumer +newynumer;
 Fraction newsum(sumnumer, lcm);
 sum = newsum;
 }else{
 int sumnumer = xnumer +ynumer;
 Fraction newsum(sumnumer, xdenom);
 sum = newsum;
 }
 
 return sum;
 }
 
 */

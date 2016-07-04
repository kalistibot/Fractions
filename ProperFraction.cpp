//
//  ProperFraction.cpp
//  Fractions
//
//  Created by Aaron on 10/11/15.
//  Copyright © 2015 Aaron. All rights reserved.
//
#include <iostream>
#include "ProperFraction.hpp"
using namespace std;
ProperFraction::ProperFraction()
    :Fraction(){
    
} //end default constructor


ProperFraction::ProperFraction(int numerator, int denominator)
    :Fraction(numerator,denominator)
{
    this->wholeNumber =makeProper();
    
}// end overloaded construction


int ProperFraction::makeProper(){
    //check to see if the numerator is greater than the denominator;
    int tempN =0;
    int tempD = 0;
    int wholeNumber = 0;
    int newN = 0;
    if (this->getNumerator()<this->getDenominator()){
        return wholeNumber;
        
    }else{
        tempN = this->getNumerator();
        tempD = this->getDenominator();
        wholeNumber= (tempN/tempD);
        newN = tempN %tempD;
        this->setNumerator(newN);
        return wholeNumber;
    }
}

void ProperFraction::print(){
    if (this->getWholeNumber() == 0) {
        this->Fraction::print();
    }else if (this->getNumerator()>0) {

        std::cout<< this->wholeNumber<< " & "<< this->getNumerator()<< "/"<< this->getDenominator();
    }else{
        std::cout<<this->wholeNumber;
    }
}


ProperFraction ProperFraction::add(ProperFraction &x,ProperFraction &y){

    //This calls the add function from the Fraction class
    // but has to handle the fact that now whole numbers are involved
    Fraction tempFraction;
    int newWhole = 0;
    newWhole+= (x.getWholeNumber()+ y.getWholeNumber());
    tempFraction = Fraction::add(x, y);
    ProperFraction tempProper(tempFraction.getNumerator(),tempFraction.getDenominator());
    tempProper.reduceme();
    tempProper.setWholeNumber(tempProper.getWholeNumber()+newWhole);
    return tempProper;
}

int ProperFraction::getWholeNumber(){
    return this->wholeNumber;
}

void ProperFraction::setWholeNumber(int x){
    this->wholeNumber = x;
}

bool ProperFraction::lessThan(ProperFraction &x, ProperFraction &y) {
    // return true if the lvalue is lower than the rvalue.
    // Starts with whole numbers
    if ((y.getWholeNumber())>(x.getWholeNumber())) {
        return true;
    }
    else if (Fraction::lessThan(x, y)&& (x.getWholeNumber()>!y.getWholeNumber())){
        return true;
    }else{
        return false;
        }
    
}
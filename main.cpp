//
//  Testing
//  Fractions and ProperFractions classes
//
//  Created by Aaron on 9/10/15. Revised on 10/11 and on 10/17
//  Copyright (c) 2015 Aaron. All rights reserved.
//
#include "ProperFraction.hpp"
#include <iostream>
#include "Fraction.h"
#include <functional>
using namespace std;

template<typename Fraction>

//function
bool increasing_order(Fraction f1, Fraction f2)
{
    return Fraction::lessThan(f1,   f2);
}


/*
//sort function takes array, size and here a pointer to a function
void mysort(Fraction arr[], int size, bool(*predicate)(Fraction, Fraction));

//using function pointer
void mysort(Fraction arr[], int size,
          bool(*predicate)(Fraction, Fraction))
{
    bool Swaps;
    Fraction temp;
    do
    {
        Swaps = false;
        for (int i = 0; i < size - 1; ++i)
            if (!predicate(arr[i], arr[i + 1]))
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                Swaps = true;
            }
    } while (Swaps);
}


*/
//functor

class my_order {
public:
    bool operator()(Fraction f1, Fraction f2) const
    {
        return Fraction::lessThan(f1, f2);
    }
};

/*
template<typename Fraction>

void functorSort(Fraction arr[], int size,
            my_order predicate)
{
 
    
    bool Swaps;
    Fraction temp;
    do
    {
        Swaps = false;
        for (int i = 0; i < size - 1; ++i)
            if (!predicate(arr[i], arr[i + 1]))
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                Swaps = true;
            }
    } while (Swaps);
}

*/
template<typename Fraction>

void flexiSort(Fraction arr[], int size,
                 function<bool(Fraction,Fraction)> anySort)
{
    
    
    bool Swaps;
    Fraction temp;
    do
    {
        Swaps = false;
        for (int i = 0; i < size - 1; ++i)
            if (!anySort(arr[i], arr[i + 1]))
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                Swaps = true;
            }
    } while (Swaps);
}




int main(int argc, const char * argv[]) {
    
    cout <<" With a function Pointer \n";
    Fraction f1(1,2),f2(3,5),f3(5,7),f4(4,9),f5(3,4);
    Fraction arr[5] = {f1 ,f2, f3, f4, f5};
    cout << "before:";
    for (int i = 0; i < 5;  ++i){
        cout <<"\t"; (arr[i]).Fraction::print();
    }
    bool (*sortPtr)(Fraction,Fraction) = increasing_order;
    //mysort(arr, 5, sortPtr);
 
    flexiSort<Fraction>(arr,5,sortPtr);
    
    cout << "\nafter:";
    for (int i = 0; i < 5;  ++i){
        cout <<"\t" ; arr[i].Fraction::print();
    }
    
    //Now with a Functor
    cout << "\n Now with a functor";
    my_order increasing;
    Fraction f6(3,2), f7(4,5), f8(6,7),f9(7,9),f10(8,4);
    Fraction arr2[5] = {f6 ,f7, f8, f9, f10};
    cout << "\nbefore:";
    for (int i = 0; i < 5;  ++i){
        cout <<"\t"; (arr2[i]).Fraction::print();
    }
    //functorSort(arr2, 5, increasing);
    flexiSort<Fraction>(arr2,5,increasing);
    cout << "\nafter:";
    for (int i = 0; i < 5;  ++i){
        cout <<"\t" << arr2[i];
    }
    cout<< "\n Now for the Lambda";
    Fraction f11(9,2), f12(8,5),f13(4,7),f14(2,9),f15(5,4);
    Fraction arr3[5] = {f11,f12,f13,f14,f15};
    
    cout << "\nbefore:";
    for (int i = 0; i < 5;  ++i){
        cout <<"\t"<<(arr3[i]);
    }
    flexiSort<Fraction>(arr3,5,[](Fraction f1,Fraction f2) {return Fraction::lessThan(f1,f2);});
    
    cout << "\nafter:";
    for (int i = 0; i < 5;  ++i){
        cout <<"\t" << arr3[i];
    }
    cin.get();
    return 0;
}


    
    /* Testing ProperFraction class
    int numerator =0;
    int denominator =1;
    cout << "Let's try this\n";
    cout << "Proper Fraction Test" << endl;
    cout<<"numerator please:";
    cin >> numerator;
    cout<<"denominator:";
    cin >> denominator;
    ProperFraction raspberry = ProperFraction(numerator,denominator);
    cout << "The numerator is "<< raspberry.getNumerator()<<endl;
    cout << "The denominator is "<< raspberry.getDenominator()<<endl;
    raspberry.print(); cout<<endl;
    if(raspberry.reducible()){
    cout<< "this fraction is reducible to "<<endl;
    raspberry.reduceme();
    raspberry.print();
    }
    cout << endl<< "Now lets compare. \nAnother numerator please: "<< endl;
    cin >> numerator;
    cout << "denominator: "<< endl;
    cin >> denominator;
    ProperFraction grape = ProperFraction(numerator,denominator);
    if (ProperFraction::lessThan(raspberry,grape )){
        raspberry.print(); cout << " is less than "; grape.print();
    }else{
        raspberry.print(); cout <<" is not less than "; grape.print();
    }
    
    ProperFraction sum = ProperFraction::add(raspberry,grape);
    cout<< "\nTheir sum is "; sum.ProperFraction::print();
    
    cout << "one more thing... a reducible fraction. \n numerator:";
    cin >> numerator;
    cout << "denominator: ";
    cin >> denominator;
    ProperFraction orange(numerator,denominator);
    (orange.reduce()).print();
    
    cout << endl;
     */
    /*
     
    //All of this code was to test the Fraction class.
    Fraction vanilla;
    Fraction chocolate = Fraction(numerator,denominator);
    Fraction strawberry =Fraction(chocolate);
    cout << "default constructor \n";
    vanilla.Fraction::print();
    cout<<"\n";
    cout << "with your inputs\n";
    chocolate.Fraction::print();
    cout<<"\n";
    cout<<"The copy:\n";
    strawberry.Fraction::print();
    cout<<"\n";
    strawberry = vanilla;
    cout <<"Reassigning the copy to the default\n";
    strawberry.Fraction::print();
    if (chocolate.Fraction::reducible()){
        cout<< "\n The fraction "; chocolate.Fraction::print();cout << " is reducible\n"<<endl;
        chocolate.Fraction::reduceme();
        cout << "The reduced fraction is: ";
        chocolate.Fraction::print();
        cout <<"\n";
    }else{
        cout <<"\n The fraction "; chocolate.Fraction::print();cout << " is not reducible\n";
    }
    
    cout<<"Let's add a fraction to that \n";
    cout<<"numerator please:";
    cin >> numerator;
    cout<<"denominator:";
    cin >> denominator;
    Fraction caramel = Fraction(numerator,denominator);
       Fraction turtle =  Fraction::add(caramel, chocolate);
    cout << "The sum of "; chocolate.Fraction::print(); cout << " and "; caramel.Fraction::print();
    cout << ": "; turtle.Fraction::print();cout<<"\n";
    if (Fraction::lessThan(chocolate,caramel)){
        cout <<"The fraction "; chocolate.Fraction::print(); cout <<" is less than "; caramel.Fraction::print();
        cout << "\n";
    }else{
        cout <<"The fraction "; caramel.Fraction::print(); cout <<" is not less than "; chocolate.Fraction::print();
        cout <<"\n";

    }
    cout << " one more time... A fraction to be reduced...\n give me a numerator: ";
    cin >>numerator;
    cout << " denominator:";
    cin >> denominator;
    Fraction blueberry(numerator,denominator);
    Fraction cheesecake;
    cheesecake = blueberry.Fraction::reduce();
    
    
   // cout << "The reduced fraction is " ;cheesecake.Fraction::print(); cout <<"\n";
}
     */
#include <iostream>
#include "fraction.h"
using namespace std;



// Prints the fraction in terms ( numerator / denominator).


void fraction::print() const
{
    cout << numerator << "/" << denominator;

}


// first constructor: every fraction object, if declared( but not initialized)  is set to 
//   0/1. It is also reduced to lowest terms.



fraction::fraction()
{
    numerator = 0;
    denominator = 1;
    Reduce();       

}


// Second constructor: every fraction object, if declared and initialized, is also
// reduced to its lowest terms. inNumerator is the numerator, inDenominator is the denominator 



fraction::fraction (int inNumerator, int inDenominator)
{
    numerator = inNumerator;
    denominator = inDenominator;
    Reduce();      

}



// Function that multiplies two fractions together. parameter fraction value 
// is used as the second fraction's numerator and denominator. An additional
// fraction object is declared (tempMul), and returns that same multiplied 
// fraction, after tempMul has been reduced.



fraction fraction::MultipliedBy (fraction value) const
{
    fraction tempMul;                                   // The temporary value of the multiplied fractions
    tempMul.numerator = numerator * value.numerator;       
    tempMul.denominator = denominator * value.denominator;
    tempMul.Reduce();
    return tempMul;  

}



// Function that divides two fractions. parameter fraction value 
// is used as the second fraction's numerator and denominator. An additional
// fraction object is declared (tempDiv), and returns that same divided
// fraction, after tempDev has been reduced.



fraction fraction::DividedBy(fraction value) const
{
    fraction tempDiv;                              // The temporary value of the divided fractions
    tempDiv.numerator = numerator * value.denominator ;       
    tempDiv.denominator = denominator * value.numerator;  
    tempDiv.Reduce();
    return tempDiv;

}




// Function that subtracts one fraction from another parameter fraction value 
// is used as the second fraction's numerator and denominator. An additional
// fraction object is declared (tempSub), and returns that same subtracted 
// fraction, after tempSub has been reduced.




fraction fraction::Subtract(fraction value) const
{
    fraction tempSub;                            // The temporary value of the subtracted fractions
    tempSub.numerator = (numerator * value.denominator) - (value.numerator * denominator);
    tempSub.denominator = (denominator * value.denominator);
    tempSub.Reduce();
    return tempSub;

}


// Function that adds two fractions together. parameter fraction value 
// is used as the second fraction's numerator and denominator. An additional
// fraction object is declared (tempAdd), and returns that same added
// fraction, after tempAdd has been reduced.



fraction fraction:: AddedTo( fraction value) const
{
    fraction tempAdd;                          // The temporary value of the added fractions
    tempAdd.numerator = (numerator * value.denominator) + (value.numerator * denominator);
    tempAdd.denominator = (denominator * value.denominator);
    tempAdd.Reduce();
    return tempAdd;

}


// Function which tests whether two fractions are each two. It does this by
// testing whether numerator/denominator is equal to the parameter fraction value
// value.numerator/value.denominator. If they are, then the function returns true.




bool fraction:: isEqualTo(fraction value) 
{   
    if(  (numerator/denominator)==(value.numerator/value.denominator)){
               return true;
    }               

} 




/*

This fraction reduces the function. It does this by finding the GCF. At first, 
at the start of the for loop, the gcf is set to = denominator * numerator.
But the if statement checks whether the denominator can be divided by the GCF 
w/o any remaineder and if the numerator can be divided by the GCF w/o any remainder.
If both can be divided by the same factor, gcf decrements until it finds the greatest number
both the numerator and denominator can be divided by. Then, the denominator and the numerator 
are both divided by the proper GCF.

*/




void fraction::Reduce() 
{
    int gcf;                    // The greatest common factor of the two fractions 
   
    for ( gcf = denominator * numerator; gcf > 1; gcf--) {  
         if ((denominator % gcf == 0) && (numerator % gcf == 0)) {  
            denominator = denominator/gcf;  
            numerator  = numerator/gcf;  
    }                 
   
    }        
}
        


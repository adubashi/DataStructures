
#ifndef FRACTION_H
#define FRACTION_H


/*
This class is a fraction class. It allows 
the client programmer to declare a single fraction object,
rather than continually declaring a numerator and denominator.
This class has 9 different functions. There are 5 different operations 
that can be performed; MultipliedBy, DividedBy, Subtract,AddedTo
, isEqualTo(to test whether two frations are equal. In addition, 
the void reduce makes sure that the fractions are always stored 
in their lowest terms.
There are two constructors, the first takes in the fraction's numerator 
and denominator and reduces them, the second initializes the result of any operation
to zero.


Public Member Functions( Pre and Post conditions):
       
Void print() const -- Pre: one fraction object being applied. Post: Prints the numerator
fraction(int, int) -- Pre: two int variables, post: declared as a fraction object
fraction --- Pre: Numerator and Denominator(0 and 1), post;  declared as a fraction object
fraction MultipliedBy(fraction value)--- Pre:  Two  fraction objects/ Post : returns the multiplication of two fractions
fraction DividedBy(fraction value) const---Pre: Two  fraction objects/ Post: returns the division of two fractions
fraction Subtract(fraction value) const;---Pre: Two  fraction objects/ Post: returns the subtraction of two fractions
fraction AddedTo( fraction value) const;---Pre: Two  fraction objects/ Post: returns the addition of two fractions
bool isEqualTo(fraction value);---Pre: Two fraction objects/ Post: either returns true or false 
void Reduce();---Pre: One fraction object/ Post: fraction object reduced to lowest terms.





*/
class fraction {
    public:
    void print() const;                             // Prototype: prints the fraction in form: numerator/denominator
    fraction(int, int);                            // Prototype: constructor: initializes the fraction with numbers entered by client programmer
    fraction();                                   //  Prototype: constructor:un initilized fraction declared as 0/1
    fraction MultipliedBy(fraction value) const;  // Prototype: multiplied together
    fraction DividedBy(fraction value) const;     // Prototype: divided from one another 
    fraction Subtract(fraction value) const;      // Prototype: subtracted from one another 
    fraction AddedTo( fraction value) const;      // Prototype: adds together
    bool isEqualTo(fraction value);               // Prototype: Checks whether they are equal
    void Reduce();                                // Prototype: reduces the fractions to their lowest terms.
      
      
    private:
    int numerator;          // The Numerator of the fraction
    int denominator;        // The Denominator of the fraction

};

#endif

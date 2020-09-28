#ifndef FRACTIONS_CPP
#define FRACTIONS_CPP

#include <iostream>

typedef struct fraction_s{
    int num;
    int den;
} fraction_t;

fraction_t sum_fractions(fraction_t *frac1, fraction_t *frac2);
fraction_t simplify(fraction_t *frac);
int MCD(int n1, int n2);
void print_fraction(fraction_t *frac); 

int main(){
    fraction_t frac1;
    fraction_t frac2;
    fraction_t frac_result;
    fraction_t frac_simplify;
    //Request fractions
    std::cout << "Introduce num frac1: ";
    std::cin >> frac1.num;
    std::cout << "Introduce den frac1: ";
    std::cin >> frac1.den;
    std::cout << "Introduce num frac2: ";
    std::cin >> frac2.num;
    std::cout << "Introduce den frac2: ";
    std::cin >> frac2.den;
    //print fractions
    std::cout << "Fraction 1: \n";
    print_fraction(&frac1);
    std::cout << "Fraction 2: \n";
    print_fraction(&frac2);
    //Add fractions
    std::cout << "Adding fractions\n";
    frac_result = sum_fractions(&frac1, &frac2);
    std::cout << "result: \n";
    print_fraction(&frac_result);
    //Simplify fraction
    std::cout << "Simplify fraction \n";
    frac_simplify = simplify(&frac_result);
    std::cout << "simplify: \n";
    print_fraction(&frac_simplify);
    return 0;
}

fraction_t sum_fractions(fraction_t *frac1, fraction_t *frac2){
    fraction_t result;
    result.den = frac1->den * frac2->den;
    result.num = (frac1->num*frac2->den)+(frac2->num*frac1->den);
    return result;
}

fraction_t simplify(fraction_t *frac){
    fraction_t result;
    int mcd = MCD(frac->num, frac->den);
    result.num = frac->num/mcd;
    result.den = frac->den/mcd;
    return result;
}

int MCD(int n1, int n2){
    int result = 1;
    int factor = 2;

    while (factor <= n1 || factor <= n2){
        while(!(n1 % factor)&&!(n2 % factor)){
            result *= factor;
            n1 /= factor;
            n2 /= factor;
        }
        if (factor == 2) factor++;
        else factor +=2;
    }
    return result;
}

void print_fraction(fraction_t *frac){
    std::cout << " " << frac->num << "\n";
    std::cout << "---\n";
    std::cout << " " << frac->den << "\n";
} 


#endif //FRACTIONS_CPP
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#define NICKEL 5
#define DIME  10
#define QUARTER 25
#define DOLLAR  100


void user_input(float *input){

    printf("\nEnter dollar amount: ");
    scanf("%f", input);
    
    if ( *input < 0 ) 
        user_input(input);
}

void check_for_quarters(uint16_t *quarts, uint16_t *pens){
    uint8_t remainder = *pens % DOLLAR;

    *pens /= DOLLAR;

    // calculate number of quarters from the dollar amount
    *quarts = ( *pens > 0 ) ? ( *pens * (DOLLAR / QUARTER) ) : 0;

    if (remainder > QUARTER){
        *pens = remainder % QUARTER;
        remainder /= QUARTER;
        *quarts += remainder;
    }
    else{
        *pens = remainder;
    }
}

void check_for_dimes(uint16_t *dimes, uint16_t *pens){
    *dimes = *pens / DIME;
    *pens %= DIME;
}

void check_for_nickels(uint16_t *nicks, uint16_t *pens){
    *nicks = *pens / NICKEL;
    *pens %= NICKEL;
}

int main(){
    float       amount;
    uint16_t    quarters;
    uint16_t    dimes;
    uint16_t    nickels;
    uint16_t    pennies;

    user_input(&amount);
    // printf("\n%p holds %.2f", (void *)&amount, amount);

    pennies = amount * DOLLAR;

    while ( pennies > NICKEL ){
        check_for_quarters(&quarters, &pennies);
        printf("\nQuarters: %u", quarters);

        check_for_dimes(&dimes, &pennies);
        printf("\nDIMES: %u", dimes);

        check_for_nickels(&nickels, &pennies);
        printf("\nNickels: %u", nickels);

        printf("\nPennies: %u", pennies);
    }
}
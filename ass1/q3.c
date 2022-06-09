#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

void user_input(uint8_t *input){

    printf("Enter month number: ");
    scanf("%u", input);
    
    if ( *input <= 0 || *input >= 13 ) 
        user_input(input);
}

int main(){
    uint8_t month;

    user_input(&month);

    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        printf("31 Days\n");
        break;
    
    case 4:
    case 6:
    case 9:
    case 11:
        printf("30 Days\n");
        break;
    
    default:
        printf("28 or 29 Days depending on leap year existence\n");
        break;
    }

}
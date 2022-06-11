#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

void user_input(uint8_t *input){

    printf("Enter number of rows: ");
    scanf("%u", input);
    
    if ( *input <= 0 || *input >= 11 ) 
        user_input(input);
}

int main(){

    uint8_t input;
    user_input(&input);

    uint8_t rows = 2*input - 1;

    for (int i=1; i <= rows; i++){
        int space_idx   = abs(input - i);
        int star_idx    = rows - 2 * space_idx;

        for (int j=1; j <= rows; j++){
            if ( space_idx > 0 || \
                (space_idx < 0 && star_idx <= 0) ){
                printf(" ");
            }
            else if ( space_idx == 0 || star_idx > 0 ){
                printf("*");
                star_idx--;
            }
            else{
                printf("?");
            }
            space_idx--;
        }
        printf("\n");
    }

    return 0;
}
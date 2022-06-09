#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// - not the best approach but i just wanted to practice #ifdef directives
// - comment and uncomment for if-else vs case-switch conditions
//#define if_else_cond True

int user_input(){

    int input;

    printf("Enter %: ");
    scanf("%d", &input);
    
    return ( input < 0 || input > 100 ) ? user_input() : input;
}

char is_correct_grade_window(int gpa_12){
    char grade =    ( gpa_12 >= 90 && gpa_12 <= 100 ) ? 'A' : \
                    ( gpa_12 >= 85 && gpa_12 <= 89 ) ? 'B' : \
                    ( gpa_12 >= 80 && gpa_12 <= 84 ) ? 'C' : \
                    ( gpa_12 >= 77 && gpa_12 <= 79 ) ? 'D' : 'E';
    
    return grade;
}

int main(){

    int percent = user_input();
    // printf("\n%p holds %d", (void *)&percent, percent);

    #ifdef if_else_cond

        if ( percent >= 90 && percent <= 100 ){
            printf("\nGPA: 4.0");
        }
        else if ( percent >= 85 && percent <= 89 ){
            printf("\nGPA: 3.9");
        }
        else if ( percent >= 80 && percent <= 84 ){
            printf("\nGPA: 3.7");
        }
        else if ( percent >= 77 && percent <= 79 ){
            printf("\nGPA: 3.3");
        }
        else {
            printf("\nGPA below or equal to 3.0 ");
        }
    
    #endif

    #ifndef if_else_cond

        char grade_4 = is_correct_grade_window(percent);
        // printf_s("%c", grade_4);

        switch (grade_4)
        {
        case 'A':
            printf("\nGPA: 4.0");
            break;
        
        case 'B':
            printf("\nGPA: 3.9");
            break;

        case 'C':
            printf("\nGPA: 3.7");
            break;
        
        case 'D':
            printf("\nGPA: 3.3");
            break;

        default:
            printf("\nGPA below or equal to 3.0 ");
            break;
        }
    
    #endif

    return 0;
}
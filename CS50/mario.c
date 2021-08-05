#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int total_height;
    int dinamic_height;
    int spaces;
    int blocks;

    total_height = 0;
    while (total_height < 1 || total_height > 8)
    {
        total_height = get_int("Height:  ");
    }
    dinamic_height = total_height;
    while (dinamic_height > 0)
    {
        // prints the left half of the pyramid
        spaces = dinamic_height - 1;
        blocks = total_height - spaces;
        while (spaces > 0)
        {
            printf(" ");
            spaces--;
        }
        while (blocks > 0)
        {
            printf("#");
            blocks--;
        }
        printf("  ");
        // prints the right half of the pyramid
        spaces = dinamic_height - 1;
        blocks = total_height - spaces;
        while (blocks > 0)
        {
            printf("#");
            blocks--;
        }
        printf("\n");
        dinamic_height--;
    }
}

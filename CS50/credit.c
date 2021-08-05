#include <cs50.h>
#include <stdio.h>

// check if char is number
int isnumber(char nbr)
{
    if (nbr >= '0' && nbr <= '9')
    {
        return (1);
    }
    return (0);
}

// gets a valid input from user
char *get_number()
{
    char *card_number;
    int check_input;
    int i;

    check_input = 0;
    while (check_input != 1)
    {
        card_number = get_string("Number: ");
        check_input = 1;
        i = 1;
        while (card_number[i] != '\0')
        {
            if (isnumber(card_number[i]) == 0)
            {
                check_input = 0;
                break;
            }
            i++;
        }
    }
    return card_number;
}

// get card number string lenght
int str_len(char *card_number)
{
    int len = 0;
    while (card_number[len] != '\0')
    {
        len++;
    }
    return len;
}

// Reverses cardnumber string
char *str_reverse(char *card_number, int len)
{
    int i = 0;
    char temp;
    len--;
    while (i < len)
    {
        temp = card_number[i];
        card_number[i] = card_number[len];
        card_number[len] = temp;
        i++;
        len--;
    }
    return card_number;
}

// Hans Peter Luhn of IBM algorithm
void check_luhn(char *card_number, int len)
{
    int i = 0;
    int sum = 0;
    int nbr;

    while (card_number[i] != '\0')
    {
        nbr = card_number[i] - '0';
        if (i % 2 == 1)
        {
            if (nbr >= 5)
            {
                sum = sum + nbr - (9 - nbr);
            }
            else
            {
                sum = sum + nbr * 2;
            }
        }
        else
        {
            sum = sum + nbr;
        }
        i++;
    }
    //  check if last digit is 0
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (len == 15 && card_number[len - 1] == '3' && (card_number[len - 2] == '4' || card_number[len - 2] == '7'))
    {
        printf("AMEX\n");
    }
    else if (len == 16 && card_number[len - 1] == '5' && (card_number[len - 2] == '1' || card_number[len - 2] == '2' 
             || card_number[len - 2] == '3' || card_number[len - 2] == '4' || card_number[len - 2] == '5'))
    {
        printf("MASTERCARD\n");
    }
    else if ((len == 13 || len == 16) && card_number[len - 1] == '4')
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int main(void)
{
    char *card_number;
    int is_valid;
    int len;

    card_number = get_number();
    len = str_len(card_number);
    card_number = str_reverse(card_number, len);

    check_luhn(card_number, len);
    return (0);
}

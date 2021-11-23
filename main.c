#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    const size_t maxLineLen = 1024;
    char input[maxLineLen];
    char temp[100] ={0};
    int i = 0;
    while (fgets(input, sizeof(input), stdin) != NULL)
    {
        for(i =0;i<strlen(input);i++)
        {
            switch (input[i])
            {
            case '0':
                strcat(temp, "0000");
                break;
            case '1':
                strcat(temp, "0001");
                break;
            case '2':
                strcat(temp, "0010");
                break;
            case '3':
                strcat(temp, "0011");
                break;
            case '4':
                strcat(temp, "0100");
                break;
            case '5':
                strcat(temp, "0101");
                break;
            case '6':
                strcat(temp, "0110");
                break;
            case '7':
                strcat(temp, "0111");
                break;
            case '8':
                strcat(temp, "1000");
                break;
            case '9':
                strcat(temp, "1001");
                break;
            case 'A':
                strcat(temp, "1010");
                break;
            case 'B':
                strcat(temp, "1011");
                break;
            case 'C':
                strcat(temp, "1100");
                break;
            case 'D':
                strcat(temp, "1101");
                break;
            case 'E':
                strcat(temp, "1110");
                break;
            case 'F':
                strcat(temp, "1111");
                break;
            default:
                break;
            }
        }

        int len = strlen(temp);
        char onescomplement[len + 1]; // onescomplement array declaration
        char twoscomplement[len + 1]; // twoscomplement array declaration
        int carry = 1;                // variable initialization
        int value;

        if (temp[0] == '1')
        {
            for (int i = 0; i < len; i++)
            {
                if (temp[i] == '0')
                    onescomplement[i] = '1';
                else if (temp[i] == '1')
                    onescomplement[i] = '0';
            }
            onescomplement[strlen(temp)] = '\0';

            // Finding twoscomplement in C
            for (int i = strlen(temp) - 1; i >= 0; i--)
            {
                if (onescomplement[i] == '1' && carry == 1)
                {
                    twoscomplement[i] = '0';
                }
                else if (onescomplement[i] == '0' && carry == 1)
                {
                    twoscomplement[i] = '1';
                    carry = 0;
                }
                else
                {
                    twoscomplement[i] = onescomplement[i];
                }
            }
            twoscomplement[strlen(temp)] = '\0';
            value = atoi(twoscomplement);
        }
        else
        {
            value = atoi(temp);
        }

        int decimal = 0;
        int base = 1, rem = 0;
        while (value > 0)
        {
            rem = value % 10; /* divide the temp number by 10 and store the remainder in rem variable. */
            decimal = decimal + rem * base;
            value = value / 10; // divide the number with quotient
            base = base * 2;
        }

        printf("%d", temp[0] == '1' ? -decimal : decimal);

        //reset string to next complie
        memset(onescomplement, 0, sizeof(onescomplement));
        memset(twoscomplement, 0, sizeof(twoscomplement));
        memset(temp, 0, sizeof(temp));
        memset(input, 0, sizeof(input));
        printf("\n");
    }
}
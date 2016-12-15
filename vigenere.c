#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Wrong number of arguments\n");
        return 1;
    }
    else
    {
        for (int i = 0, n = strlen(argv[1]);i < n;i++)
        {
            if (!(isupper(argv[1][i]) || islower(argv[1][i])))
            {
                printf("Keyword must only contain alphabet characters\n");
                return 1;
            }
        }
        
        string key = argv[1];
        char str[50];
        gets(str);
        
        for (int i = 0, j = 0, n = strlen(str); i < n; i++, j++)
        {
            int char_limit;
            char first_letter;
            int d = strlen(key);
            int key_offset;
            
            if (j >= d)
            {
                j = 0;
            }
            
            if (isupper(str[i]))
            {
                char_limit = 90;
                first_letter = 'A';
            }
            else if (islower(str[i]))
            {
                char_limit = 122;
                first_letter = 'a';
            }
            
            if (!(isupper(str[i]) || islower(str[i])))
            {
                if (j == 0)
                {
                    j = 0;
                }
                else
                {
                    j--;
                }
                printf("%c", str[i]);
            }
            else
            {
                if (isupper(key[j]))
                {
                    key_offset = 13;
                }
                else if (islower(key[j]))
                {
                    key_offset = 7;
                }
                int result = str[i] + (key[j] + key_offset) % 26;
                
                if (result > char_limit)
                {
                    int altered_key = result - char_limit;
                    
                    printf("%c", first_letter + altered_key-1);
                }
                else
                {
                    printf("%c", result);
                }
            }
        }
        
        printf("\n");
        return 0;
    }
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str;
    char ch;
    int size = 1;
    int i = 0;

    str = (char *)malloc(size * sizeof(char));
    if (str == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter a string: ");

    while ((ch = getchar()) != '\n')
    {
        size++;

        str = (char *)realloc(str, size * sizeof(char));
        if (str == NULL)
        {
            printf("Memory reallocation failed!\n");
            return 1;
        }

        str[i++] = ch;
    }

    str[i] = '\0';

    printf("Entered string: %s\n", str);

    free(str);

    return 0;
}

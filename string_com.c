#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SUBSTR_NUMS 10 
#define MAX_SUBSTR_LENS 128

void split_word(char *input, char *outstrs[])
{
    char sz[1024] = {0};
    int i = 0;
    char *tmp;

    strcpy(sz, input);
    tmp  = strtok(sz, " ");
    while(tmp != NULL)
    {
        printf("%s\n", tmp);
        //strcpy(outstrs[i], tmp);
        outstrs[i] = (char *)malloc(MAX_SUBSTR_LENS);
        outstrs[i] = tmp;
        i++;
        tmp = strtok(NULL, " "); 
    }
}

void print_single_strs(char *outstrs[])
{
    int i = 0;
    printf("start print result\n");
    while(outstrs[i] != '\0')
    {
        printf("%s\t", outstrs[i]);
        i++;          
    }
    return;
}

void free_malloc_strs(char *outstrs[])
{
    int i = 0;
    for(i = 0; i < MAX_SUBSTR_NUMS; i++)
    {
        if(outstrs[i] != NULL)
        {
            free(outstrs[i]);
        }
    }
}

int main()
{
    char *teststr = "123 456";
    char *outputstr[MAX_SUBSTR_NUMS];
    
    split_word(teststr, outputstr);
    print_single_strs(outputstr);
    free_malloc_strs(outputstr);
}   

/* 4-1 Write the function strrindex(s,t), which returns the position of the
rightmost occurence of t in s, or -1 if there is none, page 71 */

#include <stdio.h>
#define MAXLINE 1000    /* maximum input line length */

int getline(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould"; /* pattern to search for */

/* find all lines matching pattern */
main() 
{
    char line[MAXLINE];
    int found = 0;
    int lastindex;

    while (getline(line, MAXLINE) > 0)
        if ((lastindex = strrindex(line, pattern)) >= 0) {
            printf("last index = %d\t%s", lastindex, line);
            found++;
        }
    return found;
}

/* getline: get line int s, return length */
int getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c!= '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

/* strrindex: return index of t in s, -1 if none */
int strrindex(char s[], char t[])
{
    int i, j, k;
    int lastindex = -1;

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            lastindex = i;
    }
    return lastindex;
}
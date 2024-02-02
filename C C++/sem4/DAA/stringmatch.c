#include <stdio.h>
#include <string.h>

int naive_string_matching(char text[], char pattern[])
{
    int m = strlen(text);
    int n = strlen(pattern);

    for (int i = 0; i <= m - n; i++)
    {
        int j = 0;
        while (j < n && pattern[j] == text[i + j])
        {
            j = j + 1;
        }
        if (j == n)
        {
            return i;
        }
    }
    return -1; // Pattern not found
}

int main()
{
    char text[100], pattern[100];

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove newline character from input

    printf("Enter the pattern to search for: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0'; // Remove newline character from input

    int position = naive_string_matching(text, pattern);

    if (position != -1)
    {
        printf("Pattern found at position %d\n", position);
    }
    else
    {
        printf("Pattern not found in the text.\n");
    }

    return 0;
}

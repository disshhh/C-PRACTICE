#include <stdio.h>

int sequential_search(int arr[], int n, int key)
{
    /*
    int sequential_search(int arr[], int n, int key) {
    int i = 0;
    while (i < n && arr[i] != key) {
        i++;
    }
    if (i < n) {
        return i; // Return the index if key is found
    } else {
        return -1; // Return -1 if key is not found
    }
    }
*/
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i; // Return the index if key is found
        }
    }
    return -1; // Return -1 if key is not found
}

int main()
{
    int n, key, index;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Perform sequential search
    index = sequential_search(arr, n, key);

    if (index != -1)
    {
        printf("Element found at index: %d\n", index);
    }
    else
    {
        printf("Element not found in the array.\n");
    }

    return 0;
}

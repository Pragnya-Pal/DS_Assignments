

#include <stdio.h>
#include <string.h>

struct student
{
    int roll;
    char name[50];
    float marks;
};

int sorted_by_roll(struct student s[], int n)
{
    int i;

    for (i = 0; i < n - 1; i++)
        if (s[i].roll > s[i + 1].roll)
            return 0;

    return 1;
}

void selection_sort(struct student s[], int n)
{
    int i, j, max;
    struct student temp;

    for (i = 0; i < n - 1; i++)
    {
        max = i;

        for (j = i + 1; j < n; j++)
            if (s[j].roll > s[max].roll)
                max = j;

        temp = s[i];
        s[i] = s[max];
        s[max] = temp;
    }
}

void shell_sort(struct student s[], int n)
{
    int gap, i, j;
    struct student temp;

    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = s[i];

            for (j = i; j >= gap &&
                 strcmp(s[j - gap].name, temp.name) > 0;
                 j -= gap)
                s[j] = s[j - gap];

            s[j] = temp;
        }
    }
}

void linear_search(struct student s[], int n, char key[])
{
    int i, count = 0;

    for (i = 0; i < n; i++)
    {
        count++;

        if (strcmp(s[i].name, key) == 0)
        {
            printf("Found at index %d\n", i);
            printf("Comparisons = %d\n", count);
            return;
        }
    }

    printf("Not found\n");
    printf("Comparisons = %d\n", count);
}

void binary_search(struct student s[], int n, int key)
{
    int low = 0, high = n - 1;
    int mid, count = 0;

    if (!sorted_by_roll(s, n))
    {
        printf("Sort by roll number first\n");
        return;
    }

    while (low <= high)
    {
        mid = (low + high) / 2;
        count++;

        if (s[mid].roll == key)
        {
            printf("Found at index %d\n", mid);
            printf("Comparisons = %d\n", count);
            return;
        }
        else if (s[mid].roll < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("Not found\n");
    printf("Comparisons = %d\n", count);
}

int main()
{
    struct student s[100];
    int n, i, choice, key;
    char name[50];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d %49s %f",
              &s[i].roll, s[i].name, &s[i].marks);

    while (scanf("%d", &choice) == 1)
    {
        switch (choice)
        {
            case 1:
                selection_sort(s, n);
                for (i = 0; i < n; i++)
                    printf("%d %s %.2f\n",
                           s[i].roll, s[i].name, s[i].marks);
                break;

            case 2:
                shell_sort(s, n);
                for (i = 0; i < n; i++)
                    printf("%d %s %.2f\n",
                           s[i].roll, s[i].name, s[i].marks);
                break;

            case 3:
                scanf("%49s", name);
                linear_search(s, n, name);
                break;

            case 4:
                scanf("%d", &key);
                binary_search(s, n, key);
                break;

            default:
                break;
        }
    }

    return 0;
}

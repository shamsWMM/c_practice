#include <stdio.h>
#include <string.h>
struct weather
{
    char day[10];
    float temp;
};
void display(struct weather *arr, int len);
void sort(struct weather *arr, int len);

int main()
{
    struct weather week[7] = {
        {"Sunday", 72.5},
        {"Monday", 68.4},
        {"Tuesday", 75.0},
        {"Wednesday", 73.8},
        {"Thursday", 65.1},
        {"Friday", 72.8},
        {"Saturday", 75.2}};

    display(week, 7);
    sort(week, 7);
    puts("Sorted forecast:");
    display(week, 7);

    return (0);
}
void sort(struct weather *arr, int len)
{
    int y, x;
    for (y = 0; y < len; y++)
    {
        for (x = 0; x < len - 1; x++)
        {
            float temp = (arr + x)->temp;
            if (temp > ((arr + x + 1)->temp))
            {
                (arr + x)->temp = (arr + x + 1)->temp;
                (arr + x + 1)->temp = temp;
            }
        }
        len--;
    }
}
    void display(struct weather * arr, int len)
    {
        int x;
        for (x = 0; x < len; x++)
            printf("%10s %.1f degrees\n",
                   (arr + x)->day,
                   (arr + x)->temp);
    }

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void obnuleniye (int mas [], int k)
{
    for (int i = 0; i < k; i++)
    {
        mas [i] = 0;
    }
}

void vvod (int mas [], int k)
{
    for (int i = 0; i < k; i++)
    {
        scanf ("%d", &mas[i]);
    }
}

void zapolneniye (int mas [], int k, int a, int b)
{
    srand(time(NULL));
    
    for (int i = 0; i < k; i++)
    {
        mas[i] = a + rand() % (b - a + 1);
    }
}

void vivod (int mas [], int k)
{
    for (int i = 0; i < k; i++)
    {
        printf ("%d.  %d\n", i+1, mas [i]);
    }
}

int search_min(int mass[]){
    int s=mass[0];
    for (int i=1;mass[i];i++){
        if (mass[i] < s)
            s=mass[i];
    }
    return s;
}

void zamena(int massiv[], int num){
    int j=0;
    // while(massiv[j])
    //     j++;
    // j--;
    if (num%2 == 1)
        num++;
    for (int i=0; i < num/2; i++){
        if (i%2==0){
            int tmp = massiv[i];
            massiv[i] = massiv[num-i-2];
            massiv[num-i-2] = tmp;
        }
    }
}
// void zamena(int massiv[]){
//     int j=0;
//     while(massiv[j])
//         j++;
//     int count=1;
//     if (massiv[j-1] %2 == 0){
//         count = 0;
//         j--;
//     }
//     for (int i=j/2; massiv[i]; i++){
//         if (massiv[i] % 2 == 1){
//             int tmp=massiv[i];
//             massiv[i] = massiv[j-i-1];
//             massiv[j-i-1] = tmp;
//         }
//     }
//     if (massiv[j-1] == -1)
//         massiv[j-1] = 0;
// }

void open_file(int mass[], char name[]){
    FILE *fp;
    if ((fp = fopen(name, "r"))==NULL){
        printf("Не удалось открыть файл");
        getchar();
        return ;
    }
    for (int i=0; mass[i]; i++){
        fscanf(fp, "%d ", &mass[i]);
    }
    fclose(fp);
    getchar();
}

void write_to_file(int mass[], char name[]){
    FILE *fp;
    if ((fp = fopen(name, "w"))==NULL){
        printf("Не удалось открыть файл");
        getchar();
        return ;
    }
    for (int i=0; mass[i]; i++){
        fprintf(fp, "%d ", mass[i]);
    }
    fclose(fp);
    getchar();
}

void delete_element_index(int mass[], int index){
    for (int i=index; mass[i]; i++)
        mass[i] = mass[i+1];
}

void add_element_index(int mass[], int index, int num){
    int i=0;
    while (mass[i])
        i++;
    int j=i;
    for (; j >= index; j--)
        mass[j+1] = mass[j];
    mass[j+1] = num;
}

int main(int ac, char **av){
    int j=0;
    int count=1;

    int massiv[1000];
    if (ac == 1){
        printf("Write number of arguments\n");
        scanf("%d", &j);
        printf("Write arguments\n");
        vvod(massiv, j);
    }
    else
        for(int i=1; av[i]; i++){
            massiv[j++] = atoi(av[i]);
    }

    zamena(massiv, j);

    // printf("Lets move 2nd element to 100\n");
    // add_element_index(massiv, 2, 100);

    // printf("Lets delete 1st element\n");
    // delete_element_index(massiv, 1);

    vivod(massiv, j);

    // write_to_file(massiv, "1.txt");
    // return printf("\n");
}
/* Работа с графом
Удалить вершины, которые смежны 
с заданным ребром, и отсортировать
оставшиеся по убыванию степени вершины 
(сортировка вставками) */

#include <stdio.h>
#include <stdlib.h>
FILE* f;
FILE* f1;
int Sort1(int* m, int v) {
    for (int j = 0; j < v; j++) {
    printf("%d ",m[j]);
    }
    printf("\n");
    return 0;
}

int main(void) {
    printf("enter the number of edge - top\n");
    int v;
    int sv;
    scanf("%d",&sv);
    printf("\n");
    scanf("%d",&v);
    int m[sv][v];
    for (int i = 0; i < sv; i++) {
        for (int j = 0; j < v; j++) {
            scanf("%d",&m[i][j]);
        }
    }
       f = fopen("text.dot","w");
    if (f == NULL)
        return 0;

    fprintf(f,"graph MyGraf {\n");

    for (int i = 0; i < sv; i++) {
        int x1 = -1;
        int x2 = -1;

        for (int j = 0; j < v; j++) {
            if (m[i][j] == 1 && x1 == -1 )
                x1 = j+1;
            else if (m[i][j] == 1 && x2 == -1 )
                x2 = j+1;
             else if (m[i][j] == 2 )
                x2 = x1 = j+1;
        }
        if (x1 == -1)
            fprintf(f,"%d;\n",x2);
        else if (x2 == -1)
            fprintf(f,"%d;\n",x1);
        else
            fprintf(f,"%d -- %d;\n",x1,x2);
    }
    fprintf(f,"{ rank = same; ");
    for (int j = 0; j < v; j++) {
        fprintf(f,"%d; ",j+1);
    }
    fprintf(f,"}\n");
    fprintf(f,"}");
    fclose(f);
    // change Graf
    f1 = fopen("text1.dot","w");
    if (f1 == NULL)
        return 0;
    printf("enter the two top to delete\n");
    printf("enter fitst top\n");
    int t1;
    scanf("%d",&t1);
    printf("\n");
    printf("enter second top\n");
    int t2;
    scanf("%d",&t2);
    --t1;
    --t2;
    fprintf(f1,"graph MyGraf {\n");
    for (int i = 0; i < sv; i++)
    {
        int x1 = -1;
        int x2 = -1;

        for (int j = 0; j < v; j++) {
            if ( (m[i][t1] == 1) || (m[i][t2] == 1) ) {
                for (int q = 0; q < v; q++) {
                    m[i][q] = 0;
                }
                break;
            }
            if (m[i][j] == 1 && x1 == -1 )
                x1 = j+1;
            else if (m[i][j] == 1 && x2 == -1 )
                x2 = j+1;
            else if (m[i][j] == 2 ) {
                x2 = x1 = j+1;
                break;
             }
        }
        if ( (x1 == -1) && (x2 == -1) )
            continue;
        if (x1 == -1)
            fprintf(f,"%d;\n",x2);
        else if (x2 == -1)
            fprintf(f,"%d;\n",x1);
        else
            fprintf(f,"%d -- %d;\n",x1,x2);
    }


    fprintf(f1,"{ rank = same; ");
    for (int j = 0; j < v; j++) {
        if ( (j == t1) || (j == t2) )
            continue;
        fprintf(f1,"%d; ",j+1);
    }
    fprintf(f1,"}\n");
    fprintf(f1,"}");
    fclose(f1);

    printf("\n\n");
    for (int i = 0; i < sv; i++) {
        for (int j = 0; j < v; j++) {
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int mas_sort[v];
    for (int j = 0; j < v; j++) {
        mas_sort[j] = 0;
    }
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < sv; j++) {
        mas_sort[i] += m[j][i];
       }
    }
    printf("\n\n");
    Sort1(mas_sort,v);
    for (int i = 1; i < v; i++) {
        int j = i;
        int p = mas_sort[i];
        while ( (j > 0) && (mas_sort[j-1] < p) )  {
            mas_sort[j] = mas_sort[j-1];
            --j;
        }
        mas_sort[j] = p;
    }
    printf("\n");
    Sort1(mas_sort,v);

    return 0;
}

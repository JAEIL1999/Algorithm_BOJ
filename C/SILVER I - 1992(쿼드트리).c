#include <stdio.h>
#include <stdlib.h>


int **QuadTree;

void recursiveLeftUp(int **Quad, int row, int colomn, int number);
void recursiveRightUp(int **Quad, int row, int colomn, int number);
void recursiveLeftDown(int **Quad, int row, int colomn, int number);
void recursiveRightDown(int **Quad, int row, int colomn, int number);

int main()
{
    int number;
    int i,j;
    scanf("%d",&number);

    QuadTree = (int**)malloc(sizeof(int*)*number);
    for(int i=0;i<number;i++) {
        QuadTree[i] = (int*)malloc(sizeof(int)*number);
    }
    for(int i=0;i<number;i++) {
        for(int j=0;j<number;j++) {
            scanf("%1d",&QuadTree[i][j]);
        }
    }

    for(i=0;i<number;i++) {
        for(j=0;j<number;j++) {
            if(QuadTree[i][j] != QuadTree[0][0]) break;
        }
        if(j != number) break;
    }
    if(i==number) {
        printf("%d",QuadTree[0][0]);
    }
    else {
        printf("(");
        recursiveLeftUp(QuadTree, 0, 0, number/2);
        recursiveRightUp(QuadTree, 0, number/2, number/2);
        recursiveLeftDown(QuadTree, number/2, 0,  number/2);
        recursiveRightDown(QuadTree, number/2, number/2, number/2);
        printf(")");
    }


    return 0;
}

void recursiveLeftUp(int **Quad, int row, int colomn, int number)
{
    int start_number = Quad[row][colomn];
    int i,j;

    if(number==1) {
        printf("%d",start_number);
        return ;
    }
    for(i=row;i<row+number;i++) {
        for(j=colomn;j<colomn+number;j++) {
            if(Quad[i][j] != start_number) break;
        }
        if(j!=colomn+number) break;
    }
    if(i==row+number) printf("%d",start_number);
    else {
        printf("(");
        recursiveLeftUp(Quad, row, colomn, number/2);
        recursiveRightUp(Quad, row, colomn+(number/2), number/2);
        recursiveLeftDown(Quad, row+(number/2), colomn, number/2);
        recursiveRightDown(Quad, row+(number/2), colomn+(number/2), number/2);
        printf(")");
    }
}

void recursiveRightUp(int **Quad, int row, int colomn, int number)
{
    int start_number = Quad[row][colomn];
    int i,j;

    if(number==1) {
        printf("%d",start_number);
        return ;
    }

    for(i=row;i<row+number;i++) {
        for(j=colomn;j<colomn+number;j++) {
            if(Quad[i][j] != start_number) break;
        }
        if(j !=colomn+number) break;
    }
    if(i==row+number) printf("%d",start_number);
    else {
        printf("(");
        recursiveLeftUp(Quad, row, colomn, number/2);
        recursiveRightUp(Quad, row, colomn+(number/2), number/2);
        recursiveLeftDown(Quad, row+(number/2), colomn, number/2);
        recursiveRightDown(Quad, row+(number/2), colomn+(number/2), number/2);
        printf(")");
    }
}

void recursiveLeftDown(int **Quad, int row, int colomn, int number)
{
    int start_number = Quad[row][colomn];
    int i,j;

    if(number==1) {
        printf("%d",start_number);
        return ;
    }

    for(i=row;i<row+number;i++) {
        for(j=colomn;j<colomn+number;j++) {
            if(Quad[i][j] != start_number) break;
        }
        if(j!=colomn+number) break;
    }
    if(i==row+number) printf("%d",start_number);
    else {
        printf("(");
        recursiveLeftUp(Quad, row, colomn, number/2);
        recursiveRightUp(Quad, row, colomn+(number/2), number/2);
        recursiveLeftDown(Quad, row+(number/2), colomn, number/2);
        recursiveRightDown(Quad, row+(number/2), colomn+(number/2), number/2);
        printf(")");
    }

}

void recursiveRightDown(int **Quad, int row, int colomn, int number)
{
    int start_number = Quad[row][colomn];
    int i,j;

    if(number==1) {
        printf("%d",start_number);
        return ;
    }

    for(i=row;i<row+number;i++) {
        for(j=colomn;j<colomn+number;j++) {
            if(Quad[i][j] != start_number) break;
        }
        if(j != colomn+number) break;
    }
    if(i==row+number) printf("%d", start_number);
    else {
        printf("(");
        recursiveLeftUp(Quad, row, colomn, number/2);
        recursiveRightUp(Quad, row, colomn+(number/2), number/2);
        recursiveLeftDown(Quad, row+(number/2), colomn, number/2);
        recursiveRightDown(Quad, row+(number/2), colomn+(number/2), number/2);
        printf(")");
    }
}

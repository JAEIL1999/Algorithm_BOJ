#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

void recursiveSection(int row, int column, int arr, int *answer);
int returnSection(int row, int column, int arr);

int main(void)
{
    int N;
    int row, column;
    bool up = false, down=false, left=false, right=false;
    int arr;
    int answer = 0;
    cin>>N>>row>>column;

    arr = pow(2, N);
    recursiveSection(row+1, column+1, arr, &answer);

    cout<<answer;

    return 0;
}

void recursiveSection(int row, int column, int arr, int *answer) {
    int section = 0;
    section = returnSection(row, column, arr);

    if (arr == 2) {
        switch(section) {
        case 1 :
            *answer += 0;
            return ;
        case 2 :
            *answer += 1;
            return ;
        case 3 :
            *answer += 2;
            return ;
        case 4 :
            *answer += 3;
            return ;
        default :
            break;
        }
    }

     switch(section) {
        case 1 :
            recursiveSection(row, column, arr/2, answer);
            break;
        case 2 :
            *answer += pow(arr/2,2);
            recursiveSection(row, column-arr/2, arr/2, answer);
            break;
        case 3 :
            *answer += 2*pow(arr/2,2);
            recursiveSection(row-arr/2, column, arr/2, answer);
            break;
        case 4 :
            *answer += 3*pow(arr/2,2);
            recursiveSection(row-arr/2, column-arr/2, arr/2, answer);
            break;
        default :
            break;
        }

}

int returnSection(int row, int column, int arr) {
    bool up = false, down=false, left=false, right=false;

    if (row >arr/2) down = true;
    else up = true;
    if(column>arr/2) right = true;
    else left = true;

    if (up == true) {
        if(left == true)    return 1;
        else    return 2;

    } else {
        if(left==true)  return 3;
        else    return 4;
    }

}

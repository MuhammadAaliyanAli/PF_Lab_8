#include <stdio.h>
void printGrid(int (*grid)[5]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
}
int countNeighbours(int (*grid)[5],int row,int col){
    int count=0;
    for(int i=row-1;i<=row+1;i++){
        for(int j=col-1;j<=col+1;j++){
            if(i>=0 && i<5 && j>=0 && j<5 && !(i==row && j==col)){
                count+=grid[i][j]&1;
            }
        }
    }
    return count;
}
void nextGeneration(int (*grid)[5]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int neighbours=countNeighbours(grid,i,j);
            int alive=grid[i][j]&1;
            if((alive && (neighbours==2 || neighbours==3)) || (!alive && neighbours==3)){
                grid[i][j]|=2;
            }
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            grid[i][j]>>=1;
        }
    }
}
int main(){
    int grid[5][5]={0},n;
    grid[1][2]=1;
    grid[2][2]=1;
    grid[3][2]=1;
    do{
        printf("Enter number of generations (0-50): ");
        scanf("%d",&n);
        if(n<0 || n>50){
            printf("Invalid number\n");
        }
    }while(n<0 || n>50);
    printf("Generation 0:\n");
    printGrid(grid);
    for(int i=1;i<=n;i++){
        nextGeneration(grid);
        printf("Generation %d:\n",i);
        printGrid(grid);
    }
    return 0;
}

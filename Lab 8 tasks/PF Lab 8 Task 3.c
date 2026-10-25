#include <stdio.h>
int isValidMark(int m){
    return m>=0 && m<=100;
}
void findMinMax(int arr[],int size,int *min,int *max){
    *min=arr[0];
    *max=arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]<*min){
            *min=arr[i];
        }
        if(arr[i]>*max){
            *max=arr[i];
        }
    }
}
int main(){
    int arr[5],min,max;
    for(int i=0;i<5;i++){
        do{
            printf("Enter mark %d: ",i+1);
            scanf("%d",&arr[i]);
            if(!isValidMark(arr[i])){
                printf("Invalid mark, enter again\n");
            }
        }while(!isValidMark(arr[i]));
    }
    findMinMax(arr,5,&min,&max);
    printf("Lowest mark: %d\n",min);
    printf("Highest mark: %d\n",max);
    return 0;
}

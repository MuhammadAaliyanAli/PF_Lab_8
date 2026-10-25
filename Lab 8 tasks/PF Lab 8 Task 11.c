#include <stdio.h>
int square(int x){
    return x*x;
}
int negate(int x){
    return -x;
}
int isEven(int x){
    return x%2==0;
}
int isPositive(int x){
    return x>0;
}
void applyToArray(int *arr,int n,int (*fn)(int)){
    for(int i=0;i<n;i++){
        *(arr+i)=fn(*(arr+i));
    }
}
int countIf(const int *arr,int n,int (*pred)(int)){
    int count=0;
    for(int i=0;i<n;i++){
        if(pred(*(arr+i))){
            count++;
        }
    }
    return count;
}
void printGeneric(void *data,char type,int n){
    if(type=='i'){
        for(int i=0;i<n;i++){
            printf("%d ",*((int *)data+i));
        }
    }else if(type=='f'){
        for(int i=0;i<n;i++){
            printf("%.2f ",*((float *)data+i));
        }
    }else if(type=='c'){
        for(int i=0;i<n;i++){
            printf("%c ",*((char *)data+i));
        }
    }else{
        printf("Invalid type '%c' for printGeneric",type);
    }
    printf("\n");
}
int main(){
    int arr[50]={3,-2,8,-5,6},n;
    float floats[]={1.50,2.25};
    do{
        printf("Enter n (1-50): ");
        scanf("%d",&n);
        if(n<1 || n>50){
            printf("Invalid number\n");
        }
    }while(n<1 || n>50);
    printf("Original: ");
    printGeneric(arr,'i',n);
    applyToArray(arr,n,negate);
    printf("After negate: ");
    printGeneric(arr,'i',n);
    printf("Positive values after negate: %d\n",countIf(arr,n,isPositive));
    printf("Even values after negate: %d\n",countIf(arr,n,isEven));
    printf("Float print (type f): ");
    printGeneric(floats,'f',2);
    printGeneric(arr,'x',n);
    return 0;
}

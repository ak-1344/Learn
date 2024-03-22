#include <stdio.h>
struct party_item{
    char name[20];
    int quantity;
    int price;
};
struct party_item input(){
    struct party_item a;
    printf("Enter the name of item: ");
    scanf("%s",&a.name);
    printf("Enter the quantity of item: ");
    scanf("%d",&a.quantity);
    printf("Enter the price of item: ");
    scanf("%d",&a.price);
    return a;
}
int main(){
    int n,items;
    printf("Enter the number of items: ");
    scanf("%d",&items);
    struct party_item arr[items];
    printf("Enter the number of students: ");
    scanf("%d",&n);
    int total_price=0;
    for(int i=0;i<items;i++){
        printf("\nEnter the details of item %d.\n",i+1);
        arr[i]=input();
        total_price+=(arr[i].price)*(arr[i].quantity);
    }
    printf("Total price: %d\n", total_price);
    printf("Price per head: %d\n",total_price/n);
    return 0;
}
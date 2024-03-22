    #include <stdio.h>
    #include <stdlib.h>
    typedef struct employee{
        char name[50];
        int age;
        int id;
        long long unsigned int mob_no;
        char address[50];
    }emp;

    emp input(){
        emp a;
        printf("Enter Employee Id, name, age, Mobile number and address respectively and please press enter after each value entered:\n");
        scanf("%d\n",&a.id);
        gets(a.name);
        scanf("%d\n",&a.age);
        scanf("%lld\n",&a.mob_no);
        gets(a.address);
        return a;
    }

    void print(emp a){
        printf("%d\n",a.id);
        printf("%s\n",a.name);
        printf("%d\n",a.age);
        printf("%lld\n",a.mob_no);
        printf("%s\n",a.address);
    }
    void byname(emp *a,char name[50]){
        int n=sizeof(a)/sizeof(a[0]);
        for(int i=0;i<n;i++){
            if(a[i].name == name){
                print(a[i]);
            }
        }
    }
    void byage(emp *a,int age){
        int n=sizeof(a)/sizeof(a[0]);
        for(int i=0;i<n;i++){
            if(a[i].age == age){
                print(a[i]);
            }
        }
    }
    void byid(emp *a,int id){
        int n=sizeof(a)/sizeof(a[0]);
        for(int i=0;i<n;i++){
            if(a[i].id == id){
                print(a[i]);
            }
        }
    }

    int main(){
        int n;
        scanf("%d",&n);
        emp arr[n];
        for(int i=0;i<n;i++){
            printf("%d",i+1);
            arr[i]=input();
        }
        printf("Do you want to search any entered employee:\n 1 for YES\n0 for NO\n");
        int check; scanf("%d",&check);
        if(check==1){
            printf("Choose one of the option:\n1. By employee name.\n2. By employee ID.\n3. By Age.\n");
            int c; scanf("%d",&c);
            switch (c)
            {
            case 1:
                printf("Enter the name of the employee: ");
                char name[50];
                scanf("\n");
                gets(name);
                byname(arr,name);
                break;
            case 2:
                printf("Enter the ID: ");
                int id; scanf("%d",&id);
                byid(arr,id);
                break;
            case 3:
                printf("Enter the age of the employee: ");
                int age; scanf("%d",&age);
                byage(arr,age);
                break;
            default:
                printf("You entered the wrong input.");
                break;
            }
        }
        emp maxage=arr[0];
        maxage.age=0;
        for(int i=0;i<n;i++){
            if(maxage.age<arr[i].age){
                maxage=arr[i];
            }
        }
        print(maxage);
    }
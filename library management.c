#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct anil{
    int a;
    char s[100];
    float b;
};
void edit(int,int);

int main()
{
   int x;
    printf("for new book detail set enter 1\n");
    printf("for read book detail set enter 2\n");
    printf("To see all book detail set enter 3\n");
    printf("for changes in book detail  enter 4\n");
    scanf("%d",&x);
    if(x==1){
    int x1;
    printf("Enter 1 for add new book and 2 for reset system :");
    scanf("%d",&x1);
    if(x1 == 1){
    FILE *f;
    f = fopen("anil","r");
    int i,n,n1;
    printf("Enter how many book enter : ");
    scanf("%d",&n1);
    fscanf(f,"%d\n",&n);
    fclose(f);
    f = fopen("anil","a");
    struct anil b[n1+n];
    printf("Enter detail of book like (Book Id , book name and prize) : \n");
    for(i=n;i<n1+n;i++){
        scanf("%d%s%f",&b[i].a,b[i].s,&b[i].b);

    }
    for(i=n;i<n1+n;i++){
        fprintf(f,"%d\n",b[i].a);
        fprintf(f,"%s\n",b[i].s);
        fprintf(f,"%f\n",b[i].b);
    }
    fclose(f);

    edit(n,n1);
    }
    if(x1 == 2){
    FILE *f;
    f = fopen("anil","w");
    int i,n;
    printf("Enter how many book enter : ");
    scanf("%d",&n);
    fprintf(f,"%d\n",n);
    struct anil b[n];
    printf("Enter detail of book like (Book Id , book name and prize) : \n");
    for(i=0;i<n;i++){
        scanf("%d%s%f",&b[i].a,b[i].s,&b[i].b);
    }
    for(i=0;i<n;i++){
        fprintf(f,"%d\n",b[i].a);
        fprintf(f,"%s\n",b[i].s);
        fprintf(f,"%f\n",b[i].b);
    }
    fclose(f);
    }
    }

    if(x==2){
    FILE *f;
    f = fopen("anil","r");
    int i,k,n;
    char j[100];
    printf("Enter book name : ");
    scanf("%s",j);
    fscanf(f,"%d\n",&n);
    struct anil b[n];
    for(i=0;i<n;i++){
        fscanf(f,"%d\n",&b[i].a);
        fscanf(f,"%s\n",b[i].s);
        fscanf(f,"%f\n",&b[i].b);
    }
    for(i=0;i<n;i++){
        if(strcmp(j, b[i].s)==0){
            k=i;
            break;
        }
    }
        printf("Book ID = %d\n",b[k].a);
        printf("Book name  = %s\n",b[k].s);
        printf("Book prize = %f\n\n",b[k].b);

    fclose(f);
    }
    if(x==3){
    FILE *f;
    f = fopen("anil","r");
    int i,n;
    fscanf(f,"%d\n",&n);
    struct anil b[n];
    for(i=0;i<n;i++){
        fscanf(f,"%d\n",&b[i].a);
        fscanf(f,"%s\n",b[i].s);
        fscanf(f,"%f\n",&b[i].b);
    }
   for(i=0;i<n;i++){
       printf("Book %d :\n",i+1);
        printf("Book ID = %d\n",b[i].a);
        printf("Book name  = %s\n",b[i].s);
        printf("Book prize = %f\n\n",b[i].b);
   }
    fclose(f);
    }
    if(x==4){
       FILE *f;
    f = fopen("anil","r");
    int i,k,n,x2;
    printf("for edit book enter 1 and 2 for delete book");
    scanf("%d",&x2);
    char j[100];
    printf("Enter book name : ");
    scanf("%s",j);
    fscanf(f,"%d\n",&n);
    struct anil b[n];
    for(i=0;i<n;i++){
        fscanf(f,"%d\n",&b[i].a);
        fscanf(f,"%s\n",b[i].s);
        fscanf(f,"%f\n",&b[i].b);
    }
    for(i=0;i<n;i++){
        if(strcmp(j, b[i].s)==0){
            k=i;
            break;
        }
    }
        printf("Book ID = %d\n",b[k].a);
        printf("Book name  = %s\n",b[k].s);
        printf("Book prize = %f\n\n",b[k].b);
        fclose(f);
        if(x2==1){
        f = fopen("anil","r+");
        fprintf(f,"%d\n",n);
        for(i=0;i<n;i++){
            if(i!=k){
        fprintf(f,"%d\n",b[i].a);
        fprintf(f,"%s\n",b[i].s);
        fprintf(f,"%f\n",b[i].b);
            }
            else{
                scanf("%d%s%f",&b[k].a,b[k].s,&b[k].b);
                 fprintf(f,"%d\n",b[k].a);
        fprintf(f,"%s\n",b[k].s);
        fprintf(f,"%f\n",b[k].b);
            }

    }

         fclose(f);
        }
        if(x2==2){
        f = fopen("anil","w");
        n=n-1;
        fprintf(f,"%d\n",n);
        for(i=0;i<n+1;i++){
            if(k!=i){
        fprintf(f,"%d\n",b[i].a);
        fprintf(f,"%s\n",b[i].s);
        fprintf(f,"%f\n",b[i].b);
            }
            }

    }

         fclose(f);
        }
        getch();

    return 0;
}
void edit(int n,int n1){
    FILE *f;
    f = fopen("anil","r+");
    n=n+n1;
    fprintf(f,"%d\n",n);
    fclose(f);
}

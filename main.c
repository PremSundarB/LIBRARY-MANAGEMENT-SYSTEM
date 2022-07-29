#include <stdio.h>
#include <string.h>
struct library
{
    char bookname[50];
    char bookid[50];
};

//function 1 
int verify(char uname[],char pword[],char u[],char p[])
{
    int input;
    char temp;
if ((strcmp(u,uname)==0) && (strcmp(p,pword)==0))
{ 
  printf("THE USERNAME AND PASSWORD ARE CORRECT \n");
  return 0;
} 
 else 
{  
  printf("THE USERNAME OR PASSWORD IS INCORRECT.\nPRESS 1 : TO CREATE NEW ACCOUNT \nPRESS 2 : TO RETRY USERNAME AND PASSWORD\n"); 
  scanf("%d",&input);
  if(input==1)
  {
    printf("ENTER THE NEW USERNAME :\n");
    scanf("%c",&temp);
    scanf("%[^\n]",uname);
    printf("ENTER THE NEW PASSWORD :\n");
    scanf("%c",&temp);
    scanf("%[^\n]",pword);
    printf("THE ACCOUNT HAS BEEN CREATED. PLEASE REENTER THE LOGIN DETAILS \n");  
  }
  scanf("%c",&temp);
  return 1;
}
}
//end of function 1

//function 2
void add(struct library lib[],int *count)
{
       int x; //to take number of books
       char temp; //to clear buffer
        printf("ENTER NUMBER OF BOOK YOU WANT TO ADD : \n");
        scanf("%d",&x);
        for(int i=*count;i<(*count+x);i++)
        {
        printf("ENTER THE BOOK NAME : \n");
        scanf("%c",&temp);// we use temp to clear the bufffer 
        scanf("%[^\n]",lib[i].bookname);
        printf("ENTER THE BOOK ID : \n");
        scanf("%c",&temp);
        scanf("%[^\n]",lib[i].bookid);
        printf("THE BOOK HAS BEEN ADDED \n");
        }
        *count+=x;
       
}
//end of function 2

//function 3
void delete(struct library lib[],int *count)
{
    int index=-1;
    char temp;
    //index -> the matched index
    char bd[100];//to take inputs from user
    printf("ENTER THE BOOK NAME / BOOK ID :");
    scanf("%c",&temp);
    scanf("%[^\n]",bd);
        for(int i=0;i<*count;i++)
        {
        if(strcmp((lib[i].bookname),(bd))==0 || strcmp((lib[i].bookid),(bd))==0)
        {
            index=i;
            printf("THE BOOK HAS BEEN DELETED \n");
            break;
        }
        }
    if(index==-1)
    {
        printf("BOOK NOT FOUND \n");
    }
    else 
    {
        for(int i=index;i<*count;i++)
        {
        strcpy(lib[i].bookname,lib[i+1].bookname);
        strcpy(lib[i].bookid,lib[i+1].bookid);
        }
    }  
    *count=*count-1;  
}

//end of function 3

//function 4
void search(struct library lib[],int *count)
{
    int index=-1;
    char temp;
    //index -> the matched index
    char bd[100];//to take inputs from user
    printf("ENTER THE BOOK NAME / BOOK ID :");
    scanf("%c",&temp); 
    scanf("%[^\n]",bd);
        for(int i=0;i<*count;i++)
        {
        if(strcmp((lib[i].bookname),(bd))==0 || strcmp((lib[i].bookid),(bd))==0)
        {
        printf("THE BOOK NAME IS : %s \n",lib[i].bookname);
        printf("THE BOOK ID IS : %s \n",lib[i].bookid);
        index=0;
        }
        }
    if(index==-1)
    {
        printf("BOOK NOT FOUND \n");
    }   
}
//end of function 4

//function 5
void view(struct library lib[],int *count)
{
        for(int i=0;i<*count;i++)
        {
             printf("THE BOOK NAME IS :%s \n",lib[i].bookname);
             printf("THE BOOK ID IS :%s \n",lib[i].bookid);
             
        }
}
//end of function 5

//function 6
void edit(struct library lib[],int *count)
{
    int index=-1,choice;
    char temp;
    //index -> the matched character
    char bd[100];//to take inputs from user
    printf("ENTER THE BOOK NAME / BOOK ID :");
    scanf("%c",&temp);
    scanf("%[^\n]",bd);
        for(int i=0;i<*count;i++)
        {
        if(strcmp((lib[i].bookname),(bd))==0 || strcmp((lib[i].bookid),(bd))==0)
        {
            index=i;
            break;
        }
        }
    if(index==-1)
    {
        printf("BOOK NOT FOUND \n");
    }
    else 
    {
        
         printf("1.EDIT BOOK NAME \n2.EDIT BOOK ID \n3.EDIT BOOK NAME AND BOOK ID\n");
         printf("ENTER YOUR CHOICE \n");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                printf("ENTER THE NEW BOOK NAME: \n");
                scanf("%c",&temp);
                scanf("%[^\n]",lib[index].bookname);
                printf("THE EDITED BOOK NAME IS :  %s \n",lib[index].bookname);
                break;
                
                case 2:
                printf("ENTER THE NEW BOOK ID: \n");
                scanf("%c",&temp);
                scanf("%[^\n]",lib[index].bookid);
                printf("THE EDITED BOOK ID IS : %s \n",lib[index].bookid);
                break;
                
                case 3:
                printf("ENTER THE NEW BOOK NAME: \n");
                scanf("%c",&temp);
                scanf("%[^\n]",lib[index].bookname);
                printf("ENTER THE NEW BOOK ID: \n");
                scanf("%c",&temp);
                scanf("%[^\n]",lib[index].bookid);
                printf("THE EDITED BOOK NAME IS : %s \n",lib[index].bookname);
                printf("THE EDITED BOOK ID IS : %s \n",lib[index].bookid);
                break;
            }
    }
}
//end of function 6

int main()
{
    printf("WELCOME TO PRAGNYA LIBRARY MANAGEMENT SYSTEM \n");
    struct library lib[100];
    //maximum no of books are 100

    int count=0;
    //count = to count number of book 
    
    

//verification 
int verified =1;//for while looping
char temp; 
char uname[100]="elc";
char pword[100]="elc";
char username[100],password[100];
while(verified)
{
printf("Please enter your user name :\n");
scanf("%[^\n]",username);
printf("Please enter your password :\n"); 
scanf("%c",&temp);
scanf("%[^\n]",password);
verified=verify(uname,pword,username,password);
//verified=0;
}
//end of verification

int input=0;
// input = menu driven program input
    while(input!=6)
{
    printf("1.ADD BOOK \n2.DELETE BOOK \n3.SEARCH BOOK \n4.VIEW BOOK \n5.EDIT BOOK \n6.TO EXIT \n");
    printf("ENTER YOUR CHOICE \n");
    scanf("%d",&input);
    switch(input)
    {
        case 1:add(lib,&count);
        break;

        case 2:delete(lib,&count);
        break;

        case 3: search(lib,&count);
        break;  
        
        case 4: view(lib,&count);
        break;
         
        case 5:edit(lib,&count); 
        break;
        
        case 6:printf("THANK YOU");
        break;

        default:printf("PLEASE ENTER A CHOICE 1-6 \n");
        break;
    }
}
return 0;
}
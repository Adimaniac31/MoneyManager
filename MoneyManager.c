#include<stdio.h>
int main()
{ printf("Enter 'a' if you want to set budget and manage expenses and enter 'b' if you want to split money with friends in a trip\n");
  char d;
  scanf("%c",&d);
  if(d=='a')
{     
  float budget,expense=0,balance=0,expense_final=0,safe=0,warn=0;
    int days;
    printf("Enter the number of days you want to set budget for:");
    scanf("%d",&days);
    printf("\n");
    printf("Set The budget for %d days:",days);
    scanf("%f",&budget);
    printf("\n");
    int n;
    float amount;
    int arr[days][n];
    printf("We will recommend to add extra category as other for safer side\n");
    printf("\n");
    printf("Enter the no. of categories you will spend money for:");
    scanf("%d",&n);
    printf("\n");
    //for loop to take amount input in a 2d array of days and category
    for(int k=0;k<days;k++)
       {
        printf("*************INPUT******************\n");
          for(int i=0;i<n;++i)//i is category k is day
                { amount=0;
                   printf("Enter money spend on day %d and category %d :",k+1,i+1);
                   scanf("%f",&amount);
                   arr[k][i]=amount;
                   printf("\n");
                }
         expense=0;
         for(int i=0;i<n;i++)
                {
                   expense=expense+arr[k][i];
                   expense_final=expense_final+arr[k][i];
                }
          printf("**************OUTPUT****************\n");
          printf("The money spent on day %d is %f.\n",k+1,expense);
           printf("\n");
          printf("Total money spent after day %d is %f.\n",k+1,expense_final);
           printf("\n");
          balance=budget-expense_final;
          if(expense_final<=budget)
          {
            printf("You are left with %f money after %d day.\n",balance,k+1);
            printf("\n");
          }
          if(expense_final>budget)
          {
            printf("You have spent all your money!!!\n");
            printf("\n");
          }
          warn=0.75*budget;
          if(expense_final>=warn)
          {
            printf("You have spent over 75 percentage of your budget,so spend your money wisely now.\n");
            printf("\n");
          }
          safe=(balance/(days-(k+1)));
          if(expense_final<=budget)
          {
            printf("You are safe to spend %f money daily\n",safe);
            printf("\n");
          }
          if(expense_final>budget)
          {
            printf("Stop spending money you moron,you are already over budget,you have no money to spend safely\n");
            printf("\n");
          }
       }
       float extra=budget-expense_final;
       if(extra>=0)
       {
        printf("You have saved %f\n",extra);
       }
       if(extra<0)
       {
        printf("You are overbudget by %f\n",(-extra));
       }
       float max=0,cost=0;
       int cat=0;
       for(int i=0;i<n;i++)
          {
               for(int k=0;k<days;k++)
               { 
               cost=cost+arr[k][i];//day will change and category will be same k is day and i is category
               if(cost>max)
               {
                max=cost;
                cat=i+1;
               }
               }     
          }
       printf("You spent most of your money %f on category %d\n",max,cat);   
}
//trip manager
  if(d=='b')
{
       int person,time=0,sum=0,trans=0,give=0;
       printf("Enter the no. of people came in trip\n");
       scanf("%d",&person);
       int money[person][person];
       money[0][0]=0;
       for(int i=0;i<person;i++)
       {
           money[i][i]=0;
           for(int k=0;k<person;k++)
           {
          
           if(i==k)
            {
              money[i][i]=0;
            }
          else if(i!=k){
            
             printf("Enter the NUMBER OF TIMES money given by %d to %d\n",i+1,k+1);
             scanf("%d",&time);
             sum=0;
             for(int j=1;j<=time;j++)
             {
               printf("Enter the transaction %d amount done by %d for %d \n",j,i+1,k+1);
               scanf("%d",&trans);
               sum=sum+trans;
             } 
             money[i][k]=sum; //i for k
         }
           
           }
       }    
           for(int i=0;i<person;i++)
          {
             for(int k=0;k<person;k++)
                 {
                      if(money[i][k]>money[k][i]) 
                      {
                         give=money[i][k]-money[k][i];
                         printf("Person %d has to give person %d %d rupees\n\n",k+1,i+1,give);
                         printf("Person %d has to give person %d 0 rupees\n\n",i+1,k+1);
                      }  
                 }
           }           
}     
printf("Thankyou for using the program\n");
   return 0;
}
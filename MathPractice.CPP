#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

int main()
{
	FILE *fp;
	int i,j,timing,num1,num2,op,input,result,resulttmp,right,score;
	char option,ID[7],checkID[7],prob[10][8];
	int Correct[10],Ur[10];


    /*Get and check ID no.*/
    while (1)
    {
	    printf("Please enter your ID no: ");
	    scanf("%s",ID);

	    if (isalpha(ID[0])&&isalpha(ID[1])&&isdigit(ID[2])&&isdigit(ID[3])&&isdigit(ID[4])&&isdigit(ID[5]))
	      	break; /* If the input ID is valid, then continue. */
	    else
			printf("Your ID is invalid. Please check it carefully!\n");
    }

	/*Main function*/
    while (1)
    {
	    /*Menu*/
	    printf("--------------------------------------\n");
	    printf("MENU\n(1)   Start a test\n(2)   Check scores\n(3)   Exit\nPlease choose an option: ");
	    scanf("%s",&option);

	    fp = fopen("record.txt","a+");/*Open FILE*/


	    /*1. Start a test*/
	    if (option == '1')
	    {
	      printf("--------------------------------------");
	      printf("\nFinish 10 math problems!\n");
	      right = 0; /* Reset counts of right answers*/

	      /*Get start time*/
	      time_t timeBegin, timeEnd;
	      timeBegin = time(NULL);

	      /*Randomly get operators and numbers*/
	      srand((int)time(NULL)); /*Use time as a seed*/
	      for (i=0;i<10;i++)
	        {
		      op = rand()%4;
		      switch (op)
		        {
		        case 0 :  /* Plus */
		          num1 = rand()%100;
		          num2 = rand()%(100 - num1);
		          printf("%d + %d = ",num1,num2);
		          scanf("%d",&input);
		          result = num1 + num2;
		          sprintf (prob[i],"%2d + %2d",num1,num2);
		          break;
		        case 1 :  /* Minus*/
		          num1 = rand()%100;
		          num2 = rand()%num1;
		          printf("%d - %d = ",num1,num2);
		          scanf("%d",&input);
		          result = num1 - num2;
		          sprintf (prob[i],"%2d - %2d",num1,num2);
		          break;
		        case 2 :  /* Multiply*/
		          num1 = rand()%100;
		          num2 = rand()%100;
		          while (num1 * num2 > 100)
		          {num2 = rand()%100;}
		          printf("%d * %d = ",num1,num2);
		          scanf("%d",&input);
		          result = num1 * num2;
		          sprintf (prob[i],"%2d * %2d",num1,num2);
		          break;
		        case 3:   /* Division*/
		          num1 = rand()%99 + 1;
		          num2 = rand()%100;
		          while (num1 * num2 >= 100)
		          {num2 = rand()%100;}
		          result = num1 * num2;
		          printf("%d / %d = ",result,num1);
		          scanf("%d",&input);
		          resulttmp = result;
		          result = num2;
		          sprintf (prob[i],"%2d / %2d",resulttmp,num1);
		          break;
		        }
		        /*Compare with the right result*/
		        Correct[i] = result;
		        Ur[i] = input;
		        if (input == result){right++;}
	        }

	      /*Print problems and answers*/
	      printf("-----------------------------------");
	      printf("\n Prob. | Correct Answ.  |  Ur Answ.\n");
	      for (j=0;j<10;j++)
	      {
	        printf("%7s %8d %13d\n",prob[j],Correct[j],Ur[j]);
	      }

	      /*Save ID, score and time into file*/
	      score = right * 10;
	      timeEnd = time(NULL);
	      timing = timeEnd - timeBegin;
	      fprintf(fp, "%s %d %d\n",ID,score,timing);
	      fclose(fp);
	      printf("--------------------------------------\n");
	    }


	    /*2. Records*/
	    if (option == '2')
	    {
	      printf("--------------------------------------");
	      printf("\nYour previous records are:\n");
	      
	      while(fscanf(fp, "%s %d %d",checkID,&score,&timing) != EOF)	/*Check ID and search for records*/
	      {
	        if ( strcmp(ID,checkID) == 0 )
	        {
	          printf("%6s %4d %5d seconds\n",ID,score,timing);
	        }
	      }
	      fclose(fp);
	      printf("--------------------------------------\n");
	    }


	    /*3. Exit*/
	    if (option == '3')
	    {
			fclose(fp);
		    exit(0);
	    }

	    /*4. Invalid option*/
	    else
		{
			printf("Invalid option.\n");
		    fclose(fp);
		}
    }
}

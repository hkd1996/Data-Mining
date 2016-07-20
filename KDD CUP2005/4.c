#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
//-------------------------------------------------------------------------------------------------
char query[20],word1[20],word2[20],arr1[5],arr2[5];
int sp,val,array1[5],array2[5],final[5],size=0;
static int p1=0,p2=0;
FILE *fp;
//-------------------------------------------------------------------------------------------------
void fetchandfind(char word[20])
{
	char tempquery[20],a[20];
	int i;
	for (int i = 0; i < 20; ++i)
    {
    	tempquery[i]=NULL;
    } 
    strcpy(a,word);
   fp=fopen("data.txt","r");
   if ( fp != NULL )
      {
      		char line [ 100 ]; // SUITABLE SIZE OF 30
      	x:	while ( fgets ( line, sizeof line, fp ) != NULL ) // READ A LINE 
      		{
      			for(i=0;line[i]!=' ';i++)
      			tempquery[i]=line[i];
      			if(strcmp(tempquery,a)==0)
      			{
      				if(strcmp(word1,a)==0)
      				{
      					for (int i = 0; line[i]!='\0'; ++i)
              	 {
                 			 if(isdigit(line[i]))
                  			{
                     				//STORE IT IN AN ARRAY
                     			arr1[p1++]=line[i];
                     			
                        }
                 }
                 for(i = 0; arr1[i]!='\0'; i++)
                 {
                    array1[i] = arr1[i]-'0';
                 }
      				
          		}
              else
              {
                  for (int i = 0; line[i]!='\0'; ++i)
                 {
                       if(isdigit(line[i]))
                        {
                            //STORE IT IN AN ARRAY
                          arr2[p2++]=line[i];
                          
                        }
                 }
                 for(i = 0; arr2[i]!='\0'; i++)
                 {
                    array2[i] = arr2[i]-'0';
                 } 
              }
              break;
      				
      			}
      			

      			else
      			{
      				for (int i = 0; i < 20; ++i)
      				{
      					tempquery[i]=NULL;
      				}
      				goto x;
      			}
      			

      			  
     		 }
      }
      fclose(fp);	


}
//-------------------------------------------------------------------------------------------------

void splitquery()
{
	for (int i=0;i<20;++i)
   {
      if(query[i]==' ')
      {
         sp=i-1;
         break;
      }
   }
   for (int i = 0; i <= sp; ++i)
   {
      word1[i]=query[i];
   }
   fetchandfind(word1);
   for (int j =sp+1; j<20; ++j)
   {
      word2[j-(sp+2)]=query[j]; // COPY EXCLUDING THE SPACE. HENCE SP+2 AND NOT SP+1
   }
   fetchandfind(word2);
}
 //-------------------------------------------------------------------------------------------------
   void category()
   {
     int uni[10],inter[5],i,j,k=0,l=0,flag=0;
     for(i=0;i<10;i++)
      uni[i]=0;
      for(i=0;i<5;i++)
      inter[i]=0;
     //-------------------------------------------------------------------------------------------------
     for(i=0;i<p1;i++) 
     { 
        uni[k]=array1[i]; 
        k++; 
     } 
    for(i=0;i<p2;i++)                               // UNION
    { 
      flag=0; 
      for(j=0;j<p1;j++) 
      { 
         if(array2[i]==uni[j]) 
          { 
              flag=1; 
              break; 
          } 
    } 
    if(flag==0) 
    { 
        uni[k]=array2[i]; 
        k++; 
    } 

  }

     //-------------------------------------------------------------------------------------------------
  flag=0;
  for(i=0;i<p1;i++) 
   { 
      flag=0; 
      for(j=0;j<p2;j++) 
      { 
          if(array1[i]==array2[j])              // Intersection
          { 
              flag=1; 
               break; 
           } 
      } 
      if(flag==1) 
      {      
          inter[l]=array1[i]; 
          l++; 
       } 

    } 
      //-------------------------------------------------------------------------------------------------
    if(l==0)
    {
       for(i=0;i<5;i++)
       {
        final[i]=uni[i];
        if(final[i])
        printf("%d\t",final[i]);                      //Final categorization
       }
     }
     else
     {
          for(i=0;i<l;i++)
          {
           final[i]=inter[i];
           if(final[i])
           printf("%d\t",final[i]);
          }
            
     }
  }
//-------------------------------------------------------------------------------------------------


int main()
{
	printf("Enter the query to be searched\n");
	gets(query);
   //SPLIT QUERY
    splitquery();
     for(int i=0;array1[i]!=0;i++)
     printf("%d\t",array1[i]);
    printf("\n");
    for(int i=0;array2[i]!=0;i++)
      printf("%d\t\n",array2[i]);
    printf("Final Categorization is\n");
   category();
   printf("\n");

}
//-------------------------------------------------------------------------------------------------
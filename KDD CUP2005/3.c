#include<stdio.h>
#include<ctype.h>
#include<string.h>
//--------------------------------------------------------------------------------------------------
int p,sp=0,pointer=0;
char query[20],tempquery[20],word1[10],word2[10],attribute1[5],attribute2[5],tempword[10];
FILE *file;
//--------------------------------------------------------------------------------------------------
// SPLITS A QUERY IF IT IS HAS MORE THAN 1 WORD IN IT
void splitquery(char tempquery[20])
{
   for (int i=0;i<20;++i)
   {
      if(tempquery[i]==' ')
      {
         sp=i-1;
         break;
      }
   }
   for (int i = 0; i <= sp; ++i)
   {
      word1[i]=tempquery[i];
   }
   for (int j =sp+1; j<20; ++j)
   {
      word2[j-(sp+2)]=tempquery[j]; // COPY EXCLUDING THE SPACE. HENCE SP+2 AND NOT SP+1
   }

}
//--------------------------------------------------------------------------------------------------
//FINDS THE NUMBERS/CATEGORIES IN THE DATA FILE AND ADDS THEM TO AN ARRAY
void fetchandfind(char word1[10])
{
   file=fopen("data.txt","r");
   if ( file != NULL )
      {
      char line [ 100 ]; // SUITABLE SIZE OF 30
      while ( fgets ( line, sizeof line, file ) != NULL ) // READ A LINE 
      {
         for (int i = 0; i < sizeof(word1); ++i)
         {
            tempword[i]=line[i];// COPY WORD TO COMPARE WITH WORD 1
            if(!strcmp(tempword,word1))
            {
               //FETCH CATEGORY
               for (int i = 0; i < sizeof line; ++i)
               {
                  if(isdigit(line[i]))
                  {
                     //STORE IT IN AN ARRAY
                     attribute1[pointer++]=line[i];
                     puts(attribute1);
                  }
               }
            }
         }
      }
      //========================================================================//
      //WORD 2
      while ( fgets ( line, sizeof line, file ) != NULL ) // READ A LINE 
      {
         for (int i = 0; i < sizeof(word1); ++i)
         {
            tempword[i]=line[i];// COPY WORD TO COMPARE WITH WORD 1
            if(!strcmp(tempword,word1))
            {
               //FETCH CATEGORY
               for (int i = 0; i < sizeof line; ++i)
               {
                  if(isdigit(line[i]))
                  {
                     //STORE IT IN AN ARRAY
                     attribute1[pointer++]=line[i];
                     puts(attribute1);
                  }
               }
            }
         }
      }

      fclose ( file );
      }
}
//--------------------------------------------------------------------------------------------------
int main()
{
	printf("Enter the query to be searched\n");
	gets(query);
   //SPLIT QUERY
   splitquery(query);
	//FETCH AND FIND 
   fetchandfind(word1);
   fetchandfind(word2);
}
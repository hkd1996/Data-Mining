#include<stdio.h>
#include<ctype.h>
#include<string.h>
//--------------------------------------------------------------------------------------------------
int p,sp=0;
char query[20],tempquery[20],word1[10],word2[20],attribute[21][5];
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
void fetchandfind()
{
   file=fopen("data.txt","r");
   if ( file != NULL )
      {
      char line [ 30 ]; // suitable line size of 30
      while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
      {
        for(int i=0;i<sizeof line;i++)
        {
            if(isdigit(line[i]))
            {
               p=i;
               
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
   puts(word1);
   puts(word2);
	//FETCH AND FIND
   fetchandfind();

}
//--------------------------------------------------------------------------------------------------
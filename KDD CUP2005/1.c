#include<stdio.h>
#include<string.h>
int main()
{
	char query[20];
	FILE *file;
	printf("Enter the query to be searched\n");
	gets(query);
	//FETCH AND FIND
	file=fopen("data.txt","r");
	if ( file != NULL )
   	{
      char line [ 30 ]; /* or other suitable maximum line size */
      while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
      {
         fputs ( line, stdout ); /* write the line */
      }
      fclose ( file );
   	}

}
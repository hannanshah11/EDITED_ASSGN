/*Program to check correctness limited to '{','[','(' */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char expr[100];
	int bf = 0; //Initial balance factor equals zero
	int i;

    char file_name[100];
    printf("Enter file name: \n");
    scanf("%s", file_name);

    // Reading data from the file
    FILE *f = fopen(file_name, "rb");
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);  //same as rewind(f);

    char *string = malloc(fsize + 1);
    fread(string, fsize, 1, f);
    fclose(f);
    string[fsize] = 0;

    strcpy(expr, string);

	//Scanning will get started
	i = 0;
	while(expr [i] != '\0')
		{if (expr[i] == '{')
	  bf++ ;
	  else if (expr[i] == '}'){	
	  bf-- ;
	  if (bf < 0)
         break; //Terminate Scanning Search
	  	}
	  	i++;

}

//Data For Output 
if (bf == 0)
	printf(" Balanced Paranthesis.\n");
else
	printf("Unbalanced Paranthesis.\n");
return 0;
}
#include "ec_main.h"
 
int main (int args, char *filename[]) 
{
	FILE *pToFIle = fopen(filename[1], "r"); // Just like others we are getting the file name which one we want to execute and reading that :P
	
	// printf(" started ");
	char input[512] = "",
		functions[512] = "";
	
	while ( fgets( input, 512, pToFIle) ) // Get input from the file line by line
	{ 
		int count = 0;
		memset(functions, '\0', strlen(functions)); // cleaning up the memory of functions for some retarded erroes
		
		int inputLenth = strlen(input); 

		// realloc(input, inputLenth*sizeof(char));
		// We Need to remove extra Spaces from front
		RemoveStringSpaces(input, 0);
	
		inputLenth = strlen(input);
		
		// Loop will continue to check for any kind of space between if spave we know that we found our function
		for (count = 0; count < inputLenth; count++) 
		{
			printf("");
			if (input[count] != ' ') 
				functions[count] = input[count];
			else {
				known_functions(functions, input, count);
				break;
			}
		}
	}

	fclose(pToFIle);
	return 0;
}

void known_functions(char functions[], char input[], int count) {
	int new_count, temp_count = 0, empty = 0;

	switch ( IdentifyFunction(functions) )
	{
		case INVALID_FUNCTION:
			return;
			break;
		case console_print_function:
			ConsolePrintFunc(input, count);
			break;
		default:
			return;
	}
}
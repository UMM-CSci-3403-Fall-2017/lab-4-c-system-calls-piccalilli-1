#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 1024

bool is_vowel(char c) { 
    /* 
     * Returns true if c is a vowel (upper or lower case), and 
     * false otherwise. 
     */ 
	//We create a string that contains all the vowels
	//Then return true if c is in this string, and false otherwise
	char string[] = "aeiouAEIOU";
	return strchr(string, c) != NULL;

}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
    /*
     * Copy all the non-vowels from in_buf to out_buf. 
     * num_chars indicates how many characters are in in_buf, 
     * and this function should return the number of non-vowels that
     * that were copied over.
     */

     int size, i, k;
     size = 0;
     k = 0;
     for(i = 0; i < num_chars; ++i){
  	
	//if the character is not a vowel, put it in the outBuffer
	//and increment size and k
	if(is_vowel(in_buf[i]) == false){
		out_buf[k] = in_buf[i];
		k++;
		size++;
	}	
     }

     return size;
}

void disemvowel(FILE* inputFile, FILE* outputFile) { 
    /*
     * Copy all the non-vowels from inputFile to outputFile.
     * Create input and output buffers, and use fread() to repeatedly read
     * in a buffer of data, copy the non-vowels to the output buffer, and
     * use fwrite to write that out. 
     */
        //Defining our int variables, and in and out buffers
	int nRead, nWrite;
	char* inBuffer; 
	char* outBuffer;
	
	//Allocating memory for our buffers
	inBuffer = (char*) calloc(BUF_SIZE + 1, sizeof(char));
	outBuffer= (char*) calloc(BUF_SIZE, sizeof(char));
	
	//While that keeps putting 'chuncks' of data into a buffer, untill all data is read
	while(0 < (nRead=fread(inBuffer, sizeof(char), BUF_SIZE, inputFile))){

		nWrite=copy_non_vowels(nRead, inBuffer, outBuffer); 
		fwrite(outBuffer, sizeof(char), nWrite, outputFile);
	 }
	
	//closing our input and output files
	fclose(inputFile);
	fclose(outputFile);

}

int main(int argc, char *argv[]) { 
    FILE *inputFile; 
    FILE *outputFile;

    // Code that processes the command line arguments 
    // and sets up inputFile and outputFile.
    inputFile = stdin;
    outputFile = stdout;

    //Let inputFile be the second argument
    if(argc == 2){
	    inputFile = fopen(argv[1], "r");
    }
	
    //let inputFile be the the second argument, and outputfile the third
    else if(argc ==  3){
	    inputFile = fopen(argv[1], "r");
	    outputFile = fopen(argv[2], "w");
    }
    else{
	    //Return input incorrect message if there's more than 3 arguments or less than 1, and exit from the program
	    printf("Input is incorrect");
	    exit(0);
    }
	
    disemvowel(inputFile, outputFile);

    return 0; 
}

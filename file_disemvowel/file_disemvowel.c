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

     int size, i;
     for(i = 0; i < num_chars; ++i){
	if(is_vowel(in_buf[i]) == false){
		in_buf[i] = out_buf[i];
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
	FILE* outFile;
	FILE* inFile;
	inFile = fopen(inputFile, "r");
	outFile = fopen(outputFile, "w+");
        int nRead, nWrite;
	char* inBuffer; 
	char* outBuffer;

	inBuffer = (char*) calloc(BUF_SIZE, sizeof(char));
	outBuffer= (char*) calloc(BUF_SIZE, sizeof(char));

	while(0 < (nRead=fread(inBuffer, sizeof(char), BUF_SIZE, inFile))){
		nWrite=copy_non_vowels(nRead, inBuffer, outBuffer); 
		fwrite(outBuffer, 1, nWrite, outFile);
	 }

	fclose(inFile);
	fclose(outFile);

}

int main(int argc, char *argv[]) { 
    FILE *inputFile; 
    FILE *outputFile;

    // Code that processes the command line arguments 
    // and sets up inputFile and outputFile.
    inputFile = stdin;
    outputFile = stdout;

    disemvowel(inputFile, outputFile);

    return 0; 
}

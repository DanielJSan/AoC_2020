#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Advent of Code 2020 - Day 1 - Star 1
//Daniel Juanes Sánchez - danieljsan@usal.es

int main() {

	FILE *pFile = fopen("input.txt", "r");
	
	if(pFile == NULL) {
	
		fprintf(stderr, "Null file\n");
		return 1;
	
	}
	
	fseek(pFile, 0, SEEK_END);
	int tam = ftell(pFile);
	rewind(pFile);
	
	char input[tam];
	int num[200];
	
	int i = 0;
	int j = 0;
	int k = 0;
	int exit = 0;
	
	printf("Input data table: \n");
	while (fscanf(pFile, "%s", input) != EOF) { //Reading input.txt file
		
		if(j == 10) {
		
			printf("|\n");
			j = 0;
		}
		
		printf("| %s\t ", input);
		
		num[i] = atoi(input); //Char to int parse
		
		i++;
		j++;
		
	}
	
	//fprintf(stderr, "File scanned succesfully\n");
	printf("|\n\n");
	
	for(i = 0; i < 199; i++) { //First star
	
		for(j = 1; j < 200; j++) {
		
			if(num[i] + num[j] == 2020) {
				
				printf("Star 1 flag: %d\n", num[i] * num[j]);
				exit = 1;
			}
			
		}
		
		if (exit) {
		
			break;
		
		}
	
	} 
	
	for(i = 0; i < 198; i++) { //Second star
	
		for(j = 1; j < 199; j++) {
			
			for(k = 2; k < 200; k++) {
		
				if(num[i] + num[j] + num[k] == 2020) {

					printf("Star 2 flag: %d\n", num[i] * num[j] * num[k]);
					return 1;
				}
			}
		}
	}
	
	fclose(pFile);
	
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Advent of Code 2020 - Day 1 - Star 1
//Daniel Juanes Sánchez - danieljsan@usal.es

int main() {

	FILE *pFile = fopen("input.txt", "r");
	
	fseek(pFile, 0, SEEK_END);
	int tam = ftell(pFile);
	rewind(pFile);
	
	char input[800];
	int num[200];
	
	
	//printf("tam = %d\n", tam);
	
	int i, j, k, exit= 0;
	
	while (fscanf(pFile, "%s", input) != EOF) { //Reading input.txt file
	
		printf("%s\n", input);
		num[i] = atoi(input); //Char to int parse
		
		i++;
		
	}
	
	
	/*
	while (fgets(input, 200 + 1, pFile) != 0) { //Reading input.txt file
	
		printf("%s\n", input);
		num[i] = atoi(input); //Char to int parse
		i++;
		
	}
	*/
	
	/*
	char* dump = (char *)malloc(sizeof(char) * tam);
	
	while (fscanf(pFile, "%s", input) != EOF) {
		printf("%s\n", input);
		dump[i] = atoi(input); //Char to int parse
		i++;
	}
	*/
	
	

	for(i = 0; i < 199; i++) { //First star
	
		for(j = 1; j < 200; j++) {
		
			if(num[i] + num[j] == 2020) {
				
				printf("\n%d * %d = ", num[i], num[j]);
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
					
					printf("\n%d * %d * %d = ", num[i], num[j], num[k]);
					printf("Star 2 flag: %d\n", num[i] * num[j] * num[k]);
					return 1;
				}
			}
		}
	}

	fclose(pFile);
	
}


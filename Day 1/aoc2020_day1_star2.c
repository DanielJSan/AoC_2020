#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Advent of Code 2020 - Day 1 - Star 2
//Daniel Juanes Sánchez - danieljsan@usal.es

int main() {

	FILE *pFile = fopen("input.txt", "r");

	char input[800];
	int num[200];
	
	int i, j, k = 0;
	
	while (fscanf(pFile, "%s", input) != EOF) {
	
		printf("%s\n", input);
		num[i] = atoi(input);
		i++;
		
	}
	
	for(i = 0; i < 198; i++) {
	
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

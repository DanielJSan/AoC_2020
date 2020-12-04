#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getValidPasswords(int bottomRange, int topRange, char keyCharacter, char* password, int position);
void parseRange(char* range, int* parsedRange);

//Advent of Code 2020 - Day 2 - Star 1
//Daniel Juanes Sánchez - danieljsan@usal.es

int main() {

	FILE *pFile = fopen("input.txt", "r");
	
	if(pFile == NULL) {
		printf("Error reading file.\n");
		return -1;

	}
	
	char range1[1000];
	char range2[1000];
	char key[1000];
	char pass[1000][25];
	
	int bottomRange[1000];
	int topRange[1000];
	
	int validPasswords;
	int i = 0;
	
	while ((fscanf(pFile, "%[^-]-%[^ ]%[^:]:%[^\n]", range1, range2, key, pass[i]) != EOF) && i < 1000) { //Reading input.txt file
	//while ((fscanf(pFile, "%d-%d %c: %s\n", &range1[i],&range2[i],&key[i],pass[i]) != EOF) && i < 1000) {
		
		printf("%s - %s\t|\t%s\t|%20s\t| ---- \t%d\t|", range1, range2, key, pass[i], i+ 1);
		
		i++;
		
	}
	
	parseRange(range1, bottomRange);
	parseRange(range2, topRange);
	
	
	
	for(i = 0; i < 1000; i++) {
	
		validPasswords += getValidPasswords(bottomRange[i], topRange[i], key[i], pass[i], i);
	
	}

	for(i = 0; i < 1000; i++) {
	
		printf("\n%d - %s", i + 1, key + i);
	
	}

	printf("\n\nThere's %d valid passwords in the input text file.", validPasswords);
	printf("\n");
	
	fclose(pFile);
	
}


int getValidPasswords(int bottomRange, int topRange, char keyCharacter, char* password, int position) {

	int charUsesInPassword = 0;

		
	printf("\n%d ---- Char: %c\t Password: %20s \t\t Length: %10ld", (position + 1), keyCharacter, password, strlen(password));
	
	for(int j = 0; j < strlen(password); j++) {
	
		if(password[position] == keyCharacter) {
		
			charUsesInPassword++;
		
		}
		
	}
	
	if((bottomRange < charUsesInPassword) && (charUsesInPassword < topRange)) {
	
		return 1;
	
	}
	else {
	
		return 0;
	
	}	
}

void parseRange(char* range, int* parsedRange) {

	for(int i = 0; i < 1000; i++) {
	
		parsedRange[i] = atoi(range + i);
	
	}

}

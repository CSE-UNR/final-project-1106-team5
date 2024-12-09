// Chloe Facchinetti, Carla Embuido, and Kainoa Griffith
// 12/10/2024
// Final Project: Madlibs

#include <stdio.h>

#define CAP_1 50
#define CAP_2 500
#define FILENAME "madlib1.txt"

int stringLength(int row, int cols, char arr[][cols]);
int stringCopy(int row1, int cols1, char source[][cols1], int row2, int cols2, char dest[][cols2]);
void storeMadlibs(FILE* fin, int rows, int cols, char arr[][cols], int* lines);
void getInput(int rows, int cols, char arr[][cols], int rows2, int cols2, char arr2[][cols2]);
void userMadlibs(int rows, int cols, char arr[][cols], int rows2, int cols2, char arr2[][cols2]);
void displayMadlibs(int rows, int cols, char arr[][cols]);

int main(){
	FILE* fp;
	char madlib[CAP_1][CAP_2], userInput[CAP_1][CAP_1];
	int lines;
	
	fp = fopen(FILENAME, "r");
	if(fp == NULL){
		printf("Can't open file.\n");
		return 0;
	}	
	storeMadlibs(fp, CAP_1, CAP_2, madlib, &lines);
	fclose(fp);
	
	getInput(lines, CAP_2, madlib, CAP_1, CAP_1, userInput);
	
	userMadlibs(CAP_1, CAP_2, madlib, CAP_1, CAP_1, userInput);
	
	displayMadlibs(lines, CAP_2, madlib);
	
	return 0;
}

int stringLength(int row, int cols, char arr[][cols]){
	int counter;
	for(counter = 0; arr[row][counter] != '\0'; counter++){
	}
	return counter;
}

int stringCopy(int row1, int cols1, char source[][cols1], int row2, int cols2, char dest[][cols2]){
	for(int i = 0; source[row1][i] != '\0'; i++){
		dest[row2][i] = source[row1][i];
	}
	dest[row2][stringLength(row1, cols1, source)] = '\n';
	dest[row2][stringLength(row1, cols1, source)+1] = '\0';
}

void storeMadlibs(FILE* fin, int rows, int cols, char arr[][cols], int* lines){
	int i = 0, j = 0;
	char letter;
	while(fscanf(fin, "%c", &letter) == 1){
		if(letter == '\n'){
			arr[i][j] = letter;
			arr[i][j+1] = '\0';
			i++;
			j = 0;
		}
		else{
			arr[i][j] = letter;
			j++;
		}
	}
	arr[i][j+1] = '\0';
	*lines = i;
}

void getInput(int rows, int cols, char arr[][cols], int rows2, int cols2, char arr2[][cols2]){
	int rowInd = 0;
	for(int i = 0; i < rows - 2; i+=2){
		switch(arr[i+1][0]){
			case 'A':
				printf("Please enter an adjective: ");
				scanf("%s", arr2[rowInd]);
				rowInd++;
				break;
			case 'N':
				printf("Please enter a noun: ");
				scanf("%s", arr2[rowInd]);
				rowInd++;
				break;
			case 'V':
				printf("Please enter a verb: ");
				scanf("%s", arr2[rowInd]);
				rowInd++;
				break;
		}
	}
}

void userMadlibs(int rows, int cols, char arr[][cols], int rows2, int cols2, char arr2[][cols2]){
	int rowInd = 0;
	for(int i = 0; i < rows - 2; i+=2){
		switch(arr[i+1][0]){
			case 'A':
				stringCopy(rowInd, cols2, arr2, i+1, cols, arr);
				rowInd++;
				break;
			case 'N':
				stringCopy(rowInd, cols2, arr2, i+1, cols, arr);
				rowInd++;
				break;
			case 'V':
				stringCopy(rowInd, cols2, arr2, i+1, cols, arr);
				rowInd++;
				break;
		}
	}
}

void displayMadlibs(int rows, int cols, char arr[][cols]){
	for(int i = 0; i < rows; i++){
		for(int j = 0; arr[i][j] != '\0'; j++){
			if(arr[i][j] != '\n'){
				printf("%c", arr[i][j]);
			}
			else if(arr[i+1][0] != '.' && arr[i+1][0] != ',' && arr[i+1][0] != '!' && arr[i+1][0] != '?'){
				printf(" ");
			}
		}
	}
	printf("\n");
}

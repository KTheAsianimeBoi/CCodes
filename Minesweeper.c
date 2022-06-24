#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>




enum { SIZE = 5, EMPTY = -1, BOMB = 99 };

int bombNum[SIZE][SIZE];
int isOpened[SIZE][SIZE];

void PrintBoardInit() {
	for (size_t i = 0; i < SIZE; i++)
	{
		for (size_t j = 0; j < SIZE; j++)
		{
			/* code */
			printf("- ");
		}
		printf("\n");
	}

}
int isWin(int isOpened[SIZE][SIZE], int board[SIZE][SIZE]) {

	for (size_t i = 0; i < SIZE; i++)
	{
		for (size_t j = 0; j < SIZE; j++)
		{
			if (isOpened[i][j] == 0 && board[i][j] != BOMB) {
				return 0;
			}
		}

	}
	return 1;

}
void setBombs(int board[SIZE][SIZE], int numOfBombs)
{
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			board[j][i] = EMPTY;
		}
	}

	srand(2021);
	int count = 0;
	while (count < numOfBombs) {
		int x = rand() % 5;
		int y = rand() % 5;
		if (board[y][x] == EMPTY) {
			board[y][x] = BOMB;
			++count;
		}
	}
}



void fillNumOfBombs(int board[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			bombNum[i][j] = 0;
		}

	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (board[i][j] == BOMB) {
				continue;
			}

			if (i - 1 >= 0) { // Up Row
				if (board[i - 1][j] == BOMB) {//mid
					bombNum[i][j]++;
				}
				if (j - 1 >= 0) {//left
					if (board[i - 1][j - 1] == BOMB) {
						bombNum[i][j]++;
					}
				}
				if (j + 1 <= SIZE - 1) {//right
					if (board[i - 1][j + 1] == BOMB)
					{
						bombNum[i][j]++;
					}

				}
			}



			if (i + 1 <= SIZE - 1) { // Down Row
				if (board[i + 1][j] == BOMB) { //MID
					bombNum[i][j]++;
				}
				if (j - 1 >= 0) { //Left
					if (board[i + 1][j - 1] == BOMB) {
						bombNum[i][j]++;
					}
				}
				if (j + 1 <= SIZE - 1) {//Right
					if (board[i + 1][j + 1] == BOMB)
					{
						bombNum[i][j]++;
					}

				}
			}


			//SAME ROW
			if (j - 1 >= 0) {//Left
				if (board[i][j - 1] == BOMB) {
					bombNum[i][j]++;
				}
			}

			if (j + 1 <= SIZE - 1) {//right
				if (board[i][j + 1] == BOMB) {
					bombNum[i][j]++;
				}
			}
		}




	}
}
void showBoard(int board[SIZE][SIZE], int x, int y)
{
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (j != 0) {
				printf(" ");
			}
			if (isOpened[i][j] == 1) {
				printf("%d", bombNum[i][j]);
				continue;
			}
			if (y == i && x == j) {
				if (board[i][j] == BOMB) {
					printf("*");
				}
				else {
					printf("%d", bombNum[i][j]);
				}
			}
			else {
				printf("-");
			}
		}
		printf("\n");
	}
}

void playGame(int board[SIZE][SIZE])
{
	while (true) {
		int x, y;
		scanf("%d %d", &x, &y);
		showBoard(board, x, y);
		printf("\n");
		isOpened[y][x] = 1;
		if (board[y][x] == BOMB) {
			printf("You lose.");
			exit(0);
		}
		if (isWin(isOpened, board)) {
			printf("You win.");
			exit(0);
		}
	}


}

int main(int argc, char** argv)
{
	int board[SIZE][SIZE];

	setBombs(board, 5);
	for (size_t i = 0; i < SIZE; i++)
	{

		for (size_t j = 0; j < SIZE; j++)
		{
			isOpened[i][j] = 0;
		}

	}


	fillNumOfBombs(board);
	PrintBoardInit();
	printf("\n");
	playGame(board);

	return 0;
}



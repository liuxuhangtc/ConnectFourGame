/* Main Function*/

#include "connectfour.h"


int main(void) {
	const char *TOKENS = "AB";
	char board[ROWS * COLS];
	memset(board, ' ', ROWS * COLS);

	int round, done = 0;

	for (round = 0; round < ROWS * COLS && !done; round++) {
		print_board(board);
		while (!place_token(board, round % 2, TOKENS)) {
			print_board(board);
			puts("**Column full!**\n");
		}
		done = check_win(board);
	}
	print_board(board);

	if (round == ROWS * COLS && !done) {
		puts("Tie Game! Play Again");
	}
	else {
		round--;
		printf("Player %d (%c) wins!\n", round % 2 + 1, TOKENS[round % 2]);
	}

	return 0;
}
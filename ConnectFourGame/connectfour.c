/*Functions*/

#include "connectfour.h"

void print_board(char *board) {
	int row, col;

	puts("\n**** Welcome Connect Four Game ****\n");
	for (row = 0; row < ROWS; row++) {
		for (col = 0; col < COLS; col++) {
			printf("| %c ", board[COLS * row + col]);
		}
		puts("|");
		puts("-----------------------------");

	}
	puts("  1   2   3   4   5   6   7\n");

}
int place_token(char *board, int player, const char *PIECES) {
	int row, col = 0;
	printf("Player %d (%c):\nEnter number coordinate(1-7): ", player + 1, PIECES[player]);

	while (1) {
		if (1 != scanf("%d", &col) || col < 1 || col > 7) {
			while (getchar() != '\n');
			puts("Number out of bounds! Try again.");
		}
		else {
			break;
		}
	}
	col--;

	for (row = ROWS - 1; row >= 0; row--) {
		if (board[COLS * row + col] == ' ') {
			board[COLS * row + col] = PIECES[player];
			return 1;
		}
	}
	return 0;

}
int check_win(char *board) {
	return (ishorizontal(board) || isvertical(board) || isdiagonal(board));

}
int isfour(char *board, int a, int b, int c, int d) {
	return (board[a] == board[b] && board[b] == board[c] && board[c] == board[d] && board[a] != ' ');

}
int ishorizontal(char *board) {
	int row, col, idx;
	const int width = 1;

	for (row = 0; row < ROWS; row++) {
		for (col = 0; col < COLS - 3; col++) {
			idx = COLS * row + col;
			if (isfour(board, idx, idx + width, idx + width * 2, idx + width * 3)) {
				return 1;
			}
		}
	}
	return 0;

}
int isvertical(char *board) {
	int row, col, idx;
	const int height = 7;

	for (row = 0; row < ROWS - 3; row++) {
		for (col = 0; col < COLS; col++) {
			idx = COLS * row + col;
			if (isfour(board, idx, idx + height, idx + height * 2, idx + height * 3)) {
				return 1;
			}
		}
	}
	return 0;

}
int isdiagonal(char *board) {
	int row, col, idx, count = 0;
	const int right = 6, left = 8;

	for (row = 0; row < ROWS - 3; row++) {
		for (col = 0; col < COLS; col++) {
			idx = COLS * row + col;
			if (count <= 3 && isfour(board, idx, idx + left, idx + left * 2, idx + left * 3) || count >= 3 && isfour(board, idx, idx + right, idx + right * 2, idx + right * 3)) {
				return 1;
			}
			count++;
		}
		count = 0;
	}
	return 0;

}
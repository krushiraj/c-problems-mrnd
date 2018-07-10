/*
This struct denotes the move played by user, X means the x cordinate and Y means y cordinate.
*/
typedef struct ReversiMove {
	int x, y;
}ReversiMove;

/*
Create a ReversiMove struct (malloc/calloc etc) and return it.
Assign parameters x and y to its fields.
*/
ReversiMove *createMove(int x, int y) {
	ReversiMove* newMove = (ReversiMove*)malloc(sizeof(ReversiMove));
	newMove->x = x;
	newMove->y = y;
	return newMove;
}

/*
Take Only Valid Input x, y two integers . If Invalid input is entered ,Take input again . Keep Taking input until its valid
Hint : Use While Loop and isValidInput function
Cordinates are 1 indexed. Ie first row/column is denoted by 1 while giving input.
*/
int isvalidCoordinate(ReversiGame*, int, int);
int isValidMove(ReversiGame*, ReversiMove*);
ReversiMove *inputMove(ReversiGame *game) {
	int x, y;
	ReversiMove* move;
	do
	{
		if (game->turn == 1)
			printf("%s's turn(white)\n", game->player1name);
		else
			printf("%s's turn(black)\n", game->player2name);
		printf("Enter coordinates : ");
		scanf_s("%d", &x);
		scanf_s("%d", &y);
		move = createMove(x, y);

	} while (isvalidCoordinate(game, x, y) == 0 || isValidMove(game, move) == 0);

	return move;
}

/*
To check the validity of coordinate on the board
*/

int isvalidCoordinate(ReversiGame *game, int x, int y) {


	if (x<1 || x>game->rows) return 0;
	if (y<1 || y>game->cols) return 0;
	if (game->board[x][y] != ' ') return 0;

	return 1;
}

/*
Check if the move can be placed, if its going to make a valid capture to the opponent coins
*/

int isValidMove(ReversiGame *game, ReversiMove *move) {
	char opcolor;
	char plcolor;
	if (game->turn == 1)
	{
		opcolor = 'b';
		plcolor = 'w';
	}
	else {
		opcolor = 'w'; plcolor = 'b';
	}
	int row = move->x;
	int col = move->y;
	if (row < 1 || col < 1 || row>game->rows || col>game->cols) return 0;
	if (col> 1)
	{

		if (game->board[row][col - 1] == opcolor)
		{
			for (int i = col - 1; i >= 1; i--)
			{
				if (game->board[row][i] == ' ') break;
				if (game->board[row][i] == plcolor)
				{
					return 1;
				}
			}
		}

	}
	if (col < game->cols)
	{
		if (game->board[row][col + 1] == opcolor)
		{
			for (int i = col + 1; i <= game->cols; i++)
			{
				if (game->board[row][i] == ' ') break;
				if (game->board[row][i] == plcolor)
				{
					return 1;
				}
			}
		}
	}
	if (row > 1)
	{
		if (game->board[row - 1][col] == opcolor)
		{
			for (int i = row - 1; i >= 1; i--)
			{
				if (game->board[i][col] == ' ') break;
				if (game->board[i][col] == plcolor)
					return 1;
			}
		}
	}
	if (row < game->rows)
	{
		if (game->board[row + 1][col] == opcolor)
		{
			for (int i = row + 1; i <= game->rows; i++)
			{
				if (game->board[i][col] == ' ') break;
				if (game->board[i][col] == plcolor)
					return 1;
			}
		}
	}
	//left up
	if (row > 1 && col > 1)
	{
		if (game->board[row - 1][col - 1] == opcolor)
		{
			for (int i = row - 1, j = col - 1; i >= 1 && j >= 1; i--, j--)
			{
				if (game->board[i][j] == ' ')break;
				if (game->board[i][j] == plcolor)
					return 1;
			}
		}
	}
	//right down
	if (row < game->rows&&col < game->cols)
	{
		if (game->board[row + 1][col + 1] == opcolor)
		{
			for (int i = row + 1, j = col + 1; i <= game->rows&& j <= game->cols; i++, j++)
			{
				if (game->board[i][j] == ' ')break;
				if (game->board[i][j] == plcolor)
					return 1;
			}
		}
	}
	//left down
	if (row < game->rows&&col>1)
	{
		if (game->board[row + 1][col - 1] == opcolor)
		{
			for (int i = row + 1, j = col - 1; i <= game->rows&& j >= 1; i++, j--)
			{
				if (game->board[i][j] == ' ')break;
				if (game->board[i][j] == plcolor)
					return 1;
			}
		}
	}
	//right up
	if (row > 1 && col < game->cols)
	{
		if (game->board[row - 1][col + 1] == opcolor)
		{
			for (int i = row - 1, j = col + 1; i >= 1 && j <= game->cols; i--, j++)
			{
				if (game->board[i][j] == ' ')break;
				if (game->board[i][j] == plcolor)
					return 1;
			}
		}
	}
	return 0;
}

/*
Check if the player can move , if the player is not able to move, he looses the turn
and the opponent gets the chance to play.
If both players are not able to make a move, then the game ends.
*/

int hasMove(ReversiGame *game){

	for (int i = 1; i <= game->rows; i++)
	{
		for (int j = 1; j <= game->cols; j++)
		{
			if (game->board[i][j] == ' ')
			{
				ReversiMove* move = createMove(i, j);
				if (isValidMove(game, move) == 1)
					return 1;
			}
		}
	}
	return 0;
}

/*
Increment the number of moves in ReversiGame struct.
*/
void incrementMoves(ReversiGame *game) {
	game->NumberofMoves = game->NumberofMoves + 1;
	return;
}

/*
Toggle the turn in Reversi Game.
This function is to be called when you want to change the turn.
*/
void modifyTurn(ReversiGame *game) {
	game->turn = (-1)*game->turn;
	return;
}

/*
End Reversi Game.
Populate game->winner field accordingly with who won. 1 for white, -1 for black.
This function is to be called when the game is ended.
*/
void endGame(ReversiGame *game) {
	if (game->whiteCount > game->blackCount) game->winner = 1;
	else if (game->whiteCount<game->blackCount) game->winner = -1;
	else game->winner = 0;
	game->state = 1;

	return;
}

/*
Wrapper function you will call only modify to increment moves and modify the turn.
*/

void modify(ReversiGame *game) {
	incrementMoves(game);
	modifyTurn(game);
}


/*
This function performs move action on the board
Note : call validity check performs using above functions before making a move
returns :
true on move sucess
false if move is invalid
*/

bool playMove(ReversiGame *game, ReversiMove *move) {

	if (isValidMove(game, move) == 0) return false;
	char opcolor;
	char plcolor;
	if (game->turn == 1)
	{
		opcolor = 'b';
		plcolor = 'w';
	}
	else {
		opcolor = 'w'; plcolor = 'b';
	}
	int row = move->x;
	int col = move->y;
	//if (row < 1 || col < 1 || row>game->rows || col>game->cols) return false;
	game->board[row][col] = plcolor;
	if (plcolor == 'w')
	{
		game->whiteCount++;
	}
	else
		game->blackCount++;
	if (col> 1)
	{
		int flag = 0;

		if (game->board[row][col - 1] == opcolor)
		{
			for (int i = col - 1; i >= 1; i--)
			{
				if (game->board[row][i] == ' ') break;
				if (game->board[row][i] == plcolor)
				{
					flag = 1;
				}
			}
		}
		if (flag == 1)
		{
			for (int i = col - 1; i >= 1; i--)
			{
				if (game->board[row][i] == plcolor) break;
				game->board[row][i] = plcolor;

				if (plcolor == 'w'){ game->whiteCount++; game->blackCount--; }
				else { game->blackCount++; game->whiteCount--; }
			}
		}

	}
	if (col < game->cols)
	{
		int flag = 0;
		if (game->board[row][col + 1] == opcolor)
		{
			for (int i = col + 1; i <= game->cols; i++)
			{
				if (game->board[row][i] == ' ') break;
				if (game->board[row][i] == plcolor)
				{
					flag = 1;
				}
			}
			if (flag == 1)
			{
				for (int i = col + 1; i <= game->cols; i++)
				{
					if (game->board[row][i] == plcolor) break;
					game->board[row][i] = plcolor;
					if (plcolor == 'w'){ game->whiteCount++; game->blackCount--; }
					else { game->blackCount++; game->whiteCount--; }
				}
			}
		}
	}
	if (row > 1)
	{
		int flag = 0;
		if (game->board[row - 1][col] == opcolor)
		{
			for (int i = row - 1; i >= 1; i--)
			{
				if (game->board[i][col] == ' ') break;
				if (game->board[i][col] == plcolor)
					flag = 1;
			}
		}
		if (flag == 1)
		{
			for (int i = row - 1; i >= 1; i--)
			{
				if (game->board[i][col] == plcolor) break;
				game->board[i][col] = plcolor;
				if (plcolor == 'w'){ game->whiteCount++; game->blackCount--; }
				else { game->blackCount++; game->whiteCount--; }
			}
		}
	}
	if (row < game->rows)
	{
		int flag = 0;
		if (game->board[row + 1][col] == opcolor)
		{
			for (int i = row + 1; i <= game->rows; i++)
			{
				if (game->board[i][col] == ' ') break;
				if (game->board[i][col] == plcolor)
					flag = 1;
			}
		}
		if (flag == 1)
		{
			for (int i = row + 1; i <= game->rows; i++)
			{
				if (game->board[i][col] == plcolor) break;
				game->board[i][col] = plcolor;
				if (plcolor == 'w'){ game->whiteCount++; game->blackCount--; }
				else { game->blackCount++; game->whiteCount--; }
			}
		}
	}
	//left up
	if (row > 1 && col > 1)
	{
		int flag = 0;
		if (game->board[row - 1][col - 1] == opcolor)
		{
			for (int i = row - 1, j = col - 1; i >= 1 && j >= 1; i--, j--)
			{
				if (game->board[i][j] == ' ')break;
				if (game->board[i][j] == plcolor)
					flag = 1;
			}
		}
		if (flag == 1)
		{
			for (int i = row - 1, j = col - 1; i >= 1 && j >= 1; i--, j--)
			{
				if (game->board[i][j] == plcolor)break;
				game->board[i][j] = plcolor;
				if (plcolor == 'w'){ game->whiteCount++; game->blackCount--; }
				else { game->blackCount++; game->whiteCount--; }
			}
		}
	}
	//right down
	if (row < game->rows&&col < game->cols)
	{
		int flag = 0;
		if (game->board[row + 1][col + 1] == opcolor)
		{
			for (int i = row + 1, j = col + 1; i <= game->rows&& j <= game->cols; i++, j++)
			{
				if (game->board[i][j] == ' ')break;
				if (game->board[i][j] == plcolor)
					flag = 1;
			}
		}
		if (flag == 1)
		{
			for (int i = row + 1, j = col + 1; i <= game->rows&& j <= game->cols; i++, j++)
			{
				if (game->board[i][j] == plcolor)break;
				game->board[i][j] = plcolor;
				if (plcolor == 'w'){ game->whiteCount++; game->blackCount--; }
				else { game->blackCount++; game->whiteCount--; }
			}
		}
	}
	//left down
	if (row < game->rows&&col>1)
	{
		int flag = 0;
		if (game->board[row + 1][col - 1] == opcolor)
		{
			for (int i = row + 1, j = col - 1; i <= game->rows&& j >= 1; i++, j--)
			{
				if (game->board[i][j] == ' ')break;
				if (game->board[i][j] == plcolor)
					flag = 1;
			}
		}
		if (flag == 1)
		{
			for (int i = row + 1, j = col - 1; i <= game->rows&& j >= 1; i++, j--)
			{
				if (game->board[i][j] == plcolor)break;
				game->board[i][j] = plcolor;
				if (plcolor == 'w'){ game->whiteCount++; game->blackCount--; }
				else { game->blackCount++; game->whiteCount--; }
			}
		}
	}
	//right up
	if (row > 1 && col < game->cols)
	{
		int flag = 0;
		if (game->board[row - 1][col + 1] == opcolor)
		{
			for (int i = row - 1, j = col + 1; i >= 1 && j <= game->cols; i--, j++)
			{
				if (game->board[i][j] == ' ')break;
				if (game->board[i][j] == plcolor)
					flag = 1;
			}
		}
		if (flag == 1)
		{
			for (int i = row - 1, j = col + 1; i >= 1 && j <= game->cols; i--, j++)
			{
				if (game->board[i][j] == plcolor)break;
				game->board[i][j] = plcolor;
				if (plcolor == 'w'){ game->whiteCount++; game->blackCount--; }
				else { game->blackCount++; game->whiteCount--; }
			}
		}

	}
	game->NumberofMoves++;
	game->turn = (-1)*game->turn;
	if (hasMove(game) == 0) game->turn = game->turn * (-1);
	return true;
}


void printWinner(ReversiGame *game) {
	/*
	Sample output :
	Result Praveen has won. / Game is Drawn.
	*/
	printf("\n\n");

	if (game->winner == 1)
		printf("Result:\nCongrats! %s has won.\n", game->player1name);
	else if (game->winner == -1)
		printf("Result:\nCongrats! %s has won.\n", game->player2name);
	else
		printf("Result:\nGame is drawn\n");
}
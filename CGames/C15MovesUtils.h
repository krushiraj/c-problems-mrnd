int goLeft(Board *board);
int goUp(Board *board);
int goDown(Board *board);
int goRight(Board *board);
void swap(Board *board, int x1, int y1, int x2, int y2);
int isValidInput(char letter);



/*
Take Only Valid Input W,A,S,D,w,a,s,d . If Invalid input is entered ,Take input again . Keep Taking input until its valid
Hint : Use While Loop and isValidInput function
*/
char takeInput()
{
	char c;
	printf("\nplay:");
label:scanf("%c", &c);
	fflush(stdout);
	while (isValidInput(c) == 0)
	{
		goto label;
	}

	/*
	Take input and return it ,Use fflush if scanf is being used .
	Does this function need fflush ? Whats fflush ? Post your observations in the forum ,if fflush is present/not present.
	*/
	return c;
}
/*
Return 1 for Valid Input ie if w,a,s,d,W,A,S,D are entered .
Return 0 for all other inputs
*/
int isValidInput(char letter){
	if (letter == 'w' || letter == 'a' || letter == 's' || letter == 'd' || letter == 'W' || letter == 'A' || letter == 'S' || letter == 'D'){
		return 1;
	}
	return 0;
}
/*
Process the Given Input .Ie Decide whether to move Left , Right , Up ,or Down based on W,A,S,D,w,a,s,d.
Call goLeft Function if A or a are entered.,similarly do for all valid inputs .
Output :
Returns 1 : If Input is Valid and Move is also Valid .
Returns 0 : If Input if Valid and Move is Invalid .
Returns 0: If Input is invalid ,like other letters are entered or sent through takeInput.
*/
int processInput(Board *board, char inputChar)
{
	/*int i = isValidInput(inputChar);
	if (i == 0)return 0;*/
	int z = 0;
	if ((inputChar == 'a' || inputChar == 'A') && board->emptyTileCol != 3)
		z = goLeft(board);
	if ((inputChar == 'd' || inputChar == 'D') && board->emptyTileCol != 0)
		z = goRight(board);
	if ((inputChar == 's' || inputChar == 'S') && board->emptyTileRow != 0)
		z = goUp(board);
	if ((inputChar == 'w' || inputChar == 'W') && board->emptyTileRow != 3)
		z = goDown(board);

	/*
	Handle the input char inputChar ,which is either w,a,s,d,W,A,S,D for up,left,down and right
	*/
	return z;
}

/*
This Method is invoked when a character is taken as input ie User has played his ValidMove ,and you need to proccess that Move .
Steps to be Done :
1)Call ProcessInput
2)Call modifyMoveCountBasedOnProccessInput and also pass Step 1s output
3)Call clearAndRedrawScreen
4)Call printUser
*/
void playMove(Board *board, User *user, char choice)
{
	//printf("Play move not implemented yet , Remove this printf btw ");
	int i = processInput(board, choice);
	if (i == 1)
	{
		modifyMoveCountBasedOnProccessInput(user, 1);
	}
	clearAndRedrawScreen(board);
	printUser(user);
}

/*
Move the 0 Tile one position to the left .
Return 1 if the move is possible, 0 other wise .
*/
int goLeft(Board *board)
{
	int temp;
	int r = board->emptyTileRow;
	int c = board->emptyTileCol;
	temp = board->table[r][c];
	board->table[r][c] = board->table[r][c + 1];
	board->table[r][c + 1] = temp;
	board->emptyTileCol = c + 1;
	return 1;
	/*int temp;
	int r = board->emptyTileRow;
	int c = board->emptyTileCol;
	temp = board->table[r][c];
	board->table[r][c] = board->table[r][c - 1];
	board->table[r][c - 1] = temp;
	board->emptyTileCol = c - 1;
	board->emptyTileRow = r;
	return 1;*/
}

/*
Move the 0 Tile one position to the Right.
Return 1 if the move is possible, 0 other wise .
*/
int goRight(Board *board)
{
	int temp;
	int r = board->emptyTileRow;
	int c = board->emptyTileCol;
	temp = board->table[r][c];
	board->table[r][c] = board->table[r][c - 1];
	board->table[r][c - 1] = temp;
	board->emptyTileCol = c - 1;
	return 1;
	/*int temp;
	int r = board->emptyTileRow;
	int c = board->emptyTileCol;
	temp = board->table[r][c];
	board->table[r][c] = board->table[r][c + 1];
	board->table[r][c + 1] = temp;
	board->emptyTileCol = c + 1;
	return 1;*/
}

/*
Move the 0 Tile one position to the UP .
Return 1 if the move is possible, 0 other wise .
*/
int goUp(Board *board)
{
	int temp;
	int r = board->emptyTileRow;
	int c = board->emptyTileCol;
	printf("%d %d", board->emptyTileRow, board->emptyTileCol);
	temp = board->table[r][c];
	board->table[r][c] = board->table[r - 1][c];
	board->table[r - 1][c] = temp;
	board->emptyTileRow = r - 1;
	return 1;
}

/*
Move the 0 Tile one position to the Down .
Return 1 if the move is possible, 0 other wise .
*/
int goDown(Board *board)
{
	int temp;
	int r = board->emptyTileRow;
	int c = board->emptyTileCol;
	printf("%d %d", board->emptyTileRow, board->emptyTileCol);
	temp = board->table[r][c];
	board->table[r][c] = board->table[r + 1][c];
	board->table[r + 1][c] = temp;
	board->emptyTileRow = r + 1;
	return 1;
}
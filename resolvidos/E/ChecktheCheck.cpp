#include <stdio.h>
#include <stdlib.h>

/** 10196 - Check The Check */
char board[16][16];

/*color = preto = 0 color = branco = 1*/
bool isInCheck(int reiX, int reiY, int color)
{
	if (reiX != -1)
	{
		char knight = color ? 'n' : 'N';
		char pawn = color ? 'p' : 'P';
		char queen = color ? 'q' : 'Q';
		char rook = color ? 'r' : 'R';
		char bishop = color ? 'b' : 'B';

		if (board[reiX+2][reiY+1] == knight ||
			board[reiX+2][reiY-1] == knight ||
			board[reiX+1][reiY+2] == knight ||
			board[reiX+1][reiY-2] == knight || 
			board[reiX-1][reiY+2] == knight ||
			board[reiX-1][reiY-2] == knight || 
			board[reiX-2][reiY+1] == knight ||
			board[reiX-2][reiY-1] == knight)
		{
			return true;
		}

		int lineInc = color ? -1 : 1;
		if (board[reiX + lineInc][reiY-1] == pawn || board[reiX + lineInc][reiY+1] == pawn)
		{
			return true;
		}

		// Vetores com as direcoes possiveis do espaco
		const int DX[] = { 1, -1, 0,  0, -1, 1,  1, -1 };
		const int DY[] = { 0,  0, 1, -1,  1, 1, -1, -1 };

		for ( int i = 0; i < 8; i++)
		{
			int x = reiX + DX[i];
			int y = reiY + DY[i];
			
			while (board[x][y] == '.')
			{
				x += DX[i];
				y += DY[i];
			}
//printf("board[%i][%i]= %c\n", x, y, board[x][y]);
			if (board[x][y] == queen)
			{
				return true;
			}
			else if (i < 4 && board[x][y] == rook)
			{
				return true;
			}
			else if (i >= 4 && board[x][y] == bishop)
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int n = 1;

	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 16; j++)
			board[i][j] = 'z';

	
	while (!feof(stdin))
	{
		int reiPX = -1, reiPY = -1, reiWX = -1, reiWY = -1;
		bool bcheck = false, wcheck = false;
		bool vazio = true;
		char lixo;

		for (int i = 3; i < 11; i++)
		{
			for (int j = 3; j < 11; j++)
			{
				scanf("%c", &board[i][j]);
				if (board[i][j] == 'k') { reiPX = i; reiPY = j; }
				if (board[i][j] == 'K') { reiWX = i; reiWY = j; }

				if (board[i][j] != '.') vazio = false; 
			}
			scanf("%c", &lixo);
		}

		scanf("%c", &lixo);

		if (vazio) break;

		bcheck = isInCheck(reiPX, reiPY, 0);
		wcheck = isInCheck(reiWX, reiWY, 1);

		if (wcheck) printf("Game #%d: white king is in check.\n", n);
		else if (bcheck) printf("Game #%d: black king is in check.\n", n);
		else printf("Game #%d: no king is in check.\n", n);
		n++;	
	}
	//system("pause");
	return 0;
}

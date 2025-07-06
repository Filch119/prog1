import java.util.Scanner;

public class TicTacToe{
	public  static char[][] board = {{'1','2','3'},
					  				 {'4','5','6'},
					  				 {'7','8','9'}};
	public static int turn = 0;
	public static boolean winner=false;
	public static char symbol;
	public static int[] position;
	public static int move;

	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		System.out.println("This is a tic-tac-toe game. This game requires two players. Player 1 will be marked by 'X' and Player 2 will be marked by 'O'. whosoever first creates a 3-x line or 3-o line wins \n\n");

		do {
			dispBoard();
			System.out.println("Player " + ((turn%2)+1) + ", your turn.");
			System.out.println("Choose a position in the board");
			move = scan.nextInt();
			position = moveCoords(move);
			if (turn % 2 == 0){
				symbol = 'X';
			}
			else {
				symbol = 'O';
			}
			if (board[position[0]][position[1]] != 'X' && board[position[0]][position[1]] != 'O'){
				board[position[0]][position[1]] = symbol;
				turn++;
			}
			else 
				System.out.println("Error: Invalid position. Please choose a position not marked with 'X' or 'O'");
			//dispBoard();

			if (turn>=5){
				if (winCheck())
					break;
			}
		}
		while (turn<=9);

		if (winner){
			dispBoard();
			System.out.println("Player " + (((turn-1)%2)+1) + " wins!");
		}
		else
			System.out.println("The game was a draw!");
	}

	public static void dispBoard(){
		for (int i=0; i<board.length; i++){
			for (int j=0; j<board[i].length; j++){
				System.out.print(board[i][j] + " ");
			}
			System.out.print("\n");
		}
	}

	public static int[] moveCoords(int num){
		int[] coords = new int[2];

		//int[] coords = {(num-1)/3, (num-1) % 3}

		if (num<=3){
			coords[0] = 0;
			coords[1] = num-1;
		}
		else if (num<=6 && num>3){
			coords[0]=1;
			coords[1]=num - 4;
		}
		else if (num>=7){
			coords[0]=2;
			coords[1]=num - 7;
		}
		return coords;
	}

	public static boolean winCheck(){
		if (board[0][0] == symbol && board[0][1] == symbol && board[0][2]==symbol)
			winner = true;
		else if (board[1][0] == symbol && board[1][1] == symbol && board[1][2]==symbol)
			winner = true;
		else if (board[2][0] == symbol && board[2][1] == symbol && board[2][2]==symbol)	
			winner = true;
		else if (board[0][0] == symbol && board[1][0] == symbol && board[2][0]==symbol)	
			winner = true;
		else if (board[0][1] == symbol && board[1][1] == symbol && board[2][1]==symbol)
			winner = true;	
		else if (board[0][2] == symbol && board[1][2] == symbol && board[2][2]==symbol)	
			winner = true;
		else if (board[0][0] == symbol && board[1][1] == symbol && board[2][2]==symbol)	
			winner = true;
		else if (board[0][2] == symbol && board[1][1] == symbol && board[2][0]==symbol)	
			winner = true;
		else
			winner = false;
		return winner;
	}
}
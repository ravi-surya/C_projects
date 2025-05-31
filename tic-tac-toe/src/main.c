#include <stdio.h>
#include <stdbool.h>

#define row 3
#define column 3

void print_grid(char grid[row][column]);
bool check_win(char grid[row][column]);

int main(void)
{
    char grid[row][column] = {{'0', '1', '2'}, {'3', '4', '5'}, {'6', '7', '8'}};
    int a;
    char mark = 'O';
    int count_moves=0;
    print_grid(grid);
    while (true)
    {
        count_moves++;
      
        printf("enter your move(0-8):");
        scanf("%d", &a);
        if(a<0 || a>8)
        {
            printf("invalid move!!!\n");
            printf("Try again\n");
            count_moves--;
    
            continue;
        }
        if(grid[a / 3][a % 3] == 'X' || grid[a / 3][a % 3] =='O')
        {
            printf("already taken space!!!\n");
            printf("Try again\n");
            count_moves--;
            continue;
        }
        grid[a / 3][a % 3] = mark;
        print_grid(grid);
        
        if(check_win(grid))
        {
            printf("you win %c!!!!",mark);
            break;
        }
        if(count_moves==9)
        {
            printf("Its a draw!!1");
            break;
        }
         if (mark == 'O')
            {
                mark = 'X';
            }
            else
            {
                mark = 'O';
            }
        
    }
    return 0;
}

void print_grid(char grid[row][column])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c  ", grid[i][j]);
        }
        printf("\n");
    }
}

bool check_win(char grid[row][column])
{
    //checking rows
  for (int i = 0; i < 3; i++) {
        if ((grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) && 
            (grid[i][0] == 'X' || grid[i][0] == 'O') ) {
            return true; // Row match
        }
        if ((grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i])&&
        (grid[0][i] == 'X' || grid[0][i] == 'O')) {
            return true; // Column match
        }
    }

     // Check diagonals
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
        return true;
    }
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
        return true;
    
    }
    //if draw 
    return false;

}
 
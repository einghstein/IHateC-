#include <iostream>

/*
0 = empty = 
1 = block =X
2 = player=V
3 = box   =O
*/

bool game = true;
const int BOARD_X = 20;
const int BOARD_Y = 10;
int board[BOARD_Y][BOARD_X];
char input;
int charPosX = 1;
int charPosY = 1;

void draw(int board[BOARD_Y][BOARD_X]);

int main(){
    //init board and set all to 0 except cornets those are 1
    for (int y = 0; y < BOARD_Y; y++){
        for (int x = 0; x < BOARD_X; x++){
            if (y == 0 ){board[y][x] = 1;}
            else if ((y == BOARD_Y-1)){board[y][x] = 1;}
            else if (x == 0){board[y][x] = 1;}
            else if (x == BOARD_X-1){board[y][x] = 1;}
            else {board[y][x] = 0;}
        }
    }
    board[charPosY][charPosX] = 2;
    board[5][10] = 3;
    
    draw(board);
    while (game){
        std::cin >> input;
        if (input == 'e'){
            game = false;
        }
        else if (input == 'w'){
            if (board[charPosY-1][charPosX] == 1){
                printf("fuck you\n");
            }
            else{
                board[charPosY][charPosX] = 0;
                charPosY -= 1;
                board[charPosY][charPosX] = 2;
            }
        }      
        else if (input == 's'){
            if (board[charPosY+1][charPosX] == 1){
                printf("fuck you\n");
            }
            else{
                board[charPosY][charPosX] = 0;
                charPosY += 1;
                board[charPosY][charPosX] = 2;
            }
        }   
        else if (input == 'd'){
            if (board[charPosY][charPosX+1] == 1){
                printf("fuck you\n");
            }
            else{
                board[charPosY][charPosX] = 0;
                charPosX += 1;
                board[charPosY][charPosX] = 2;
            }
        }
        else if (input == 'a'){
            if (board[charPosY][charPosX-1] == 1){
                printf("fuck you\n");
            }
            else{
                board[charPosY][charPosX] = 0;
                charPosX -= 1;
                board[charPosY][charPosX] = 2;
            }
        }
        draw(board);
    }
    return 0;
}

void draw(int board[BOARD_Y][BOARD_X]) {
    for (int y = 0; y < BOARD_Y; y++){
        for (int x = 0; x < BOARD_X; x++){
            switch (board[y][x])
            {
            case 0:
                std::cout << " ";
                break;

            case 1:
                std::cout << "X";
                break;

            case 2:
                std::cout << "V";
                break;
            
            case 3:
                std::cout << "O";
                break;
            default:
                break;
            }
        }
        std::cout << "\n";
    }
}
#include <stdbool.h>
#include <stdio.h>
#define Ccon 97

// the TALMINATOR IS READY. 

bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol);
bool positionInBounds(int n, int row, int col);
void printBoard(char board[][26], int n);
void createBoard(char board[][26], int n);
void flipTiles(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol);
bool checkFullBoard(char board[][26], int n);
void checkWinner(char board[][26], int n);
bool IsValidMoves(char board[][26], int n, char colour);
bool checkFlukeWinWhite(char board[][26], int n);
bool checkFlukeWinBlack(char board[][26], int n);

int main(void)
{

    int dimBoard, row, col, deltaRow, deltaCol, temp, tempMax;
    char colour, oppColour, rowInput, colInput, board[26][26], compCol, rowMinW, colMinW, rowMinB, colMinB, newRowW, newColW, newRowB, newColB;

    printf("Enter the board dimension: ");
    scanf("%d", &dimBoard);
    printf("Computer plays (B/W): ");
    scanf(" %c", &compCol);

    createBoard(board, dimBoard);
    printBoard(board, dimBoard);

    float ScoreArrayAll[8][8] = 
      { { 900.01,  050.01, 450.01, 303.01, 303.02, 450.02,  050.03,  900.02 },
        { 050.02,  000.01, 070.01, 100.02, 100.03, 070.04,  000.02,  050.04 },
        { 450.03,  070.11, 400.01, 201.11, 201.12, 400.04,  070.12,  450.06 },
        { 303.05,  100.05, 201.01, 201.02, 201.03, 201.04,  100.08,  303.08 },
        { 303.06,  100.06, 201.05, 201.06, 201.07, 201.08,  100.07,  303.07 },
        { 450.04,  070.09, 400.02, 201.09, 201.10, 400.03,  070.10,  450.05 },
        { 050.05,  000.03, 070.13, 100.14, 100.15, 070.16,  000.04,  050.08 },
        { 900.03,  050.06, 450.06, 303.03, 303.04, 450.07,  050.07,  900.04 } };

    for(int k = 0; k < 500; k++) {

    if((board[7][7] == 'W') || (board[7][7] == 'B')) {
        ScoreArrayAll[7][7] = 080.60;
        ScoreArrayAll[7][6] = 080.90;
        ScoreArrayAll[6][7] = 080.97;
        ScoreArrayAll[7][5] = 080.62;
        ScoreArrayAll[5][7] = 080.63;
        ScoreArrayAll[5][5] = 080.64;
        ScoreArrayAll[6][6] = 080.69;}
    
    if((board[0][0] == 'W') || (board[0][0] == 'B')) {
        ScoreArrayAll[0][2] = 080.65;
        ScoreArrayAll[2][0] = 080.66;
        ScoreArrayAll[2][2] = 080.67;
        ScoreArrayAll[0][0] = 080.68;
        ScoreArrayAll[1][1] = 080.70;
        ScoreArrayAll[0][1] = 080.93;
        ScoreArrayAll[1][0] = 080.92;}
    
    if((board[0][7] == 'W') || (board[0][7] == 'B')) {
        ScoreArrayAll[2][5] = 080.75;
        ScoreArrayAll[2][7] = 080.74;
        ScoreArrayAll[0][5] = 080.73;
        ScoreArrayAll[0][7] = 080.72;
        ScoreArrayAll[0][6] = 080.23;
        ScoreArrayAll[1][7] = 080.22;        
        ScoreArrayAll[1][6] = 080.21;}
    
    if((board[7][0] == 'W') || (board[7][0] == 'B')) {
        ScoreArrayAll[7][0] = 080.76;
        ScoreArrayAll[7][2] = 080.27;
        ScoreArrayAll[1][7] = 080.28;
        ScoreArrayAll[6][0] = 080.20;        
        ScoreArrayAll[5][0] = 080.17;
        ScoreArrayAll[5][2] = 080.18;
        ScoreArrayAll[6][1] = 080.78;}

    if(board[0][0] == 'U' && board[1][1] != 'U' && board[0][2] != 'U' && board[2][0] == 'U') {
        ScoreArrayAll[2][0] =  025.01;}
        
    if(board[0][0] == 'U' && board[1][1] != 'U' && board[2][0] != 'U' && board[0][2] == 'U') {
        ScoreArrayAll[0][2] =  025.02;}
        
    if(board[0][7] == 'U' && board[1][6] != 'U' && board[0][5] != 'U' && board[2][7] == 'U') {
        ScoreArrayAll[2][7] =  025.03;}
        
    if(board[0][7] == 'U' && board[1][6] != 'U' && board[2][7] != 'U' && board[0][5] == 'U') {
        ScoreArrayAll[0][5] =  025.04;}
        
    if(board[7][7] == 'U' && board[6][6] != 'U' && board[7][5] != 'U' && board[5][7] == 'U') {
        ScoreArrayAll[5][7] =  025.05;}
        
    if(board[7][7] == 'U' && board[6][6] != 'U' && board[5][7] != 'U' && board[7][5] == 'U') {
        ScoreArrayAll[7][5] =  025.06;}
        
    if(board[7][0] == 'U' && board[6][1] != 'U' && board[5][0] != 'U' && board[7][2] == 'U') {
        ScoreArrayAll[7][2] =  025.07;}
        
    if(board[7][0] == 'U' && board[6][1] != 'U' && board[7][2] != 'U' && board[5][0] == 'U') {
        ScoreArrayAll[5][0] =  025.08;}

        if(checkFlukeWinWhite(board, dimBoard)) {
            printf("B player wins. \n");
            break;}
            
        if(checkFlukeWinBlack(board, dimBoard)) {
            printf("W player wins. \n");
            break;}
            
        if(checkFullBoard(board, dimBoard)) {
            checkWinner(board, dimBoard);
            break;}

        if(k % 2 == 0) {
            colour = 'W';
            int flag = 1, rowMinB, colMinB;
            float temp = 0, tempMax = 0.00;
            for(row = 0; row < dimBoard; row++) {
                for(col = 0; col < dimBoard; col++) {
                    for(deltaRow = -1; deltaRow < 2; deltaRow++) {
                        for(deltaCol = -1; deltaCol < 2; deltaCol++) {
                            if(checkLegalInDirection(board, dimBoard, row, col, colour, deltaRow, deltaCol) &&
                                positionInBounds(dimBoard, row + (deltaRow * flag), col + (deltaCol * flag))) {
                                flag = 1;
                                while((board[row + (deltaRow * flag)][col + (deltaCol * flag)] != 'B')) {
                                    flag++;
                                }
                                temp = temp + (flag - 1) + ScoreArrayAll[row][col];}}}
                                
                    if((checkLegalInDirection(board, dimBoard, row, col, colour, 1, 1) ||
                           checkLegalInDirection(board, dimBoard, row, col, colour, 1, 0) ||
                           checkLegalInDirection(board, dimBoard, row, col, colour, 1, -1) ||
                           checkLegalInDirection(board, dimBoard, row, col, colour, 0, 1) ||
                           checkLegalInDirection(board, dimBoard, row, col, colour, 0, -1) ||
                           checkLegalInDirection(board, dimBoard, row, col, colour, -1, 1) ||
                           checkLegalInDirection(board, dimBoard, row, col, colour, -1, 0) ||
                           checkLegalInDirection(board, dimBoard, row, col, colour, -1, -1))) {
                        if(temp > tempMax) {
                            tempMax = temp;
                            colMinB = col;
                            rowMinB = row;}
                            
                        temp = 0.00;}}}
            newColB = colMinB;
            newRowB = rowMinB;
            oppColour = 'W';
            colour = 'B';
        } else if((k % 2 == 1)) {

            colour = 'B';
            int flag = 1, rowMinW, colMinW;
            float temp = 0.00, tempMax = 0.00;
            for(row = 0; row < dimBoard; row++) {
                for(col = 0; col < dimBoard; col++) {
                    for(deltaRow = -1; deltaRow < 2; deltaRow++) {
                        for(deltaCol = -1; deltaCol < 2; deltaCol++) {
                            if(checkLegalInDirection(board, dimBoard, row, col, colour, deltaRow, deltaCol) &&
                                positionInBounds(dimBoard, row + (deltaRow * flag), col + (deltaCol * flag))) {
                                flag = 1;
                                while((board[row + (deltaRow * flag)][col + (deltaCol * flag)] != 'W')) {
                                    flag++;}
                                temp = temp + (flag - 1) + ScoreArrayAll[row][col];}}}
                                
                    if((checkLegalInDirection(board, dimBoard, row, col, colour, 1, 1) ||
                           checkLegalInDirection(board, dimBoard, row, col, colour, 1, 0) ||
                           checkLegalInDirection(board, dimBoard, row, col, colour, 1, -1) ||
                           checkLegalInDirection(board, dimBoard, row, col, colour, 0, 1) ||
                           checkLegalInDirection(board, dimBoard, row, col, colour, 0, -1) ||
                           checkLegalInDirection(board, dimBoard, row, col, colour, -1, 1) ||
                           checkLegalInDirection(board, dimBoard, row, col, colour, -1, 0) ||
                           checkLegalInDirection(board, dimBoard, row, col, colour, -1, -1))) {
                        if(temp > tempMax) {
                            tempMax = temp;
                            rowMinW = row;
                            colMinW = col;}
                        temp = 0.00;}}}

            oppColour = 'B';
            colour = 'W';
            newColW = colMinW;
            newRowW = rowMinW;}

        if(IsValidMoves(board, dimBoard, oppColour) && IsValidMoves(board, dimBoard, colour)) {
            printf("No player has a valid move. \n");
            checkWinner(board, dimBoard);
            break;}

        if(IsValidMoves(board, dimBoard, oppColour)) {
            printf("%c player has no valid move. \n", colour);
            continue;}

        if(k % 2 == 0 && compCol == 'B') {
            printf("Computer places B at %c%c. \n", ((char)newRowB + Ccon), ((char)newColB + Ccon));
            rowInput = ((char)newRowB + Ccon);
            colInput = ((char)newColB + Ccon);
        } else if(k % 2 == 0 && compCol == 'W') {
            printf("Enter move for colour B (RowCol): ");
            scanf(" %c %c", &rowInput, &colInput);}

        if(k % 2 == 1 && compCol == 'W') {
            printf("Computer places W at %c%c. \n", ((char)newRowW + Ccon), ((char)newColW + Ccon));
            rowInput = ((char)newRowW + Ccon);
            colInput = ((char)newColW + Ccon);
        } else if(k % 2 == 1 && compCol == 'B') {
            printf("Enter move for colour W (RowCol): ");
            scanf(" %c %c", &rowInput, &colInput);}

        bool IsValid = false;
        int colint = (int)colInput - Ccon;
        int rowint = (int)rowInput - Ccon;
        for(int k = 0; k < 500; k++) {

            if(checkLegalInDirection(board, dimBoard, rowint, colint, oppColour, 1, 1)) {
                IsValid = true;
                flipTiles(board, dimBoard, rowint, colint, colour, 1, 1);}
            if(checkLegalInDirection(board, dimBoard, rowint, colint, oppColour, 1, 0)) {
                IsValid = true;
                flipTiles(board, dimBoard, rowint, colint, colour, 1, 0);}
            if(checkLegalInDirection(board, dimBoard, rowint, colint, oppColour, 1, -1)) {
                IsValid = true;
                flipTiles(board, dimBoard, rowint, colint, colour, 1, -1);}
            if(checkLegalInDirection(board, dimBoard, rowint, colint, oppColour, 0, -1)) {
                IsValid = true;
                flipTiles(board, dimBoard, rowint, colint, colour, 0, -1);}
            if(checkLegalInDirection(board, dimBoard, rowint, colint, oppColour, 0, 1)) {
                IsValid = true;
                flipTiles(board, dimBoard, rowint, colint, colour, 0, 1);}
            if(checkLegalInDirection(board, dimBoard, rowint, colint, oppColour, -1, 1)) {
                IsValid = true;
                flipTiles(board, dimBoard, rowint, colint, colour, -1, 1);}
            if(checkLegalInDirection(board, dimBoard, rowint, colint, oppColour, -1, 0)) {
                IsValid = true;
                flipTiles(board, dimBoard, rowint, colint, colour, -1, 0);}
            if(checkLegalInDirection(board, dimBoard, rowint, colint, oppColour, -1, -1)) {
                IsValid = true;
                flipTiles(board, dimBoard, rowint, colint, colour, -1, -1);}}
                
        if(IsValid == true) {
            board[(int)rowInput - Ccon][(int)colInput - Ccon] = colour;
            printBoard(board, dimBoard);}

        if(IsValid == false) {
            if(k % 2 == 0) {
                printf("Invalid Move. \n");
                printf("W player wins. \n");
                break;
            } else {
                printf("Invalid Move. \n");
                printf("B player wins. \n");
                break;}}}
    return 0;}

void flipTiles(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol){
    int flag = 1;
    while(((board[row + (deltaRow * flag)][col + (deltaCol * flag)] != colour))) {
        board[row + (deltaRow * flag)][col + (deltaCol * flag)] = colour;
        flag++;}
    return;}

bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol){
    bool IsValid = false;
    char oppColour;
    int flag = 1;
    if(colour == 'W') {
        oppColour = 'B';
    } else {
        oppColour = 'W';}
        
    while((board[row][col] == 'U') && (board[row + (deltaRow * flag)][col + (deltaCol * flag)] == colour) &&
        positionInBounds(n, row + (deltaRow * flag), col + (deltaCol * flag)) && (IsValid != true)) {
        flag++;
        if((board[row + deltaRow * flag][col + deltaCol * flag] == oppColour) &&
            positionInBounds(n, row + (deltaRow * flag), col + (deltaCol * flag))) {
            IsValid = true;}}
            
    if(IsValid == true) {
        return true;
    } else {
        return false;}}
        
bool IsValidMoves(char board[][26], int n, char colour){
    for(int row = 0; row <= n; row++) {
        for(int col = 0; col <= n; col++) {
            for(int deltaRow = -1; deltaRow < 2; deltaRow++) {
                for(int deltaCol = -1; deltaCol < 2; deltaCol++) {
                    if(checkLegalInDirection(board, n, row, col, colour, deltaRow, deltaCol)) {
                        return false;}}}}}
    return true;}

bool checkFullBoard(char board[][26], int n){
    
    bool IsValid = true;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(board[i][j] == 'U') {
                IsValid = false;}}}
    if(IsValid == true) {
        return true;
    } else {
        return false;}}

void checkWinner(char board[][26], int n){
    int countBlack = 0, countWhite = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(board[i][j] == 'B') {
                countBlack++;
            } else if(board[i][j] == 'W') {
                countWhite++;}}}
                
    if(countBlack < countWhite) {
        printf("W player wins. \n");
    } else if(countBlack > countWhite) {
        printf("B player wins. \n");
    } else {
        printf("Draw! \n");}}

bool checkFlukeWinWhite(char board[][26], int n){
    bool IsValid = true;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(board[i][j] == 'W') {
                IsValid = false;}}}
                
    if(IsValid == true) {
        return true;
    } else {
        return false;}}

bool checkFlukeWinBlack(char board[][26], int n){
    bool IsValid = true;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(board[i][j] == 'B') {
                IsValid = false;}}}
                
    if(IsValid == true) {
        return true;
    } else {
        return false;}}

void printBoard(char board[][26], int n){
    printf("  ");
    for(int i = 0; i < n; i++) {
        printf("%c", (char)Ccon + i);}
    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("%c ", (char)Ccon + i);
        for(int j = 0; j < n; j++) {
            printf("%c", board[i][j]);}
            
        printf("\n");}
    return;}

void createBoard(char board[][26], int n){
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board[i][j] = 'U';}}
            
    board[n / 2 - 1][n / 2 - 1] = 'W';
    board[n / 2 - 1][n / 2] = 'B';
    board[n / 2][n / 2 - 1] = 'B';
    board[n / 2][n / 2] = 'W';
    return;}

bool positionInBounds(int n, int row, int col){
    if((row >= 0) && (row <= n) && (col >= 0) && (col <= n)) {
        return true;
    } else {
        return false;}}
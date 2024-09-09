#include "../lib/tictactoe.h"

char gameGrid[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '},
};
unsigned playerCount = 0;
char gameSymbols[2] = {'O','X'};
char playerSymbol = '\0';
char computerSymbol = '\0';
char playerInput[2] = "";
unsigned char position[2] = {0, 0};
char gameWinner[9] = "";
bool isGameOver = false;

void displayTempGrid() {
    char tempGrid[3][3][3] = {
        {"A1", "A2", "A3"},
        {"B1", "B2", "B3"},
        {"C1", "C2", "C3"}
    };
    printf("############\n");
    for (int i = 0; i < 3; ++i) {
        printf("# ");
        for (int j = 0; j < 3; ++j) {
            printf("%s", tempGrid[i][j]);
            if (j != 2) printf(" ");
        }
        printf(" #\n");
    }
    printf("############\n");
    printf("____________\n");
}

void displayGrid() {
    if (playerCount == 0) {
        displayTempGrid();
    } else {
        printf("#########\n");
        for (int i = 0; i < 3; ++i) {
            printf("# ");
            for (int j = 0; j < 3; ++j) {
                printf("%c", gameGrid[i][j]);
                if (j != 2) printf(" ");
            }
            printf(" #\n");
        }
        printf("#########\n");
        printf("_________\n");
    }
}

void selectPlayerSymbol() {
    do {
        printf("Select symbol (O or X) : ");
        scanf(" %c",&playerSymbol);
        while (getchar() != '\n');  // Clear input buffer
    } while (playerSymbol != gameSymbols[0] && playerSymbol != gameSymbols[1]);

    if (playerSymbol == gameSymbols[0]) computerSymbol = gameSymbols[1];
    else computerSymbol = gameSymbols[0];

    printf("Player symbol   : '%c'\n", playerSymbol);
    printf("Computer symbol : '%c'\n", computerSymbol);
    printf("______________________\n");
}

void playerTurn() {
    selectPlayerPosition();
    if (gameGrid[position[0]][position[1]] == ' ') {
        gameGrid[position[0]][position[1]] = playerSymbol;
        ++playerCount;
    }
    else {
        printf("Position already picked, select another one.\n");
        playerTurn();
    }

}

void selectPlayerPosition() {
    char validInputs[9][3] = {"A1", "A2", "A3", "B1", "B2", "B3", "C1", "C2", "C3"};
    bool isValid = false;

    // Prompt the user until they enter valid position
    do {
        printf("Select position (e.g A1) : ");
        scanf(" %s",playerInput);
        while (getchar() != '\n'); // Clear input buffer
        isValid = false;

        for (int i = 0; i < sizeof(validInputs)/sizeof(validInputs[0]); ++i) {
            if (strcmp(playerInput, validInputs[i]) == 0) {
                isValid = true;
                position[0] = validInputs[i][0] - 'A';  // Map 'A' -> 0, 'B' -> 1, 'C' -> 2
                position[1] = validInputs[i][1] - '1';  // Map '1' -> 0, '2' -> 1, '3' -> 2
                break;
            }
        }

        if(!isValid) printf ("Invalid position. Please select a valid position (e.g A1).\n");

    } while(!isValid);
}

void computerTurn() {
    unsigned char randNum = (unsigned char) (rand() % 9 + 1);
    mapComputerInput(randNum);

    if (gameGrid[position[0]][position[1]] == ' ') gameGrid[position[0]][position[1]] = computerSymbol;
    else computerTurn();
}

void mapComputerInput(unsigned char input) {
    switch (input) {
        case 1 : position[0] = 0; position[1] = 0; break;
        case 2 : position[0] = 0; position[1] = 1; break;
        case 3 : position[0] = 0; position[1] = 2; break;
        case 4 : position[0] = 1; position[1] = 0; break;
        case 5 : position[0] = 1; position[1] = 1; break;
        case 6 : position[0] = 1; position[1] = 2; break;
        case 7 : position[0] = 2; position[1] = 0; break;
        case 8 : position[0] = 2; position[1] = 1; break;
        default : position[0] = 2; position[1] = 2;
    }
}

void checkWinner() {
    // Rows
    for (int i = 0; i < 3; ++i) {
        if (gameGrid[i][0] != ' ' && gameGrid[i][0] == gameGrid[i][1] && gameGrid[i][1] == gameGrid[i][2]) {
            isGameOver = true;
            if (gameGrid[i][0] == computerSymbol) strcpy(gameWinner, "Computer"); else strcpy(gameWinner, "Player");
            return;
        }
    }

    // Columns
    for (int i = 0; i < 3; ++i) {
        if (gameGrid[0][i] != ' ' && gameGrid[0][i] == gameGrid[1][i] && gameGrid[1][i] == gameGrid[2][i]) {
            isGameOver = true;
            if (gameGrid[0][i] == computerSymbol) strcpy(gameWinner, "Computer"); else strcpy(gameWinner, "Player");
            return;
        }
    }

    // Diagonals
    if (gameGrid[0][0] != ' ' && gameGrid[0][0] == gameGrid[1][1] && gameGrid[1][1] == gameGrid[2][2]) {
        isGameOver = true;
        if (gameGrid[0][0] == computerSymbol) strcpy(gameWinner, "Computer"); else strcpy(gameWinner, "Player");
        return;
    }

    if (gameGrid[0][2] != ' ' && gameGrid[0][2] == gameGrid[1][1] && gameGrid[1][1] == gameGrid[2][0]) {
        isGameOver = true;
        if (gameGrid[0][2] == computerSymbol) strcpy(gameWinner, "Computer"); else strcpy(gameWinner, "Player");
        return;
    }

    // Draw
    if (strcmp(gameWinner, "") == 0 && playerCount == 5) {
        isGameOver = true;
        strcpy(gameWinner, "None");
        return;
    }
}
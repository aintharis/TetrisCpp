#ifndef BOARD_H

#define BOARD_H

#include <GL/glut.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;
const int BLOCK_SIZE = 50;

const int WINDOW_WIDTH = BOARD_WIDTH * BLOCK_SIZE;
const int WINDOW_HEIGHT = BOARD_HEIGHT * BLOCK_SIZE;

int pieceRow = 0;
int pieceCol = 3;

int board[BOARD_HEIGHT][BOARD_WIDTH];

void initBoard();
void drawBlock(int col, int row, float r, float g, float b);
void drawBoard();

void initBoard()
{
    for (int row = 0; row < BOARD_HEIGHT; row++)
    {
        for (int col = 0; col < BOARD_WIDTH; col++)
        {
            board[row][col] = 0;
        }
    }
}

void drawBlock(int col, int row, float r, float g, float b)
{
    int px = col * BLOCK_SIZE;
    int py = row * BLOCK_SIZE;

    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2i(px, py);
    glVertex2i(px + BLOCK_SIZE, py);
    glVertex2i(px + BLOCK_SIZE, py + BLOCK_SIZE);
    glVertex2i(px, py + BLOCK_SIZE);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2i(px, py);
    glVertex2i(px + BLOCK_SIZE, py);
    glVertex2i(px + BLOCK_SIZE, py + BLOCK_SIZE);
    glVertex2i(px, py + BLOCK_SIZE);
    glEnd();
}

int currentShape = 0;
int rotation = 0;
int score = 0;
bool GameOver = false;
bool canSpawnPiece();
void newPiece()
{
    currentShape = rand() % 4;
    rotation = 0;
    pieceRow = 0;
    pieceCol = 3;

    if (!canSpawnPiece())
    {
        GameOver = true;
        cout << " GAME OVER! " << endl;
    }
}
void rotatePiece()
{
    rotation++;
    if (rotation >= 4)
    {
        rotation = 0;
    }
}

bool validRotation(int row, int col)
{
    if (row < 0 || row >= BOARD_HEIGHT || col < 0 || col >= BOARD_WIDTH)
    {
        return false;
    }
    if (board[row][col] != 0)
    {
        return false;
    }
    return true;
}
bool canRotate()
{
    int nextRotation = rotation + 1;

    if (nextRotation >= 4)
    {
        nextRotation = 0;
    }

    // I SHAPE
    if (currentShape == 0)
    {
        if (nextRotation == 0 || nextRotation == 2)
        {
            return validRotation(pieceRow, pieceCol) &&
                   validRotation(pieceRow, pieceCol + 1) &&
                   validRotation(pieceRow, pieceCol + 2) &&
                   validRotation(pieceRow, pieceCol + 3);
        }
        else
        {
            return validRotation(pieceRow, pieceCol) &&
                   validRotation(pieceRow + 1, pieceCol) &&
                   validRotation(pieceRow + 2, pieceCol) &&
                   validRotation(pieceRow + 3, pieceCol);
        }
    }

    // O SHAPE
    else if (currentShape == 1)
    {
        return true;
    }

    // T SHAPE
    else if (currentShape == 2)
    {
        if (nextRotation == 0)
        {
            return validRotation(pieceRow, pieceCol + 1) &&
                   validRotation(pieceRow + 1, pieceCol) &&
                   validRotation(pieceRow + 1, pieceCol + 1) &&
                   validRotation(pieceRow + 1, pieceCol + 2);
        }

        else if (nextRotation == 1)
        {
            return validRotation(pieceRow, pieceCol) &&
                   validRotation(pieceRow + 1, pieceCol) &&
                   validRotation(pieceRow + 1, pieceCol + 1) &&
                   validRotation(pieceRow + 2, pieceCol);
        }

        else if (nextRotation == 2)
        {
            return validRotation(pieceRow, pieceCol) &&
                   validRotation(pieceRow, pieceCol + 1) &&
                   validRotation(pieceRow, pieceCol + 2) &&
                   validRotation(pieceRow + 1, pieceCol + 1);
        }

        else
        {
            return validRotation(pieceRow, pieceCol + 1) &&
                   validRotation(pieceRow + 1, pieceCol) &&
                   validRotation(pieceRow + 1, pieceCol + 1) &&
                   validRotation(pieceRow + 2, pieceCol + 1);
        }
    }

    // L SHAPE
    else if (currentShape == 3)
    {
        if (nextRotation == 0)
        {
            return validRotation(pieceRow, pieceCol) &&
                   validRotation(pieceRow, pieceCol + 1) &&
                   validRotation(pieceRow, pieceCol + 2) &&
                   validRotation(pieceRow + 1, pieceCol);
        }

        else if (nextRotation == 1)
        {
            return validRotation(pieceRow, pieceCol) &&
                   validRotation(pieceRow + 1, pieceCol) &&
                   validRotation(pieceRow + 2, pieceCol) &&
                   validRotation(pieceRow + 2, pieceCol + 1);
        }

        else if (nextRotation == 2)
        {
            return validRotation(pieceRow, pieceCol + 2) &&
                   validRotation(pieceRow + 1, pieceCol) &&
                   validRotation(pieceRow + 1, pieceCol + 1) &&
                   validRotation(pieceRow + 1, pieceCol + 2);
        }

        else
        {
            return validRotation(pieceRow, pieceCol) &&
                   validRotation(pieceRow, pieceCol + 1) &&
                   validRotation(pieceRow + 1, pieceCol + 1) &&
                   validRotation(pieceRow + 2, pieceCol + 1);
        }
    }

    return false;
}

void drawIShape()
{

    if (rotation == 0 || rotation == 2)
    {

        drawBlock(pieceCol, pieceRow, 0.0f, 1.0f, 1.0f);
        drawBlock(pieceCol + 1, pieceRow, 0.0f, 1.0f, 1.0f);
        drawBlock(pieceCol + 2, pieceRow, 0.0f, 1.0f, 1.0f);
        drawBlock(pieceCol + 3, pieceRow, 0.0f, 1.0f, 1.0f);
    }
    else
    {

        drawBlock(pieceCol, pieceRow, 0.0f, 1.0f, 1.0f);
        drawBlock(pieceCol, pieceRow + 1, 0.0f, 1.0f, 1.0f);
        drawBlock(pieceCol, pieceRow + 2, 0.0f, 1.0f, 1.0f);
        drawBlock(pieceCol, pieceRow + 3, 0.0f, 1.0f, 1.0f);
    }
}

void drawOShape()
{
    drawBlock(pieceCol, pieceRow, 1.0f, 1.0f, 0.0f);
    drawBlock(pieceCol + 1, pieceRow, 1.0f, 1.0f, 0.0f);
    drawBlock(pieceCol, pieceRow + 1, 1.0f, 1.0f, 0.0f);
    drawBlock(pieceCol + 1, pieceRow + 1, 1.0f, 1.0f, 0.0f);
}

void drawTShape()
{
    if (rotation == 0)
    {
        // T
        drawBlock(pieceCol + 1, pieceRow, 1.0f, 0.0f, 0.0f);
        drawBlock(pieceCol, pieceRow + 1, 1.0f, 0.0f, 0.0f);
        drawBlock(pieceCol + 1, pieceRow + 1, 1.0f, 0.0f, 0.0f);
        drawBlock(pieceCol + 2, pieceRow + 1, 1.0f, 0.0f, 0.0f);
    }
    else if (rotation == 1)
    {

        drawBlock(pieceCol, pieceRow, 1.0f, 0.0f, 0.0f);
        drawBlock(pieceCol, pieceRow + 1, 1.0f, 0.0f, 0.0f);
        drawBlock(pieceCol + 1, pieceRow + 1, 1.0f, 0.0f, 0.0f);
        drawBlock(pieceCol, pieceRow + 2, 1.0f, 0.0f, 0.0f);
    }
    else if (rotation == 2)
    {

        drawBlock(pieceCol, pieceRow, 1.0f, 0.0f, 0.0f);
        drawBlock(pieceCol + 1, pieceRow, 1.0f, 0.0f, 0.0f);
        drawBlock(pieceCol + 2, pieceRow, 1.0f, 0.0f, 0.0f);
        drawBlock(pieceCol + 1, pieceRow + 1, 1.0f, 0.0f, 0.0f);
    }
    else if (rotation == 3)
    {

        drawBlock(pieceCol + 1, pieceRow, 1.0f, 0.0f, 0.0f);
        drawBlock(pieceCol, pieceRow + 1, 1.0f, 0.0f, 0.0f);
        drawBlock(pieceCol + 1, pieceRow + 1, 1.0f, 0.0f, 0.0f);
        drawBlock(pieceCol + 1, pieceRow + 2, 1.0f, 0.0f, 0.0f);
    }
}

void drawLShape()
{

    if (rotation == 0)
    {
        drawBlock(pieceCol, pieceRow, 0.2f, 0.6f, 0.1f);
        drawBlock(pieceCol + 1, pieceRow, 0.2f, 0.6f, 0.1f);
        drawBlock(pieceCol + 2, pieceRow, 0.2f, 0.6f, 0.1f);
        drawBlock(pieceCol, pieceRow + 1, 0.2f, 0.6f, 0.1f);
    }
    else if (rotation == 1)
    {
        drawBlock(pieceCol, pieceRow, 0.2f, 0.6f, 0.1f);
        drawBlock(pieceCol, pieceRow + 1, 0.2f, 0.6f, 0.1f);
        drawBlock(pieceCol, pieceRow + 2, 0.2f, 0.6f, 0.1f);
        drawBlock(pieceCol + 1, pieceRow + 2, 0.2f, 0.6f, 0.1f);
    }
    else if (rotation == 2)
    {

        drawBlock(pieceCol, pieceRow + 1, 0.2f, 0.6f, 0.1f);
        drawBlock(pieceCol + 1, pieceRow + 1, 0.2f, 0.6f, 0.1f);
        drawBlock(pieceCol + 2, pieceRow + 1, 0.2f, 0.6f, 0.1f);
        drawBlock(pieceCol + 2, pieceRow, 0.2f, 0.6f, 0.1f);
    }
    else if (rotation == 3)
    {

        drawBlock(pieceCol, pieceRow, 0.2f, 0.6f, 0.1f);
        drawBlock(pieceCol + 1, pieceRow, 0.2f, 0.6f, 0.1f);
        drawBlock(pieceCol + 1, pieceRow + 1, 0.2f, 0.6f, 0.1f);
        drawBlock(pieceCol + 1, pieceRow + 2, 0.2f, 0.6f, 0.1f);
    }
}
bool canMoveDown()
{
    if (currentShape == 0) // I
    {
        if (rotation == 0 || rotation == 2)
        {
            if (pieceRow + 1 >= BOARD_HEIGHT)
                return false;

            for (int i = 0; i < 4; i++)
            {
                if (board[pieceRow + 1][pieceCol + i] != 0)
                    return false;
            }
        }
        else
        {
            if (pieceRow + 4 >= BOARD_HEIGHT)
                return false;

            if (board[pieceRow + 4][pieceCol] != 0)
                return false;
        }
    }

    else if (currentShape == 1) // O
    {
        if (pieceRow + 2 >= BOARD_HEIGHT)
            return false;

        if (board[pieceRow + 2][pieceCol] != 0)
            return false;

        if (board[pieceRow + 2][pieceCol + 1] != 0)
            return false;
    }

    else if (currentShape == 2) // T
    {
        if (rotation == 0)
        {
            if (pieceRow + 2 >= BOARD_HEIGHT)
                return false;

            if (board[pieceRow + 2][pieceCol] != 0 ||
                board[pieceRow + 2][pieceCol + 1] != 0 ||
                board[pieceRow + 2][pieceCol + 2] != 0)
                return false;
        }

        else if (rotation == 1)
        {
            if (pieceRow + 3 >= BOARD_HEIGHT)
                return false;

            if (board[pieceRow + 3][pieceCol] != 0)
                return false;
        }

        else if (rotation == 2)
        {
            if (pieceRow + 2 >= BOARD_HEIGHT)
                return false;

            if (board[pieceRow + 2][pieceCol + 1] != 0)
                return false;
        }

        else if (rotation == 3)
        {
            if (pieceRow + 3 >= BOARD_HEIGHT)
                return false;

            if (board[pieceRow + 3][pieceCol + 1] != 0)
                return false;
        }
    }

    else if (currentShape == 3) // L
    {
        if (rotation == 0)
        {
            if (pieceRow + 2 >= BOARD_HEIGHT)
                return false;

            if (board[pieceRow + 2][pieceCol] != 0)
                return false;
        }

        else if (rotation == 1)
        {
            if (pieceRow + 3 >= BOARD_HEIGHT)
                return false;

            if (board[pieceRow + 3][pieceCol] != 0 ||
                board[pieceRow + 3][pieceCol + 1] != 0)
                return false;
        }

        else if (rotation == 2)
        {
            if (pieceRow + 2 >= BOARD_HEIGHT)
                return false;

            if (board[pieceRow + 2][pieceCol] != 0 ||
                board[pieceRow + 2][pieceCol + 1] != 0 ||
                board[pieceRow + 2][pieceCol + 2] != 0)
                return false;
        }

        else if (rotation == 3)
        {
            if (pieceRow + 3 >= BOARD_HEIGHT)
                return false;

            if (board[pieceRow + 3][pieceCol + 1] != 0)
                return false;
        }
    }

    return true;
}

bool canMoveleft()
{
    if (currentShape == 0) // I
    {
        if (pieceCol <= 0)
            return false;

        if (rotation == 0 || rotation == 2)
        {
            if (board[pieceRow][pieceCol - 1] != 0)
                return false;
        }
        else
        {
            if (board[pieceRow][pieceCol - 1] != 0 ||
                board[pieceRow + 1][pieceCol - 1] != 0 ||
                board[pieceRow + 2][pieceCol - 1] != 0 ||
                board[pieceRow + 3][pieceCol - 1] != 0)
                return false;
        }
    }

    else if (currentShape == 1) // O
    {
        if (pieceCol <= 0)
            return false;

        if (board[pieceRow][pieceCol - 1] != 0 ||
            board[pieceRow + 1][pieceCol - 1] != 0)
            return false;
    }

    else if (currentShape == 2) // T
    {
        if (pieceCol <= 0)
            return false;

        if (rotation == 0)
        {
            if (board[pieceRow + 1][pieceCol - 1] != 0)
                return false;
        }

        else if (rotation == 1)
        {
            if (board[pieceRow][pieceCol - 1] != 0 ||
                board[pieceRow + 1][pieceCol - 1] != 0 ||
                board[pieceRow + 2][pieceCol - 1] != 0)
                return false;
        }

        else if (rotation == 2)
        {
            if (board[pieceRow][pieceCol - 1] != 0)
                return false;
        }

        else if (rotation == 3)
        {
            if (board[pieceRow + 1][pieceCol - 1] != 0)
                return false;
        }
    }

    else if (currentShape == 3) // L
    {
        if (pieceCol <= 0)
            return false;

        if (rotation == 0)
        {
            if (board[pieceRow][pieceCol - 1] != 0 ||
                board[pieceRow + 1][pieceCol - 1] != 0)
                return false;
        }

        else if (rotation == 1)
        {
            if (board[pieceRow][pieceCol - 1] != 0 ||
                board[pieceRow + 1][pieceCol - 1] != 0 ||
                board[pieceRow + 2][pieceCol - 1] != 0)
                return false;
        }

        else if (rotation == 2)
        {
            if (board[pieceRow + 1][pieceCol - 1] != 0)
                return false;
        }

        else if (rotation == 3)
        {
            if (board[pieceRow][pieceCol - 1] != 0)
                return false;
        }
    }

    return true;
}
bool canMoveRight()
{
    if (currentShape == 0) // I
    {
        if (rotation == 0 || rotation == 2)
        {
            if (pieceCol + 4 >= BOARD_WIDTH)
                return false;

            if (board[pieceRow][pieceCol + 4] != 0)
                return false;
        }
        else
        {
            if (pieceCol + 1 >= BOARD_WIDTH)
                return false;

            if (board[pieceRow][pieceCol + 1] != 0 ||
                board[pieceRow + 1][pieceCol + 1] != 0 ||
                board[pieceRow + 2][pieceCol + 1] != 0 ||
                board[pieceRow + 3][pieceCol + 1] != 0)
                return false;
        }
    }

    else if (currentShape == 1) // O
    {
        if (pieceCol + 2 >= BOARD_WIDTH)
            return false;

        if (board[pieceRow][pieceCol + 2] != 0 ||
            board[pieceRow + 1][pieceCol + 2] != 0)
            return false;
    }

    else if (currentShape == 2) // T
    {
        if (rotation == 0)
        {
            if (pieceCol + 3 >= BOARD_WIDTH)
                return false;

            if (board[pieceRow + 1][pieceCol + 3] != 0)
                return false;
        }

        else if (rotation == 1)
        {
            if (pieceCol + 2 >= BOARD_WIDTH)
                return false;

            if (board[pieceRow][pieceCol + 2] != 0 ||
                board[pieceRow + 1][pieceCol + 2] != 0 ||
                board[pieceRow + 2][pieceCol + 2] != 0)
                return false;
        }

        else if (rotation == 2)
        {
            if (pieceCol + 3 >= BOARD_WIDTH)
                return false;

            if (board[pieceRow][pieceCol + 3] != 0)
                return false;
        }

        else if (rotation == 3)
        {
            if (pieceCol + 2 >= BOARD_WIDTH)
                return false;

            if (board[pieceRow][pieceCol + 2] != 0 ||
                board[pieceRow + 1][pieceCol + 2] != 0 ||
                board[pieceRow + 2][pieceCol + 2] != 0)
                return false;
        }
    }

    else if (currentShape == 3) // L
    {
        if (rotation == 0)
        {
            if (pieceCol + 3 >= BOARD_WIDTH)
                return false;

            if (board[pieceRow][pieceCol + 3] != 0)
                return false;
        }

        else if (rotation == 1)
        {
            if (pieceCol + 2 >= BOARD_WIDTH)
                return false;

            if (board[pieceRow + 2][pieceCol + 2] != 0)
                return false;
        }

        else if (rotation == 2)
        {
            if (pieceCol + 3 >= BOARD_WIDTH)
                return false;

            if (board[pieceRow + 1][pieceCol + 3] != 0 ||
                board[pieceRow][pieceCol + 3] != 0)
                return false;
        }

        else if (rotation == 3)
        {
            if (pieceCol + 2 >= BOARD_WIDTH)
                return false;

            if (board[pieceRow][pieceCol + 2] != 0 ||
                board[pieceRow + 1][pieceCol + 2] != 0 ||
                board[pieceRow + 2][pieceCol + 2] != 0)
                return false;
        }
    }

    return true;
}
void lockPiece()
{
    if (currentShape == 0) // I
    {
        if (rotation == 0 || rotation == 2)
        {
            board[pieceRow][pieceCol] = currentShape + 1;
            board[pieceRow][pieceCol + 1] = currentShape + 1;
            board[pieceRow][pieceCol + 2] = currentShape + 1;
            board[pieceRow][pieceCol + 3] = currentShape + 1;
        }
        else
        {
            board[pieceRow][pieceCol] = currentShape + 1;
            board[pieceRow + 1][pieceCol] = currentShape + 1;
            board[pieceRow + 2][pieceCol] = currentShape + 1;
            board[pieceRow + 3][pieceCol] = currentShape + 1;
        }
    }

    else if (currentShape == 1) // O
    {
        board[pieceRow][pieceCol] = currentShape + 1;
        board[pieceRow][pieceCol + 1] = currentShape + 1;
        board[pieceRow + 1][pieceCol] = currentShape + 1;
        board[pieceRow + 1][pieceCol + 1] = currentShape + 1;
    }

    else if (currentShape == 2) // T
    {
        if (rotation == 0)
        {
            board[pieceRow][pieceCol + 1] = currentShape + 1;

            board[pieceRow + 1][pieceCol] = currentShape + 1;
            board[pieceRow + 1][pieceCol + 1] = currentShape + 1;
            board[pieceRow + 1][pieceCol + 2] = currentShape + 1;
        }

        else if (rotation == 1)
        {
            board[pieceRow][pieceCol] = currentShape + 1;

            board[pieceRow + 1][pieceCol] = currentShape + 1;
            board[pieceRow + 1][pieceCol + 1] = currentShape + 1;

            board[pieceRow + 2][pieceCol] = currentShape + 1;
        }

        else if (rotation == 2)
        {
            board[pieceRow][pieceCol] = currentShape + 1;
            board[pieceRow][pieceCol + 1] = currentShape + 1;
            board[pieceRow][pieceCol + 2] = currentShape + 1;

            board[pieceRow + 1][pieceCol + 1] = currentShape + 1;
        }

        else if (rotation == 3)
        {
            board[pieceRow][pieceCol + 1] = currentShape + 1;

            board[pieceRow + 1][pieceCol] = currentShape + 1;
            board[pieceRow + 1][pieceCol + 1] = currentShape + 1;

            board[pieceRow + 2][pieceCol + 1] = currentShape + 1;
        }
    }

    else if (currentShape == 3) // L
    {
        if (rotation == 0)
        {
            board[pieceRow][pieceCol] = currentShape + 1;
            board[pieceRow][pieceCol + 1] = currentShape + 1;
            board[pieceRow][pieceCol + 2] = currentShape + 1;
            board[pieceRow + 1][pieceCol] = currentShape + 1;
        }

        else if (rotation == 1)
        {
            board[pieceRow][pieceCol] = currentShape + 1;

            board[pieceRow + 1][pieceCol] = currentShape + 1;

            board[pieceRow + 2][pieceCol] = currentShape + 1;
            board[pieceRow + 2][pieceCol + 1] = currentShape + 1;
        }

        else if (rotation == 2)
        {
            board[pieceRow][pieceCol + 2] = currentShape + 1;

            board[pieceRow + 1][pieceCol] = currentShape + 1;
            board[pieceRow + 1][pieceCol + 1] = currentShape + 1;
            board[pieceRow + 1][pieceCol + 2] = currentShape + 1;
        }
        else if (rotation == 3)
        {
            board[pieceRow][pieceCol] = currentShape + 1;
            board[pieceRow][pieceCol + 1] = currentShape + 1;

            board[pieceRow + 1][pieceCol + 1] = currentShape + 1;

            board[pieceRow + 2][pieceCol + 1] = currentShape + 1;
        }
    }
}
void clearLine()
{
    for (int row = BOARD_HEIGHT - 1; row >= 0; row--)
    {
        cout << "Row " << row << ": ";

        for (int col = 0; col < BOARD_WIDTH; col++)
        {
            cout << board[row][col] << " ";
        }

        cout << endl;

        bool full = true;

        for (int col = 0; col < BOARD_WIDTH; col++)
        {
            if (board[row][col] == 0)
            {
                full = false;
                break;
            }
        }

        if (full)
        {
            cout << "FULL ROW FOUND: " << row << endl;

            for (int r = row; r > 0; r--)
            {
                for (int col = 0; col < BOARD_WIDTH; col++)
                {
                    board[r][col] = board[r - 1][col];
                }
            }

            for (int col = 0; col < BOARD_WIDTH; col++)
            {
                board[0][col] = 0;
            }

            score += 100;
        }
    }
}

bool canSpawnPiece()
{
    if (currentShape == 0) // I
    {
        if (rotation == 0 || rotation == 2)
        {
            return validRotation(0, 3) &&
                   validRotation(0, 4) &&
                   validRotation(0, 5) &&
                   validRotation(0, 6);
        }
        else
        {
            return validRotation(0, 3) &&
                   validRotation(1, 3) &&
                   validRotation(2, 3) &&
                   validRotation(3, 3);
        }
    }

    else if (currentShape == 1) // O
    {
        return validRotation(0, 3) &&
               validRotation(0, 4) &&
               validRotation(1, 3) &&
               validRotation(1, 4);
    }

    else if (currentShape == 2) // T
    {
        if (rotation == 0)
        {
            return validRotation(0, 4) &&
                   validRotation(1, 3) &&
                   validRotation(1, 4) &&
                   validRotation(1, 5);
        }

        else if (rotation == 1)
        {
            return validRotation(0, 3) &&
                   validRotation(1, 3) &&
                   validRotation(1, 4) &&
                   validRotation(2, 3);
        }

        else if (rotation == 2)
        {
            return validRotation(0, 3) &&
                   validRotation(0, 4) &&
                   validRotation(0, 5) &&
                   validRotation(1, 4);
        }

        else
        {
            return validRotation(0, 4) &&
                   validRotation(1, 3) &&
                   validRotation(1, 4) &&
                   validRotation(2, 4);
        }
    }

    else if (currentShape == 3) // L
    {
        if (rotation == 0)
        {
            return validRotation(0, 3) &&
                   validRotation(0, 4) &&
                   validRotation(0, 5) &&
                   validRotation(1, 3);
        }

        else if (rotation == 1)
        {
            return validRotation(0, 3) &&
                   validRotation(1, 3) &&
                   validRotation(2, 3) &&
                   validRotation(2, 4);
        }

        else if (rotation == 2)
        {
            return validRotation(0, 5) &&
                   validRotation(1, 3) &&
                   validRotation(1, 4) &&
                   validRotation(1, 5);
        }

        else
        {
            return validRotation(0, 3) &&
                   validRotation(0, 4) &&
                   validRotation(1, 4) &&
                   validRotation(2, 4);
        }
    }

    return false;
}

void specialKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_UP)
    {
        if (canRotate())
        {
            rotatePiece();
        }
    }
    if (key == GLUT_KEY_RIGHT)
    {
        if (canMoveRight())
        {
            pieceCol++;
        }
    }

    if (key == GLUT_KEY_LEFT)
    {
        if (canMoveleft())
        {
            pieceCol--;
        }
    }

    if (key == GLUT_KEY_DOWN)
    {
        if (GameOver)
        {
            return;
        }
        if (canMoveDown())
        {
            pieceRow++;
        }
        else
        {
            lockPiece();
            clearLine();
            newPiece();
        }
    }

    glutPostRedisplay();
}

void drawBoard()
{
    if (currentShape == 0)
    {
        // I
        drawIShape();
    }
    else if (currentShape == 1)
    {
        // O
        drawOShape();
    }
    else if (currentShape == 2)
    {
        // T
        drawTShape();
    }
    else if (currentShape == 3)
    {
        // L
        drawLShape();
    }

    for (int row = 0; row < BOARD_HEIGHT; row++)
    {
        for (int col = 0; col < BOARD_WIDTH; col++)
        {
            if (board[row][col] == 0)
            {
                int px = col * BLOCK_SIZE;
                int py = row * BLOCK_SIZE;

                glColor3f(0.15f, 0.15f, 0.15f);
                glBegin(GL_LINE_LOOP);
                glVertex2i(px, py);
                glVertex2i(px + BLOCK_SIZE, py);
                glVertex2i(px + BLOCK_SIZE, py + BLOCK_SIZE);
                glVertex2i(px, py + BLOCK_SIZE);
                glEnd();
            }
            else
            {
                if (board[row][col] == 1) // I
                {
                    drawBlock(col, row, 0.0f, 1.0f, 1.0f);
                }
                else if (board[row][col] == 2) // O
                {
                    drawBlock(col, row, 1.0f, 1.0f, 0.0f);
                }
                else if (board[row][col] == 3) // T
                {
                    drawBlock(col, row, 1.0f, 0.0f, 0.0f);
                }
                else if (board[row][col] == 4) // L
                {
                    drawBlock(col, row, 0.2f, 0.6f, 0.1f);
                }
            }
        }
    }
}

#endif // BOARD_H
#ifndef BOARD_H

#define BOARD_H

#include <GL/glut.h>
#include <cstdlib>
#include <ctime>

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

void newPiece()
{
    currentShape = rand() % 4;

    pieceRow = 0;
    pieceCol = 3;
}
void drawIShape()
{
    drawBlock(pieceCol, pieceRow, 1.0f, 0.0f, 1.0f);
    drawBlock(pieceCol+1, pieceRow, 1.0f, 0.0f, 1.0f);
    drawBlock(pieceCol+2, pieceRow, 1.0f, 0.0f, 1.0f);
    drawBlock(pieceCol+3, pieceRow, 1.0f, 0.0f, 1.0f);
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
    drawBlock(pieceCol + 1, pieceRow, 1.0f, 0.0f, 0.0f);
    drawBlock(pieceCol, pieceRow + 1, 1.0f, 0.0f, 0.0f);
    drawBlock(pieceCol + 1, pieceRow + 1, 1.0f, 0.0f, 0.0f);
    drawBlock(pieceCol + 2, pieceRow + 1, 1.0f, 0.0f, 0.0f);
}

void drawLShape()
{
    drawBlock(pieceCol, pieceRow, 0.2f, 0.6f, 0.1f);
    drawBlock(pieceCol + 1, pieceRow, 0.2f, 0.6f, 0.1f);
    drawBlock(pieceCol + 2, pieceRow, 0.2f, 0.6f, 0.1f);
    drawBlock(pieceCol, pieceRow + 1, 0.2f, 0.6f, 0.1f);
}

bool canMoveDown()
{
    if (currentShape == 0)
    {
        //L
        if (pieceRow + 2 >= BOARD_HEIGHT)
        {
            return false;
        }

        if (board[pieceRow + 2][pieceCol] != 0)
        {
            return false;
        }

        if (board[pieceRow + 1][pieceCol + 1] != 0)
        {
            return false;
        }

        if (board[pieceRow + 1][pieceCol + 2] != 0)
        {
            return false;
        }
    }
    else if (currentShape == 1)
    {
        //T
        if (pieceRow + 2 >= BOARD_HEIGHT)
        {
            return false;
        }

        if (board[pieceRow + 2][pieceCol] != 0)
        {
            return false;
        }

        if (board[pieceRow + 2][pieceCol + 1] != 0)
        {
            return false;
        }

        if (board[pieceRow + 2][pieceCol + 2] != 0)
        {
            return false;
        }
    }
    else if (currentShape == 2)
    {
        //O
        if (pieceRow + 2 >= BOARD_HEIGHT)
        {
            return false;
        }

        if (board[pieceRow + 2][pieceCol] != 0)
        {
            return false;
        }

        if (board[pieceRow + 2][pieceCol + 1] != 0)
        {
            return false;
        }
    }
    else if (currentShape == 3)
{
    //I
    if (pieceRow + 1 >= BOARD_HEIGHT)
    {
        return false;
    }

    if (board[pieceRow + 1][pieceCol] != 0)
    {
        return false;
    }

    if (board[pieceRow + 1][pieceCol + 1] != 0)
    {
        return false;
    }

    if (board[pieceRow + 1][pieceCol + 2] != 0)
    {
        return false;
    }

    if (board[pieceRow + 1][pieceCol + 3] != 0)
    {
        return false;
    }
}

    return true;
}

bool canMoveleft()
{
    if (currentShape == 0)
    {
        //L
        if (pieceCol <= 0)
        {
            return false;
        }

        if (board[pieceRow][pieceCol - 1] != 0)
        {
            return false;
        }

        if (board[pieceRow + 1][pieceCol - 1] != 0)
        {
            return false;
        }
    }
    else if (currentShape == 1)
    {
        //T
        if (pieceCol <= 0)
        {
            return false;
        }

        if (board[pieceRow + 1][pieceCol - 1] != 0)
        {
            return false;
        }
    }
    else if (currentShape == 2)
    {
        //O
        if (pieceCol <= 0)
        {
            return false;
        }

        if (board[pieceRow][pieceCol - 1] != 0)
        {
            return false;
        }

        if (board[pieceRow + 1][pieceCol - 1] != 0)
        {
            return false;
        }
    }
    else if (currentShape == 3)
{
    //I
    if (pieceCol <= 0)
    {
        return false;
    }

    if (board[pieceRow][pieceCol - 1] != 0)
    {
        return false;
    }
}

    return true;
}

bool canMoveRight()
{
    if (currentShape == 0)
    {
        //L
        if (pieceCol + 3 >= BOARD_WIDTH)
        {
            return false;
        }

        if (board[pieceRow][pieceCol + 3] != 0)
        {
            return false;
        }
    }
    else if (currentShape == 1)
    {
        //T
        if (pieceCol + 3 >= BOARD_WIDTH)
        {
            return false;
        }

        if (board[pieceRow + 1][pieceCol + 3] != 0)
        {
            return false;
        }
    }
    else if (currentShape == 2)
    {
        //O
        if (pieceCol + 2 >= BOARD_WIDTH)
        {
            return false;
        }

        if (board[pieceRow][pieceCol + 2] != 0)
        {
            return false;
        }

        if (board[pieceRow + 1][pieceCol + 2] != 0)
        {
            return false;
        }
    }
    else if (currentShape == 3)
{
    //I
    if(pieceCol+4 >=BOARD_WIDTH){
        return false;
    }
    if(board[pieceRow][pieceCol+4]!=0)
    {
        return false;
    }
}

    return true;
}

void lockPiece()
{
    if (currentShape == 0)
    {
        //L
        board[pieceRow][pieceCol] = 1;
        board[pieceRow][pieceCol + 1] = 1;
        board[pieceRow][pieceCol + 2] = 1;
        board[pieceRow + 1][pieceCol] = 1;
    }
    else if (currentShape == 1)
    {
        //T
        board[pieceRow][pieceCol + 1] = 1;
        board[pieceRow + 1][pieceCol] = 1;
        board[pieceRow + 1][pieceCol + 1] = 1;
        board[pieceRow + 1][pieceCol + 2] = 1;
    }
    else if (currentShape == 2)
    {
        //O
        board[pieceRow][pieceCol] = 1;
        board[pieceRow][pieceCol + 1] = 1;
        board[pieceRow + 1][pieceCol] = 1;
        board[pieceRow + 1][pieceCol + 1] = 1;
    }
    else if (currentShape == 3)
{
    //I
    board[pieceRow][pieceCol] = 1;
    board[pieceRow][pieceCol + 1] = 1;
    board[pieceRow][pieceCol + 2] = 1;
    board[pieceRow][pieceCol + 3] = 1;
}
}

void specialKeys(int key, int x, int y)
{
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
        if (canMoveDown())
        {
            pieceRow++;
        }
        else
        {
            lockPiece();
            newPiece();
        }
    }

    glutPostRedisplay();
}

void drawBoard()
{
    if (currentShape == 0)
    {
        //L
        drawLShape();
    }
    else if (currentShape == 1)
    {
        //T
        drawTShape();
    }
    else if (currentShape == 2)
    {
        //O
        drawOShape();
    }
    else if (currentShape == 3)
{
    //I
    drawIShape();
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
                drawBlock(col, row, 0.2f, 0.6f, 1.0f);
            }
        }
    }
}

#endif // BOARD_H
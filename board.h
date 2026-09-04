#ifndef BOARD_H
#define BOARD_H

#include <GL/glut.h>

// ---------- Global board configuration ----------
const int BOARD_WIDTH  = 10;   // number of columns
const int BOARD_HEIGHT = 20;   // number of rows
const int BLOCK_SIZE   = 50;   // size of one block in pixels

// Window size is derived from the board so they always stay in sync
const int WINDOW_WIDTH  = BOARD_WIDTH  * BLOCK_SIZE;
const int WINDOW_HEIGHT = BOARD_HEIGHT * BLOCK_SIZE;

// Board matrix: 0 = empty cell, non-zero = filled cell (can later hold a color/id)
int board[BOARD_HEIGHT][BOARD_WIDTH];

// ---------- Function declarations ----------
void initBoard();
void drawBlock(int col, int row, float r, float g, float b);
void drawBoard();

// ---------- Function definitions ----------

// Clears the board matrix (all cells empty)
void initBoard() {
    for (int row = 0; row < BOARD_HEIGHT; row++) {
        for (int col = 0; col < BOARD_WIDTH; col++) {
            board[row][col] = 0;
        }
    }
}

// Draws a single filled block at grid position (col, row)
void drawBlock(int col, int row, float r, float g, float b) {
    int px = col * BLOCK_SIZE;
    int py = row * BLOCK_SIZE;

    // filled square
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
        glVertex2i(px, py);
        glVertex2i(px + BLOCK_SIZE, py);
        glVertex2i(px + BLOCK_SIZE, py + BLOCK_SIZE);
        glVertex2i(px, py + BLOCK_SIZE);
    glEnd();

    // block border
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2i(px, py);
        glVertex2i(px + BLOCK_SIZE, py);
        glVertex2i(px + BLOCK_SIZE, py + BLOCK_SIZE);
        glVertex2i(px, py + BLOCK_SIZE);
    glEnd();
}

// Draws the whole board: filled cells as blocks, empty cells as a faint grid
void drawBoard() {
    for (int row = 0; row < BOARD_HEIGHT; row++) {
        for (int col = 0; col < BOARD_WIDTH; col++) {
            if (board[row][col] == 0) {
                // empty cell -> just draw grid outline
                int px = col * BLOCK_SIZE;
                int py = row * BLOCK_SIZE;

                glColor3f(0.15f, 0.15f, 0.15f);
                glBegin(GL_LINE_LOOP);
                    glVertex2i(px, py);
                    glVertex2i(px + BLOCK_SIZE, py);
                    glVertex2i(px + BLOCK_SIZE, py + BLOCK_SIZE);
                    glVertex2i(px, py + BLOCK_SIZE);
                glEnd();
            } else {
                // filled cell -> draw a colored block
                drawBlock(col, row, 0.2f, 0.6f, 1.0f);
            }
        }
    }
}

#endif // BOARD_H
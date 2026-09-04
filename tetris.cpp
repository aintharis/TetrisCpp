#include <GL/glut.h>
#include "game.h"
#include <iostream>
using namespace std;
void resetGame() {
    glutPostRedisplay();
    pieceRow = 0;  // Spawn back at top row
    pieceCol = 3;  // Center column
}

// Sets up OpenGL state and coordinate system
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // y-flipped ortho so row 0 of the board matrix appears at the TOP of the window
    gluOrtho2D(0, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    glMatrixMode(GL_MODELVIEW);

    initBoard();
}
void game(){
    drawLShape();
    if(pieceRow == 18){
        board[pieceRow][pieceCol] = 1;
        board[pieceRow][pieceCol+1] = 1;
        board[pieceRow][pieceCol+2] = 1;
        board[pieceRow+1][pieceCol] = 1;

        resetGame();
    }
}
// GLUT display callback
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawBoard();
    game();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tetris - Board");
    glutSpecialFunc(specialKeys);
    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
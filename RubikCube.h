#pragma once
//
// Created by atima on 16.10.2024.
//

#ifndef UNTITLED5_RUBIKCUBE_H
#define UNTITLED5_RUBIKCUBE_H
#include <iostream>
#include <fstream>  // For file operations
#include <ctime>
#include <cstdlib>
using namespace std;
class RubikCube {
private:
    // 3D array for storing cube faces (6 faces, each 3x3)
    char temp_s[6][3][3];
    char cube[6][3][3];
    // Possible colors for the cube faces
    char colors[6] = { 'W', 'Y', 'R', 'O', 'G', 'B' }; // White, Yellow, Red, Orange, Green, Blue

    



public:
    RubikCube();

    int getFaceIndex(char centerColor);
    // Method to fill the cube with random colors
    void fillRandomColors();

    void getFace(int face, char faceData[3][3]);
    void getFullcub(char masiv[6][3][3]);
   
    void display();


    // Method to rotate a face clockwise
    void rotateFaceClockwise(int face);


    void rotateFaceCounterClockwise(int face);


    void rotateRow(int row, bool clockwise);


    void rotateColumn(int col, bool clockwise);


    void loadingfromfiletotemp(const string& name);

    void transtocube();

    bool isValidColorArrangement();


};

#endif //UNTITLED5_RUBIKCUBE_H



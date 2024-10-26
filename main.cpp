#include <iostream>
#include "RubikCube.h"
#include <fstream>  // For file operations
#include <ctime>
#include <cstdlib>
using namespace std; // Use the standard namespace


int main() {
    RubikCube cube;
    int choice, face, direction, layer;
    string name;

    while (true) {
        cout << "What would you like to do?\n";
        cout << "1. Rotate a face\n";
        cout << "2. Rotate a row\n";
        cout << "3. Rotate a column\n";
        cout << "4. Check if the cube is solved\n";
        cout << "5. Show the current state of the cube\n";
        cout << "6. Load configuration from file\n";
        cout << "7. Fill with random colors\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Select a face to rotate:\n";
            cout << "0 - Front\n1 - Back\n2 - Left\n3 - Right\n4 - Up\n5 - Down\n";
            cin >> face;
            cout << "Select rotation direction:\n";
            cout << "1 - Clockwise\n0 - Counter-clockwise\n";
            cin >> direction;
            if (direction) {
                cube.rotateFaceClockwise(face);
            }
            else {
                cube.rotateFaceCounterClockwise(face);
            }
            break;
        case 2:
            cout << "Enter row number (0-2): ";
            cin >> layer;
            cout << "Select rotation direction:\n";
            cout << "1 - Clockwise\n0 - Counter-clockwise\n";
            cin >> direction;
            cube.rotateRow(layer, direction);
            break;
        case 3:
            cout << "Enter column number (0-2): ";
            cin >> layer;
            cout << "Select rotation direction:\n";
            cout << "1 - Up\n0 - Down\n";
            cin >> direction;
            cube.rotateColumn(layer, direction);
            break;
        case 4:
            if (cube.isValidColorArrangement()) {
                cout << "The cube is solved!" << endl;
            }
            else {
                cout << "The cube is not solved." << endl;
            }
            break;
        case 5:
            cube.display();
            break;
        case 6:

            cube.loadingfromfiletotemp("fil");
            break;
        case 7:
            cube.fillRandomColors();
            break;
        case 8:
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
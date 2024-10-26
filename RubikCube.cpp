#include "RubikCube.h"

// 3D array for storing cube faces (6 faces, each 3x3)

int RubikCube::getFaceIndex(char centerColor)
{
    switch (centerColor)
    {
    case 'W': return 0;
    case 'Y': return 1;
    case 'R': return 2;
    case 'O': return 3;
    case 'G': return 4;
    case 'B': return 5;
    default:
        return -1;
    }
}




void RubikCube:: getFace(int face, char faceData[3][3]){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            faceData[i][j] = cube[face][i][j]; 
        }
    }
}

void RubikCube::getFullcub(char masiv[6][3][3]) {
    for (int face = 0; face < 6; ++face) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                masiv[face][i][j] = cube[face][i][j];
            }
        }
    }
}



RubikCube::RubikCube() {
    srand(time(0));
    // Initialize the cube — all faces empty
    for (int face = 0; face < 6; face++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cube[face][i][j] = ' ';
            }
        }
    }
}

// Method to fill the cube with random colors
void RubikCube::fillRandomColors() {
    for (int face = 0; face < 6; face++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cube[face][i][j] = colors[rand() % 6];
            }
        }
    }
}

void RubikCube::display() {
    string faceNames[6] = { "Front", "Back", "Left", "Right", "Up", "Down" };
    for (int face = 0; face < 6; face++) {
        cout << faceNames[face] << " face:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << cube[face][i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

// Method to rotate a face clockwise
void RubikCube::rotateFaceClockwise(int face) {
    char temp[3][3];
    // Copy the current face into a temporary array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp[i][j] = cube[face][i][j];
        }
    }
    // Rotate the face
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cube[face][j][2 - i] = temp[i][j];
        }
    }
}

void RubikCube::rotateFaceCounterClockwise(int face) {
    char temp[3][3];
    // Copy the current face into a temporary array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp[i][j] = cube[face][i][j];
        }
    }
    // Rotate the face counter-clockwise
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cube[face][2 - j][i] = temp[i][j];
        }
    }
}

void RubikCube::rotateRow(int row, bool clockwise) {
    char temp[3];
    if (clockwise) {
        // Rotate the row clockwise
        for (int j = 0; j < 3; j++) {
            temp[j] = cube[0][row][j];  // Save the front row
        }
        for (int j = 0; j < 3; j++) {
            cube[0][row][j] = cube[3][row][j];  // Left -> Front
            cube[3][row][j] = cube[1][row][j];  // Right -> Left
            cube[1][row][j] = cube[2][row][j];  // Back -> Right
            cube[2][row][j] = temp[j];          // Front -> Back
        }
    }
    else {
        // Rotate the row counter-clockwise
        for (int j = 0; j < 3; j++) {
            temp[j] = cube[0][row][j];  // Save the front row
        }
        for (int j = 0; j < 3; j++) {
            cube[0][row][j] = cube[2][row][j];  // Back -> Front
            cube[2][row][j] = cube[1][row][j];  // Right -> Back
            cube[1][row][j] = cube[3][row][j];  // Left -> Right
            cube[3][row][j] = temp[j];          // Front -> Left
        }
    }
}

void RubikCube::rotateColumn(int col, bool clockwise) {
    char temp[3];  // Temporary array for storing column values
    if (clockwise) {
        // Save elements from the top face
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[4][i][col];  // Top face
        }
        // Moving elements:
        for (int i = 0; i < 3; i++) {
            cube[4][i][col] = cube[0][i][col];  // Front -> Top
        }
        for (int i = 0; i < 3; i++) {
            cube[0][i][col] = cube[5][i][col];  // Bottom -> Front
        }
        for (int i = 0; i < 3; i++) {
            cube[5][i][col] = cube[1][i][col];  // Back -> Bottom
        }
        for (int i = 0; i < 3; i++) {
            cube[1][i][col] = temp[i];  // Top -> Back
        }
    }
    else {
        // Rotate the column counter-clockwise
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[4][i][col];  // Top face
        }
        for (int i = 0; i < 3; i++) {
            cube[4][i][col] = cube[1][i][col];  // Back -> Top
        }
        for (int i = 0; i < 3; i++) {
            cube[1][i][col] = cube[5][i][col];  // Bottom -> Back
        }
        for (int i = 0; i < 3; i++) {
            cube[5][i][col] = cube[0][i][col];  // Front -> Bottom
        }
        for (int i = 0; i < 3; i++) {
            cube[0][i][col] = temp[i];  // Top -> Front
        }
    }
}

void RubikCube::loadingfromfiletotemp(const string& name) {
    ifstream fin(name + ".txt");
    if (!fin.is_open()) {
        cerr << "error while opening  fil.txt" << endl;
    }
    cout << "File opened successfully.\n";

    for (int face = 0; face < 6; face++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (!(fin >> temp_s[face][i][j])) { // Читаем символ в куб
                    cerr << "error in " << face << ", position (" << i << ", " << j << ")" << endl;


                }
            }
        }
    }


    fin.close();
    transtocube();
}

void RubikCube::transtocube() {
    for (int i = 0; i < 6; i++) {
        int targetFace = getFaceIndex(temp_s[i][1][1]); // Получаем центральный цвет

        if (targetFace != -1) {
            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                    cube[targetFace][row][col] = temp_s[i][row][col];
                }
            }
        }
        else {
            cerr << "Invalid data in face " << i << endl; // Уведомление о неверных данных
        }
    }

    cout << "Cube loaded from the selected file\n";

}





bool RubikCube::isValidColorArrangement() {
    const int expectedCount = 9;
    int colorCount[6] = { 0 }; // Массив для подсчета количества каждого цвета

    for (int face = 0; face < 6; ++face) {
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                char color = cube[face][row][col];
                int index = getFaceIndex(color);

                if (index != -1) {
                    colorCount[index]++;
                }
                else {
                    std::cerr << "Invalid color found: " << color << std::endl;
                    return false; // Если найден неверный цвет, вернуть false
                }
            }
        }
    }

    // Проверка, что каждый цвет встречается 9 раз
    for (int i = 0; i < 6; ++i) {
        if (colorCount[i] != expectedCount) {
            std::cerr << "Invalid color count for index " << i << ": " << colorCount[i] << std::endl;
            return false;
        }
    }

    return true;
}


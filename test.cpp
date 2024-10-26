#include "pch.h"

#include "D:\pois\Project7\Project7\RubikCube.h"
#include "D:\pois\Project7\Project7\RubikCube.cpp"


TEST(Rubictest, rotateFaceCounterClockwise) {
    RubikCube cube;
    char mas[3][3];  // ������ ��� �������� ���������� �������� ����� ����� ��������
    char testmas[3][3] = {
        {'W', 'W', 'W'},
        {'W', 'W', 'W'},
        {'Y', 'Y', 'B'}  // ����� ���� ���������� ���������
    };

    // ��������� ��� �� ����� (�����������, ��� "tren" ���� �������� ������ ����)
    cube.loadingfromfiletotemp("fil");

    // ������ ������� �������� ����� ������ ������� �������
    cube.rotateFaceCounterClockwise(0);

    // �������� ��������� �������� ����� � ������ mas
    cube.getFace(0, mas);

    // ���������, ��� ��� �������� ������� mas ������������� ���������� ���������� testmas
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ASSERT_EQ(mas[i][j], testmas[i][j]) << "Mismatch at position (" << i << ", " << j << ")";
        }
    }
}

TEST(Rubictest, rotateFaceClockwise) {
    RubikCube cube;
    char mas[3][3];  // ������ ��� �������� ���������� �������� ����� ����� ��������
    char testmas[3][3] = {
        {'B', 'Y', 'Y'},
        {'W', 'W', 'W'},
        {'W', 'W', 'W'}  // ����� ���� ���������� ���������
    };

    // ��������� ��� �� ����� (�����������, ��� "tren" ���� �������� ������ ����)
    cube.loadingfromfiletotemp("fil");

    // ������ ������� �������� ����� ������ ������� �������
    cube.rotateFaceClockwise(0);

    // �������� ��������� �������� ����� � ������ mas
    cube.getFace(0, mas);

    // ���������, ��� ��� �������� ������� mas ������������� ���������� ���������� testmas
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ASSERT_EQ(mas[i][j], testmas[i][j]) << "Mismatch at position (" << i << ", " << j << ")";
        }
    }
}

TEST(Rubictest, rotateRowleft) {
    RubikCube cube;
    char mas[3][3];  // ������ ��� �������� ���������� �������� ����� ����� ��������
    char testmas[3][3] = {
        {'O', 'O', 'O'},
        {'Y', 'W', 'W'},
        {'B', 'W', 'W'}  // ����� ���� ���������� ���������
    };

    // ��������� ��� �� ����� (�����������, ��� "tren" ���� �������� ������ ����)
    cube.loadingfromfiletotemp("fil");

    // ������ ������� �������� ����� ������ ������� �������
    cube.rotateRow(0, true);

    // �������� ��������� �������� ����� � ������ mas
    cube.getFace(0, mas);

    // ���������, ��� ��� �������� ������� mas ������������� ���������� ���������� testmas
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ASSERT_EQ(mas[i][j], testmas[i][j]) << "Mismatch at position (" << i << ", " << j << ")";
        }
    }
}

TEST(Rubictest, rotateRowRight) {
    RubikCube cube;
    char mas[3][3];  // ������ ��� �������� ���������� �������� ����� ����� ��������
    char testmas[3][3] = {
        {'R', 'R', 'R'},
        {'Y', 'W', 'W'},
        {'B', 'W', 'W'}  // ����� ���� ���������� ���������
    };

    // ��������� ��� �� ����� (�����������, ��� "tren" ���� �������� ������ ����)
    cube.loadingfromfiletotemp("fil");

    // ������ ������� �������� ����� ������ ������� �������
    cube.rotateRow(0, false);

    // �������� ��������� �������� ����� � ������ mas
    cube.getFace(0, mas);

    // ���������, ��� ��� �������� ������� mas ������������� ���������� ���������� testmas
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ASSERT_EQ(mas[i][j], testmas[i][j]) << "Mismatch at position (" << i << ", " << j << ")";
        }
    }
}
TEST(Rubictest, rotateColumnUp) {
    RubikCube cube;
    char mas[3][3];  // ������ ��� �������� ���������� �������� ����� ����� ��������
    char testmas[3][3] = {
        {'Y', 'B', 'W'},
        {'Y', 'B', 'W'},
        {'B', 'B', 'W'}  // ����� ���� ���������� ���������
    };

    // ��������� ��� �� ����� (�����������, ��� "tren" ���� �������� ������ ����)
    cube.loadingfromfiletotemp("fil");

    // ������ ������� �������� ����� ������ ������� �������
    cube.rotateColumn(1, true);

    // �������� ��������� �������� ����� � ������ mas
    cube.getFace(0, mas);

    // ���������, ��� ��� �������� ������� mas ������������� ���������� ���������� testmas
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ASSERT_EQ(mas[i][j], testmas[i][j]) << "Mismatch at position (" << i << ", " << j << ")";
        }
    }
}

TEST(Rubictest, rotateColumnDown) {
    RubikCube cube;
    char mas[3][3];  // ������ ��� �������� ���������� �������� ����� ����� ��������
    char testmas[3][3] = {
        {'Y', 'G', 'W'},
        {'Y', 'G', 'W'},
        {'B', 'G', 'W'}  // ����� ���� ���������� ���������
    };

    // ��������� ��� �� ����� (�����������, ��� "tren" ���� �������� ������ ����)
    cube.loadingfromfiletotemp("fil");

    // ������ ������� �������� ����� ������ ������� �������
    cube.rotateColumn(1, false);

    // �������� ��������� �������� ����� � ������ mas
    cube.getFace(0, mas);

    // ���������, ��� ��� �������� ������� mas ������������� ���������� ���������� testmas
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ASSERT_EQ(mas[i][j], testmas[i][j]) << "Mismatch at position (" << i << ", " << j << ")";
        }
    }
}

TEST(Rubictest, loadingfromfile) {
    RubikCube cube;
    char mas[3][3];  // ������ ��� �������� ���������� �������� ����� ����� ��������
    char testmas[3][3] = {
        {'R', 'R', 'R'},
        {'R', 'R', 'R'},
        {'R', 'R', 'R'}  // ����� ���� ���������� ���������
    };

    // ��������� ��� �� ����� (�����������, ��� "tren" ���� �������� ������ ����)
    cube.loadingfromfiletotemp("fil");

    // ������ ������� �������� ����� ������ ������� �������

    // �������� ��������� �������� ����� � ������ mas
    cube.getFace(2, mas);

    // ���������, ��� ��� �������� ������� mas ������������� ���������� ���������� testmas
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ASSERT_EQ(mas[i][j], testmas[i][j]) << "Mismatch at position (" << i << ", " << j << ")";
        }
    }
}







TEST(RubikCubeTest, GetFaceIndexTest) {  
    RubikCube cube;

    // ����� ��� ���������� �������� ������
    EXPECT_EQ(cube.getFaceIndex('W'), 0);  // ����� �������
    EXPECT_EQ(cube.getFaceIndex('Y'), 1);  // Ƹ���� �������
    EXPECT_EQ(cube.getFaceIndex('R'), 2);  // ������� �������
    EXPECT_EQ(cube.getFaceIndex('O'), 3);  // ��������� �������
    EXPECT_EQ(cube.getFaceIndex('G'), 4);  // ������ �������
    EXPECT_EQ(cube.getFaceIndex('B'), 5);  // ����� �������

    // ����� ��� ������������ ��������
    EXPECT_EQ(cube.getFaceIndex('X'), -1);  // �������������� �������
    EXPECT_EQ(cube.getFaceIndex(' '), -1);  // ������
    EXPECT_EQ(cube.getFaceIndex('1'), -1);  // �������� ������
}



TEST(Rubictest, fillRandomColorsWithValidColors) {
    RubikCube cube;
    char randomizedCube[6][3][3];  // ������ ��� �������� ��������� ���� ����� ����������
    char colors[6] = { 'W', 'Y', 'R', 'O', 'G', 'B' };  // ������ ���������� ������

    // ��������� ����� ���������� �������
    cube.fillRandomColors();

    // ��������� ��������� ����
    cube.getFullcub(randomizedCube);

    // ���������, ��� ��� �������� ���� �������� ������ ���������� �����
    bool invalidColorFound = false;
    for (int face = 0; face < 6; ++face) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                char color = randomizedCube[face][i][j];

                // ���������, ��� ���� �� ���� ���� � ������� colors
                bool isValidColor = false;
                for (int k = 0; k < 6; ++k) {
                    if (color == colors[k]) {
                        isValidColor = true;
                        break;
                    }
                }

                // ���� ���� �� ������ � ����������, �������� ��� ������
                if (!isValidColor) {
                    invalidColorFound = true;
                    break;
                }
            }
            if (invalidColorFound) break;
        }
        if (invalidColorFound) break;
    }

    // ��������, ��� ��� ������������ ������
    ASSERT_FALSE(invalidColorFound) << "Invalid color found in the cube!";
}

TEST(Rubictest, getcube) {
    RubikCube cube;
    char mas[6][3][3];  // ������ ��� �������� ���������� �������� ����� ����� ��������
    char fixedCube[6][3][3] = {
        { {'W', 'W', 'W'}, {'W', 'W', 'W'}, {'W', 'W', 'W'} }, // Front face
        { {'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'} }, // Back face
        { {'R', 'R', 'R'}, {'R', 'R', 'R'}, {'R', 'R', 'R'} }, // Left face
        { {'O', 'O', 'O'}, {'O', 'O', 'O'}, {'O', 'O', 'O'} }, // Right face
        { {'G', 'G', 'G'}, {'G', 'G', 'G'}, {'G', 'G', 'G'} }, // Up face
        { {'B', 'B', 'B'}, {'B', 'B', 'B'}, {'B', 'B', 'B'} }  // Down face
    };

    // ��������� ��� �� ����� (�����������, ��� "tren" ���� �������� ������ ����)
    cube.loadingfromfiletotemp("fil1");

    // ������ ������� �������� ����� ������ ������� �������
    
    // �������� ��������� �������� ����� � ������ mas
    cube.getFullcub(mas);



    // ���������, ��� ��� �������� ������� mas ������������� ���������� ���������� testmas
    for (int face = 0; face < 6; ++face) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                ASSERT_EQ(mas[face][i][j], fixedCube[face][i][j]) << "Mismatch at position (" << i << ", " << j << ")";
            }
        }
    }
}

TEST(Rubictest, displaycub) {
    RubikCube cube;
    char mas[6][3][3];  // ������ ��� �������� ���������� �������� ����� ����� ��������
    char fixedCube[6][3][3] = {
        { {'W', 'W', 'W'}, {'W', 'W', 'W'}, {'W', 'W', 'W'} }, // Front face
        { {'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'} }, // Back face
        { {'R', 'R', 'R'}, {'R', 'R', 'R'}, {'R', 'R', 'R'} }, // Left face
        { {'O', 'O', 'O'}, {'O', 'O', 'O'}, {'O', 'O', 'O'} }, // Right face
        { {'G', 'G', 'G'}, {'G', 'G', 'G'}, {'G', 'G', 'G'} }, // Up face
        { {'B', 'B', 'B'}, {'B', 'B', 'B'}, {'B', 'B', 'B'} }  // Down face
    };

    // ��������� ��� �� ����� (�����������, ��� "tren" ���� �������� ������ ����)
    cube.loadingfromfiletotemp("fil1");

    // ������ ������� �������� ����� ������ ������� �������
    cube.display();
    // �������� ��������� �������� ����� � ������ mas
    cube.getFullcub(mas);



    // ���������, ��� ��� �������� ������� mas ������������� ���������� ���������� testmas
    for (int face = 0; face < 6; ++face) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                ASSERT_EQ(mas[face][i][j], fixedCube[face][i][j]) << "Mismatch at position (" << i << ", " << j << ")";
            }
        }
    }
}

TEST(Rubictest, isSolvableTest) {
    RubikCube solvableCube;
    RubikCube unsolvableCube;

    // ������ �������� ������������ ������ ������ (��������, �������� ���)
    solvableCube.loadingfromfiletotemp("fil1"); // ���� � �������� �������

    // ������ ���������� ������������ (��������, ������ ��� �������� �������)
    unsolvableCube.loadingfromfiletotemp("fil"); // ���� � ���������� �������

    // ���������, ��� �������� ��� ������
    ASSERT_TRUE(solvableCube.isValidColorArrangement()) << "The cube should be solvable";

    // ���������, ��� ���������� ������������ �� ����� ���� ������
    ASSERT_FALSE(unsolvableCube.isValidColorArrangement()) << "The cube should not be solvable";
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
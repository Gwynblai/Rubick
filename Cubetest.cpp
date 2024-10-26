#include "pch.h"

#include "D:\pois\Project7\Project7\RubikCube.h"
#include "D:\pois\Project7\Project7\RubikCube.cpp"


TEST(Rubictest, rotateFaceCounterClockwise) {
    RubikCube cube;
    char mas[3][3];  // Массив для хранения измененной передней грани после поворота
    char testmas[3][3] = {
        {'W', 'W', 'W'},
        {'W', 'W', 'W'},
        {'Y', 'Y', 'B'}  // Здесь ваше намеренное изменение
    };

    // Загружаем куб из файла (предположим, что "tren" файл содержит данные куба)
    cube.loadingfromfiletotemp("fil");

    // Делаем поворот передней грани против часовой стрелки
    cube.rotateFaceCounterClockwise(0);

    // Копируем изменённую переднюю грань в массив mas
    cube.getFace(0, mas);

    // Проверяем, что все элементы массива mas соответствуют ожидаемому результату testmas
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ASSERT_EQ(mas[i][j], testmas[i][j]) << "Mismatch at position (" << i << ", " << j << ")";
        }
    }
}

TEST(Rubictest, rotateFaceClockwise) {
    RubikCube cube;
    char mas[3][3];  // Массив для хранения измененной передней грани после поворота
    char testmas[3][3] = {
        {'B', 'Y', 'Y'},
        {'W', 'W', 'W'},
        {'W', 'W', 'W'}  // Здесь ваше намеренное изменение
    };

    // Загружаем куб из файла (предположим, что "tren" файл содержит данные куба)
    cube.loadingfromfiletotemp("fil");

    // Делаем поворот передней грани против часовой стрелки
    cube.rotateFaceClockwise(0);

    // Копируем изменённую переднюю грань в массив mas
    cube.getFace(0, mas);

    // Проверяем, что все элементы массива mas соответствуют ожидаемому результату testmas
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ASSERT_EQ(mas[i][j], testmas[i][j]) << "Mismatch at position (" << i << ", " << j << ")";
        }
    }
}

TEST(Rubictest, rotateRowleft) {
    RubikCube cube;
    char mas[3][3];  // Массив для хранения измененной передней грани после поворота
    char testmas[3][3] = {
        {'O', 'O', 'O'},
        {'Y', 'W', 'W'},
        {'B', 'W', 'W'}  // Здесь ваше намеренное изменение
    };

    // Загружаем куб из файла (предположим, что "tren" файл содержит данные куба)
    cube.loadingfromfiletotemp("fil");

    // Делаем поворот передней грани против часовой стрелки
    cube.rotateRow(0, true);

    // Копируем изменённую переднюю грань в массив mas
    cube.getFace(0, mas);

    // Проверяем, что все элементы массива mas соответствуют ожидаемому результату testmas
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ASSERT_EQ(mas[i][j], testmas[i][j]) << "Mismatch at position (" << i << ", " << j << ")";
        }
    }
}

TEST(Rubictest, rotateRowRight) {
    RubikCube cube;
    char mas[3][3];  // Массив для хранения измененной передней грани после поворота
    char testmas[3][3] = {
        {'R', 'R', 'R'},
        {'Y', 'W', 'W'},
        {'B', 'W', 'W'}  // Здесь ваше намеренное изменение
    };

    // Загружаем куб из файла (предположим, что "tren" файл содержит данные куба)
    cube.loadingfromfiletotemp("fil");

    // Делаем поворот передней грани против часовой стрелки
    cube.rotateRow(0, false);

    // Копируем изменённую переднюю грань в массив mas
    cube.getFace(0, mas);

    // Проверяем, что все элементы массива mas соответствуют ожидаемому результату testmas
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ASSERT_EQ(mas[i][j], testmas[i][j]) << "Mismatch at position (" << i << ", " << j << ")";
        }
    }
}
TEST(Rubictest, rotateColumnUp) {
    RubikCube cube;
    char mas[3][3];  // Массив для хранения измененной передней грани после поворота
    char testmas[3][3] = {
        {'Y', 'B', 'W'},
        {'Y', 'B', 'W'},
        {'B', 'B', 'W'}  // Здесь ваше намеренное изменение
    };

    // Загружаем куб из файла (предположим, что "tren" файл содержит данные куба)
    cube.loadingfromfiletotemp("fil");

    // Делаем поворот передней грани против часовой стрелки
    cube.rotateColumn(1, true);

    // Копируем изменённую переднюю грань в массив mas
    cube.getFace(0, mas);

    // Проверяем, что все элементы массива mas соответствуют ожидаемому результату testmas
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ASSERT_EQ(mas[i][j], testmas[i][j]) << "Mismatch at position (" << i << ", " << j << ")";
        }
    }
}

TEST(Rubictest, rotateColumnDown) {
    RubikCube cube;
    char mas[3][3];  // Массив для хранения измененной передней грани после поворота
    char testmas[3][3] = {
        {'Y', 'G', 'W'},
        {'Y', 'G', 'W'},
        {'B', 'G', 'W'}  // Здесь ваше намеренное изменение
    };

    // Загружаем куб из файла (предположим, что "tren" файл содержит данные куба)
    cube.loadingfromfiletotemp("fil");

    // Делаем поворот передней грани против часовой стрелки
    cube.rotateColumn(1, false);

    // Копируем изменённую переднюю грань в массив mas
    cube.getFace(0, mas);

    // Проверяем, что все элементы массива mas соответствуют ожидаемому результату testmas
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ASSERT_EQ(mas[i][j], testmas[i][j]) << "Mismatch at position (" << i << ", " << j << ")";
        }
    }
}

TEST(Rubictest, loadingfromfile) {
    RubikCube cube;
    char mas[3][3];  // Массив для хранения измененной передней грани после поворота
    char testmas[3][3] = {
        {'R', 'R', 'R'},
        {'R', 'R', 'R'},
        {'R', 'R', 'R'}  // Здесь ваше намеренное изменение
    };

    // Загружаем куб из файла (предположим, что "tren" файл содержит данные куба)
    cube.loadingfromfiletotemp("fil");

    // Делаем поворот передней грани против часовой стрелки

    // Копируем изменённую переднюю грань в массив mas
    cube.getFace(2, mas);

    // Проверяем, что все элементы массива mas соответствуют ожидаемому результату testmas
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ASSERT_EQ(mas[i][j], testmas[i][j]) << "Mismatch at position (" << i << ", " << j << ")";
        }
    }
}







TEST(RubikCubeTest, GetFaceIndexTest) {  
    RubikCube cube;

    // Тесты для допустимых символов цветов
    EXPECT_EQ(cube.getFaceIndex('W'), 0);  // Белая сторона
    EXPECT_EQ(cube.getFaceIndex('Y'), 1);  // Жёлтая сторона
    EXPECT_EQ(cube.getFaceIndex('R'), 2);  // Красная сторона
    EXPECT_EQ(cube.getFaceIndex('O'), 3);  // Оранжевая сторона
    EXPECT_EQ(cube.getFaceIndex('G'), 4);  // Зелёная сторона
    EXPECT_EQ(cube.getFaceIndex('B'), 5);  // Синяя сторона

    // Тесты для недопустимых символов
    EXPECT_EQ(cube.getFaceIndex('X'), -1);  // Несуществующая сторона
    EXPECT_EQ(cube.getFaceIndex(' '), -1);  // Пробел
    EXPECT_EQ(cube.getFaceIndex('1'), -1);  // Числовой символ
}



TEST(Rubictest, fillRandomColorsWithValidColors) {
    RubikCube cube;
    char randomizedCube[6][3][3];  // Массив для хранения состояния куба после заполнения
    char colors[6] = { 'W', 'Y', 'R', 'O', 'G', 'B' };  // Массив допустимых цветов

    // Заполняем кубик случайными цветами
    cube.fillRandomColors();

    // Сохраняем состояние куба
    cube.getFullcub(randomizedCube);

    // Проверяем, что все элементы куба содержат только допустимые цвета
    bool invalidColorFound = false;
    for (int face = 0; face < 6; ++face) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                char color = randomizedCube[face][i][j];

                // Проверяем, что цвет из куба есть в массиве colors
                bool isValidColor = false;
                for (int k = 0; k < 6; ++k) {
                    if (color == colors[k]) {
                        isValidColor = true;
                        break;
                    }
                }

                // Если цвет не найден в допустимых, помечаем как ошибку
                if (!isValidColor) {
                    invalidColorFound = true;
                    break;
                }
            }
            if (invalidColorFound) break;
        }
        if (invalidColorFound) break;
    }

    // Убедимся, что нет недопустимых цветов
    ASSERT_FALSE(invalidColorFound) << "Invalid color found in the cube!";
}

TEST(Rubictest, getcube) {
    RubikCube cube;
    char mas[6][3][3];  // Массив для хранения измененной передней грани после поворота
    char fixedCube[6][3][3] = {
        { {'W', 'W', 'W'}, {'W', 'W', 'W'}, {'W', 'W', 'W'} }, // Front face
        { {'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'} }, // Back face
        { {'R', 'R', 'R'}, {'R', 'R', 'R'}, {'R', 'R', 'R'} }, // Left face
        { {'O', 'O', 'O'}, {'O', 'O', 'O'}, {'O', 'O', 'O'} }, // Right face
        { {'G', 'G', 'G'}, {'G', 'G', 'G'}, {'G', 'G', 'G'} }, // Up face
        { {'B', 'B', 'B'}, {'B', 'B', 'B'}, {'B', 'B', 'B'} }  // Down face
    };

    // Загружаем куб из файла (предположим, что "tren" файл содержит данные куба)
    cube.loadingfromfiletotemp("fil1");

    // Делаем поворот передней грани против часовой стрелки
    
    // Копируем изменённую переднюю грань в массив mas
    cube.getFullcub(mas);



    // Проверяем, что все элементы массива mas соответствуют ожидаемому результату testmas
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
    char mas[6][3][3];  // Массив для хранения измененной передней грани после поворота
    char fixedCube[6][3][3] = {
        { {'W', 'W', 'W'}, {'W', 'W', 'W'}, {'W', 'W', 'W'} }, // Front face
        { {'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'} }, // Back face
        { {'R', 'R', 'R'}, {'R', 'R', 'R'}, {'R', 'R', 'R'} }, // Left face
        { {'O', 'O', 'O'}, {'O', 'O', 'O'}, {'O', 'O', 'O'} }, // Right face
        { {'G', 'G', 'G'}, {'G', 'G', 'G'}, {'G', 'G', 'G'} }, // Up face
        { {'B', 'B', 'B'}, {'B', 'B', 'B'}, {'B', 'B', 'B'} }  // Down face
    };

    // Загружаем куб из файла (предположим, что "tren" файл содержит данные куба)
    cube.loadingfromfiletotemp("fil1");

    // Делаем поворот передней грани против часовой стрелки
    cube.display();
    // Копируем изменённую переднюю грань в массив mas
    cube.getFullcub(mas);



    // Проверяем, что все элементы массива mas соответствуют ожидаемому результату testmas
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

    // Задаем решаемую конфигурацию кубика Рубика (например, решенный куб)
    solvableCube.loadingfromfiletotemp("fil1"); // Файл с решенным кубиком

    // Задаем нерешаемую конфигурацию (например, меняем два элемента местами)
    unsolvableCube.loadingfromfiletotemp("fil"); // Файл с нерешаемым кубиком

    // Проверяем, что решенный куб решаем
    ASSERT_TRUE(solvableCube.isValidColorArrangement()) << "The cube should be solvable";

    // Проверяем, что нерешаемая конфигурация не может быть решена
    ASSERT_FALSE(unsolvableCube.isValidColorArrangement()) << "The cube should not be solvable";
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

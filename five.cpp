#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>
typedef int myarray[5][5];
typedef int myarray2[7][7];

// Функция для поиска минимального положительного числа на главной диагонали
// матрицы
int minDiagonalValue(myarray2 arr) {
  int minVal = INT_MAX;
  for (int i = 0; i < 7; ++i) {
    if (arr[i][i] > 0 && arr[i][i] < minVal) {
      minVal = arr[i][i];
    }
  }
  return minVal == INT_MAX
             ? -1
             : minVal; // Если минимальное значение осталось равным INT_MAX,
                       // значит, в матрице не было положительных чисел
}
int minDiagonalValue(myarray arr) {
  int minVal = INT_MAX;
  for (int i = 0; i < 5; ++i) {
    if (arr[i][i] > 0 && arr[i][i] < minVal) {
      minVal = arr[i][i];
    }
  }
  return minVal == INT_MAX
             ? -1
             : minVal; // Если минимальное значение осталось равным INT_MAX,
                       // значит, в матрице не было положительных чисел
}

int main() {
  srand(time(0)); // для генерации случайных чисел
  int i = 0, j = 0;
  myarray2 A = {{0}};
  myarray B = {{0}};

  // Заполнение матрицы A случайными числами
  for (i = 0; i < 7; ++i) {
    for (j = 0; j < 7; ++j) {
      A[i][j] = rand() % 100; // генерируем число от 0 до 99
    }
  }

  // Заполнение матрицы B случайными числами
  for (i = 0; i < 5; ++i) {
    for (j = 0; j < 5; ++j) {
      B[i][j] = rand() % 100; // генерируем число от 0 до 99
    }
  }

  int minA = minDiagonalValue(A);
  int minB = minDiagonalValue(B);

  std::cout
      << "Минимальное положительное число на главной диагонали матрицы A: "
      << minA << std::endl;
  std::cout
      << "Минимальное положительное число на главной диагонали матрицы B: "
      << minB << std::endl;

  return 0;
}

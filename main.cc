#include <climits>
#include <cstdlib>
#include <ctime>
#include <drogon/drogon.h>
#include <iostream>
typedef int myarray[5][5];
typedef int myarray2[7][7];

using namespace drogon;

typedef std::function<void(const HttpResponsePtr &)> Callback;

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

int *getValue() {

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

  static int res[2];
  res[0] = minDiagonalValue(A);
  res[1] = minDiagonalValue(B);

  return res;
}

void importantHandler(const HttpRequestPtr &request, Callback &&callback) {
  // Формируем JSON-объект
  int *res = getValue();
  Json::Value jsonBody;
  jsonBody["resA"] = std::to_string(res[0]);
  jsonBody["resB"] = std::to_string(res[1]);

  // Формируем и отправляем ответ с JSON-объектом
  auto response = HttpResponse::newHttpJsonResponse(jsonBody);
  callback(response);
}

int main() {
  app()
      .loadConfigFile("../config.json")
      .registerHandler("/getValue", &importantHandler, {Get})
      .run();

  return EXIT_SUCCESS;
}

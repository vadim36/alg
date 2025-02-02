#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <windows.h>

/* Binary search:
 * Need Start point, End point, searching Item and array(vector)
 * Then you need to define area of searching in array
 * Complexity O(log n);
 * Return Item and Count of iterations
 */

std::tuple<int, int> binary_search(std::vector<int> &vec, int start, int end, int item) {
  std::cout << "Binary search started\n";
  int iterationsCount{ 0 };

  if (vec.size() == 0) {
    return std::make_tuple(iterationsCount, -1);
  }

  while (end >= start) {
    iterationsCount++;
    double mid{ std::ceil((end - start) / 2) + start };

    std::cout << "Iteration " << iterationsCount
      << " Start " << start
      << " End " << end
      << " Mid " << mid
      << " Item " << item << '\n';

    if (mid <= 0 || item < start || item > end) {
      return std::make_tuple(iterationsCount, -1);
    }

    if (vec[mid] == item) {
      return std::make_tuple(iterationsCount, mid);
    }

    if (item > vec[mid]) {
      start = mid;
      mid = std::ceil( (end - mid) / 2);
    }

    if (item < vec[mid]) {
      end = mid;
      mid = std::ceil( (mid - start) / 2);
    }
  }

  return std::make_tuple(iterationsCount, -1);
}

struct Test_Case {
  int index;
  int start;
  int end;
  int item;
};

const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

class Tests {
public:
  int root_test() {
    this->fill_test_vec();
    this->log_test_vec();
    this->run_tests();
    
    return EXIT_SUCCESS;
  }
private:
  std::vector<int> test_vec{};
  std::vector<Test_Case> test_cases{
    { 1, 0, 0, 7 },
    { 2, 3, 8, 5 },
    { 3, 2, 9, 1 },
    { 3, 2, 9, 2 },
    { 4, 0, 9, 5 },
    { 5, 0, 9, 123 }
  };
  void fill_test_vec() {
      for (int i{ 0 }; i < 10; i++)
          this->test_vec.push_back(i);
  };
  void log_test_vec() {
    std::cout << "Initial vector is ";
    for (int i : this->test_vec)
      std::cout << i << ' ';
    std::cout << '\n';
  };
  void run_tests() {
    for (Test_Case test_case : this->test_cases) {
      SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
      std::cout << "Test Case " << test_case.index << '\n';
      SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);

      std::tuple<int, int> result{ binary_search(this->test_vec, test_case.start, test_case.end, test_case.item) };
      std::cout << "End Iterations " << std::get<0>(result) << " Item " << std::get<1>(result) << std::endl;
    }
  }
};

int main() {
	Tests test = Tests();
	return test.root_test();
}
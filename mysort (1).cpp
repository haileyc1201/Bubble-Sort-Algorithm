#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
void bubble(int A[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (A[j] > A[j + 1]) {
        swap(A[j], A[j + 1]);
      }
    }
  }
}
int main(int argc, char *argv[]) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " inputfile outputfile" << endl;
    return 1;
  }
  ifstream infile(argv[1]);
  ofstream outfile(argv[2]);
  if (!infile) {
    cout << "Error opening the input file" << endl;
    return 1;
  }
  vector<int> numbers;
  int num;
  while (infile >> num) {
    numbers.push_back(num);
  }
  infile.close();
  int size = numbers.size();
  int *arr = &numbers[0];
  bubble(arr, size);
  for (int i = 0; i < size; i++) {
    outfile << arr[i] << endl;
  }
  outfile.close();
  return 0;
}
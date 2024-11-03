#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
  if (argc != 4) {
    cout << "Usage: " << argv[0] << "COUNT MIN MAX" << endl;
    return 1;
  }
  int count = atoi(argv[1]);
  int min = atoi(argv[2]);
  int max = atoi(argv[3]);
  ofstream outfile("numbers.dat");
  srand(time(0));
  for (int i = 0; i < count; i++) {
    int num = rand() % (max - min + 1) + min;
    outfile << num << endl;
  }
  outfile.close();
  return 0;
}
#include "Kruskal.cpp"
#include <fstream>
int main(int argc, char const *argv[]) {
  /* code */
  if (argc != 2)
  {
    std::cout << "file didn't load use like this " << '\n';
    std::cout << "./Skew_Heap data.txt" << '\n';
  }
  std::ifstream in(argv[1]);

  int value;
  in>>value; // cause I don't need the first value
  int** array;
  int num= 1;


  while(in>>value)
  {
    const int dummy = value;
    array = new int*[dummy];

    for (int i = 0; i < value; i++) {
      array[i]= new int[value];
      for (int j = 0; j < value; j++) {
          in>>array[i][j];
      }
    }
    std::cout << "Graph" <<num<< ":\n";
    Kruskal(array, value);
    Prim(array, value);
    num++;

  }

}

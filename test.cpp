#include "Kruskal.cpp"

#include <fstream>
#include "Timer.cpp"



int main(int argc, char const *argv[]) {
  /* code */
  std::cout << "hi" << std::endl;
  long* randomnums;
  Timer time1;
  double x;
  long y;
  int n= 1000;
  double Kruskal_time[8][7];
  double Prim_time[8][7];

  Kruskal_time[0][0]=n;

  Prim_time[0][0]=n;
  long** array;
  for(int i= 1; i<4; i++)
  {
    Kruskal_time[i][0]=Kruskal_time[i-1][0]*2;

    Prim_time[i][0]=Kruskal_time[i-1][0]*2;

  } // stores n values

  for( int i = 0; i<4; i++) // loop for n values
  {
     array = new long*[n];

    for (int j = 0; j < n; j++)
    {
      array[j]= new long[n];
    }
    std::cout << "next n" << std::endl;
    for (int key=0; key< 5; key++) // for the five keys
    {
      srand(key+2); // sets  random

      for (int j=0 ; j< n ; j++)
      {
        for (int k=0 ; k<= j ; k++)
        {
        if(j==k)
        {
          array[j][k]=0;
          array[k][j]=0;
        }
         x=(double)((rand() % (4*n) +1)/(4*n));
         if(x<0.5)
         {
           array[j][k]=0;
           array[k][j]=0;
         }else
         {
           y =(rand() % (4*n) +1);
           array[j][k]=y;
           array[k][j]=y;

         }
      }
      }

      time1.start();
      Kruskal(array, n);

      Kruskal_time[i][key +1]=time1.stop();

      time1.start();
      Prim(array, n);
      Prim_time[i][key +1]=time1.stop();

    n= n*2;
  }
}
      std::cout << "\n Kruskal_time: \n " << std::endl;
  for( int i = 0; i<4; i++) // loop for n values
  {

    for (int j=0 ; j< 7 ; j++)
    {
      if (j==6) {
        Kruskal_time[i][6]= Kruskal_time[i][6]/5;
      }
      if(j>0 && j!=6)
      {
        Kruskal_time[i][6]= Kruskal_time[i][6]+Kruskal_time[i][j];
      }
      std::cout << Kruskal_time[i][j] << " ";
    }
    std::cout << "\n";

  }
    std::cout << "\n Prim: \n " << std::endl;
  for( int i = 0; i<4; i++) // loop for n values
  {
    Prim_time[i][6]=0.0;

    for (int j=0 ; j< 7 ; j++)
    {
      if (j==6) {
        Prim_time[i][6]= Prim_time[i][6]/5;
      }
      if(j>0 && j!=6)
      {
        Prim_time[i][6]= Prim_time[i][6]+Prim_time[i][j];
      }
      std::cout << Prim_time[i][j] << " ";
    }
    std::cout << "\n";

  }

};

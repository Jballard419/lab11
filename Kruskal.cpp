#include <iostream>
#include "skew_heap.h"
struct edge_t {
  int x,y;
  long cost;
  bool operator <(const edge_t* x)
  {
    return this->cost<x->cost;
  };
  bool operator >(const edge_t* x)
  {
    return this->cost>x->cost;
  };
  edge_t(int x, int y, long c):x(x),y(y),cost(c){};
};

void Kruskal(long** cost, int x)
{
  //build Q
  Skew_Heap<edge_t*>* edges = new Skew_Heap<edge_t*>();
  edge_t* temp;
  edge_t* soln[x-1];
  bool notused[x];
  int Disjoint[x];
  int rootx, rooty;

  for (int i = 0; i < x; i++) {
    notused[i]= true;
    for (int j = 0; j < i; j++) {
      if(cost[i][j]!= 0)
      {
         temp= new  edge_t( j, i, cost[i][j]);
         edges->insert(temp);
      }
    }
  }
  int num_sel = 0;

  while(num_sel<(x-1) && !(edges->isempty()))
  {

    temp = edges->findmin();
    edges->deletemin();

    if(notused[temp->x]||notused[temp->y]) // add edge
    {
      if((notused[temp->x]&&notused[temp->y]))
      {
        Disjoint[temp->x]=-1;
        Disjoint[temp->y]=temp->x;
      }else if (notused[temp->x]) // y was taken
      {
        if(Disjoint[temp->y]==-1)
        {
          Disjoint[temp->x]=temp->y;
        }else
        {
          Disjoint[temp->x]=Disjoint[temp->y];
        }

      }else
      {
        if(Disjoint[temp->x]==-1)
        {
          Disjoint[temp->y]=temp->x;
        }else
        {
          Disjoint[temp->y]=Disjoint[temp->x];
        }
      }

      soln[num_sel] = temp;
      notused[temp->x]= false;
      notused[temp->y]= false;
      num_sel++;
    }else
    {
      rootx=temp->x;
      rooty=temp->y;

      while(Disjoint[rootx]!= -1)
      {
        rootx = Disjoint[rootx]; // the hunt for -1;
      }
      while(Disjoint[rooty]!= -1)
      {
        rooty = Disjoint[rooty]; // the hunt for -1;
      }

      if(rootx!= rooty) //disjointed
      {
        Disjoint[rooty]=rootx;
        soln[num_sel] = temp;
        num_sel++;
      }
    }

  }

 //  if (num_sel != (x-1))
 //    {
 //    std::cout << "Kruskal: no soln" << '\n';
 //    return;
 // }
 //
 //    std::cout << " \n Kruskal:";
 //    for(int i = 0; i<num_sel; i++)
 //    {
 //      std::cout << " <" << soln[i]->x <<","<<soln[i]->y<< "> ";
 //
 //    }
 //    std::cout <<  '\n';
 return;
}


void Prim(long** cost, int x)
{
  edge_t* temp;
  edge_t* soln[x-1];
  Skew_Heap<edge_t*>* edges = new Skew_Heap<edge_t*>();
  bool notused[x];
  for(int i= 0; i<x; i++)
  {
    notused[i]=true;
  }
  int num_sel = 0;
  int v= 0;
  do
  {
    notused[v]=false;
    for (int j = 0 ; j < x; j++)
    {
      if(notused[j]){
        if(cost[v][j]!= 0)
        {
            if(v<j)
            {
              temp= new  edge_t(v, j,cost[v][j]);
            }
            else
            {
              temp= new  edge_t( j, v,cost[v][j]); //
            }
           edges->insert(temp);
        }
      }
    }
    while(!(edges->isempty()))
    {
      temp = edges->findmin();
      edges->deletemin();

        if(notused[temp->x]||notused[temp->y]) // add edge
        {
          if (notused[temp->x])
          {
            v =temp->x;
          }else
          {
            v =temp->y;
          }
          soln[num_sel] = temp;
          notused[temp->x]= false;
          notused[temp->y]= false;
          num_sel++;
          break;
        }
      }


  }while(num_sel<(x-1) && !(edges->isempty()));
 //  if (num_sel != (x-1))
 //    {std::cout << "prim: no soln" << '\n';
 //    return;
 // }
 //    std::cout << " \n Prim:";
 //    for(int i = 0; i<num_sel; i++)
 //    {
 //      std::cout << " <" << soln[i]->x <<","<<soln[i]->y<< "> ";
 //
 //    }
 //    std::cout <<  '\n';
 return;
}

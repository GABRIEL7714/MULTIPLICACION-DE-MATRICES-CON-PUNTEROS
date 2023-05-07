#include <iostream>
using namespace std;
int A[3][3][3] = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
                   {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
                   {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};
int *p = *(*A);
int *q = *(*(A+1));
int *r = *(*(A+2));

int *fin_q = *(*(A+1)+2) + 2;
int *ini_r = *(*(A+2));
int *fin_r = *(*(A+2)) + 2;

void multiplicar(int (*A)[3][3])
{
  while(p<*(*(A+1)))
  {  
    int aux = (*p)*(*q);
    *r+=aux;
    if(q==fin_q)
    {
      p++;
      q = *(*(A+1));
      r++;
      ini_r = r;
      fin_r = r+2;
      continue;
    }
    if(r==fin_r)
    {
      r = ini_r;
      q++;
      p++;
      continue;
    }
    r++;
    q++;
  }
}
int main() {
  multiplicar(A);
  for(int (*a)[3]=*(A+2);a<*(A+2)+3;a++)
  {
    for(int *b=*a;b<*a+3;b++)
    {
      cout<<*b<<" ";
    }
    cout<<endl;
  }
  
  
}

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <stdio.h>
#include <math.h>
#define N 3
#include <conio.h>
//---------------------------------------------------------------------------
#pragma argsused

float f(float x[]);
void dgivs (int n, float x0[],float h0[], float eps_max, char choice);

int main(int argc, char* argv[])
{
int n=3;
char choice= 1;
float eps_max = 1e-4;
static float x0[3]={-0.5,1.,0.5};
static float h0[3]={-1.,1.,2.};

dgivs(n, x0,h0,eps_max, choice);
choice =2;
dgivs(n,x0,h0,eps_max,choice);
        getch();
        return 0;  
}
//---------------------------------------------------------------------------
void dgivs(int n, float x0[], float h0[], float eps_max, char choice)
{
float xb[N], x[N], h[N], fb,fi, fr, xr[N], eps, beta, gamma, d[N];
char flag;
int i;
        if (n>N)
          {
          printf("Macroopredelenie N doljno bit ne menee %d\n",n);
          exit(1);
          }
beta = 0.5; gamma=2;
for (i=0,eps=0; i<n; i++)
  {
   xb[i]=x0[i]; h[i]=h0[i]; eps+=h[i]*h[i];
  }
fb=f(xb);
eps= sqrt(eps);
while (eps>=eps_max)
  {
   flag=0;
   for(i=0; i<n; i++) x[i]=xb[i];

   //построение образа
   for (i=0; i<n; i++)
     {
      x[i]=xb[i]+h[i]; fi=f(x);
        if(fi<fb) flag=1;
        else
          {
          x[i]=xb[i]-h[i]; fi=f(x);
          if (fi<fb) flag =1;
          else  x[i]=xb[i];
          }

     }
   if (flag==0)
     {
      for (i=0, eps=0; i<n; i++)
        {
        h[i]*=beta; eps+=h[i]*h[i];
        }
      eps = sqrt(eps); continue;
     }
  for (i=0; i<n;i++)
   {
   d[i]=x[i]-xb[i]; xr[i]=xb[i]+gamma*d[i];
   xb[i]=x[i];
   }
   fr = f(xr); fb=f(xb);
      while (fr<=fb)
        {
         for (i=0; i<n; i++)
           {
            xb[i]=xr[i]; xr[i]=xb[i]+gamma* d[i];
           }
        fb  = fr; fr= f(x);
          if(choice==1)
             break;
        }

  }
printf("Optimalnie parametri: \n");
 for (i=0; i<n; i++)
   printf("x[%d]=%f\n",i,xb[i]);
 printf("Minimum celevoy funccii: %f\n", fb);
}

//целевая функция

float f(float x[])
 {
///////Сюда вводим свою целевую функцию////////////////////////////////////////////////////////////////////////////
 return (x[0]-x[1]+x[2])*(x[0]-x[1]+x[2])+(-x[0]+x[1]+x[2])*(-x[0]+x[1]+x[2])+(x[0]+x[1]-x[2])*(x[0]+x[1]-x[2]); //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 }
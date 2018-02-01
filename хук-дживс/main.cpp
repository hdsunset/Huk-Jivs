#include <iostream>
#include <vector>
using namespace std;

float f(vector<float> x){
    return(x[0]*x[0]*x[0]+13.5*x[0]*x[0]-66*x[0]+(5*x[0]-x[1])*(5*x[0]-x[1]));
}

float f_delta(vector<float> x,float delta,int n){
    x[n]=x[n]+delta;
    return f(x);
}

vector<float> sum(vector<float>x1,vector<float>x2,int n){
    for (int i=0;i<n;i++)
        x1[i]=x1[i]+x2[i];
    return x1;
}

vector<float> dif(vector<float>x1,vector<float>x2,int n){
    for (int i=0;i<n;i++)
        x1[i]=x1[i]-x2[i];
    return x1;
}

vector<float> mul(vector<float>x,float k,int n){
    for(int i=0;i<n;i++)
        x[i]=x[i]*k;
    return x;
}

void print(vector<float>x,int n){
    for(int i=0;i<n;i++)
        cout<<'x'<<i+1<<'='<<x[i]<<endl;
}

int main()
{
    float e,delta,delta1,k;
    int m=1;
    vector <float> x0(2),x1(2),x2(2),x3(2);

    cout<<"Enter x1"<<endl;
    cin>>x0[0];
    cout<<"Enter x2"<<endl;
    cin>>x0[1];
    cout<<"Enter accuracy"<<endl;
    cin>>e;
    cout<<"Enter delta"<<endl;
    cin>>delta;
    k=1;

    do{
        delta1=delta;
        do{
            x1=x0;
            for(int i=0;i<2;i++){
                if(f_delta(x1,delta,i)<f(x1))
                    x1[i]=x1[i]+delta;
                else
                    if(f_delta(x1,-delta,i)<f(x1))
                        x1[i]=x1[i]-delta;
            }

            if (x1==x0)
                delta=delta/2;
        }
        while((x1==x0)&&(delta>=e));

        x2=x0;
        x3=x1;

        while(f(x3)<f(x2)){
            x2=x3;
            x3=sum(x2,mul(dif(x1,x0,2),k,2),2);
        }

        x0=x2;
        cout<<"i="<<m<<endl;
        cout<<"x="<<x2[0]<<' '<<x2[1]<<endl;
        cout<<"delta="<<delta1<<endl;
        m++;
    }
    while(delta1>e);

    cout<<endl;
    print(x0,2);

    return 0;
}

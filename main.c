#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float y_0=1;
float abv(float v){
if(v>=0)return v;
else return (-1)*v;
}


float rozw1(float t){

return exp(t);
}
float rozw2(float t){

return exp(-t);
}
float rozw3(float t){

return t-1 +2*exp(-t);
}
float fun1(float y,float t){
return y;
}
float fun2(float y,float t){
return -y;
}
float fun3(float y,float t){
return -y+t;
}
void euler(float fun(float aa,float bb) ,float tabt_k[],float taby_k[],float h){

float y_k;
float y_k1;
float t_k;
int N = (int)10/h+2;

y_k=y_0;
t_k=0;
tabt_k[0]=t_k;
taby_k[0]=y_k;
int k;
for(k=1;k<=N+1;++k){
    y_k+=h*(fun(y_k,t_k));

    t_k+=h;
    tabt_k[k]=t_k;
    taby_k[k]=y_k;
}

}

void RK2(float fun(float aa,float bb) ,float tabt_k[],float taby_k[],float h){

float y_k;

float t_k;
int N = (int)10/h+2;

y_k=y_0;
t_k=0;
tabt_k[0]=t_k;
taby_k[0]=y_k;
int k;
float k1=h*(fun(y_k,t_k));
float k2=h*(fun(y_k +k1,t_k+h));

for(k=1;k<=N+1;++k){
    y_k+=(0.5)*(k1+k2);

    t_k+=h;
    //printf("%3d %e  %e\n",k,y_k,fun(t_k,y_k));
     k1=h*(fun(y_k,t_k));
 k2=h*(fun(y_k+k1,t_k+h));

    tabt_k[k]=t_k;
    taby_k[k]=y_k;
}

}

void RK4(float fun(float aa,float bb) ,float tabt_k[],float taby_k[],float h){

float y_k;

float t_k;
int N = (int)10/h+2;

y_k=y_0;
t_k=0;
tabt_k[0]=t_k;
taby_k[0]=y_k;
int k;
float k1=h*fun(y_k,t_k);
float k2=h*fun(y_k+k1/2,t_k+h/2);
float k3=h*fun(y_k+k2/2,t_k+h/2);
float k4=h*fun(y_k+k3,t_k+h);

for(k=1;k<=N+1;++k){
    y_k+=(k1+2*k2+2*k3+k4)/6;


    t_k+=h;
    //printf("%3d %.8f  %.8f\n",k,y_k,fun(t_k,y_k));
    k1=h*fun(y_k,t_k);
 k2=h*fun(y_k+k1/2,t_k+h/2);
k3=h*fun(y_k+k2/2,t_k+h/2);
 k4=h*fun(y_k+k3,t_k+h);
    tabt_k[k]=t_k;
    taby_k[k]=y_k;
}

}

int main()
{
    //FILE *fp;
    //fp=fopen("wyniki.txt", "a+");
    //fprintf(fp, "Metoda RK4: \n");
//fprintf(fp, "\n");
//fprintf(fp, "dla h = %f  blad = %.8f  \n",h,diff);

    int k;
float t_k=0;

    float h;
    int f;
    int m;
    printf("Podaj h : ");
    scanf("%f",&h);
int N=(int) 10/h+2;
float tabt_k[N];float taby_k[N];
    printf("Wybierz metode  wpisz 1 dla euler, 2 dla RK2, 3 dla RK4 : ");
    scanf("%d",&m);

    printf("Wybierz funkcje wpisz 1 dla f(t,y)=y, 2 dla f(t,y)=-y, 3 dla f(t,y)=-y+t: ");
    scanf("%d",&f);

if((f!=1 &&f!=2 &&f!=3) || (m!=1 &&m!=2 &&m!=3)) {
        printf("\nzly input KONIEC PROGRAMU\n");

        exit(0);
}
    printf("  k:      czas:        aproksymacja y       scisle y          blad\n");


    if(m==1) {
            if(f==1) euler(fun1,tabt_k,taby_k,h);
            if(f==2) euler(fun2,tabt_k,taby_k,h);
            if(f==3) euler(fun3,tabt_k,taby_k,h);
            }
    if(m==2) {
            if(f==1) RK2(fun1,tabt_k,taby_k,h);
            if(f==2) RK2(fun2,tabt_k,taby_k,h);
            if(f==3) RK2(fun3,tabt_k,taby_k,h);
            }
    if(m==3) {
            if(f==1) RK4(fun1,tabt_k,taby_k,h);
            if(f==2) RK4(fun2,tabt_k,taby_k,h);
            if(f==3) RK4(fun3,tabt_k,taby_k,h);
            }

if(f==1){

float diff=abv(taby_k[0]-rozw1(0));
            for(k=0;k<N;++k){

    printf("%4d  %12.8f  %15.8f  %15.8f  %15.8f\n",k,tabt_k[k],taby_k[k],rozw1(tabt_k[k]),abv(taby_k[k]-rozw1(tabt_k[k])));

    if(abv(taby_k[k]-rozw1(tabt_k[k]))>diff) diff=abv(taby_k[k]-rozw1(tabt_k[k]));
t_k+=h;
}
printf("\nmax diff : %.8f\n",diff);

}
if(f==2){

float diff=abv(taby_k[0]-rozw2(0));
            for(k=0;k<N;++k){

    printf("%4d  %12.8f  %15.8f  %15.8f  %15.8f\n",k,tabt_k[k],taby_k[k],rozw2(tabt_k[k]),abv(taby_k[k]-rozw2(tabt_k[k])));

    if(abv(taby_k[k]-rozw2(tabt_k[k]))>diff) diff=abv(taby_k[k]-rozw2(tabt_k[k]));
t_k+=h;
}
printf("\nmax diff : %.8f\n",diff);

}
if(f==3){

float diff=abv(taby_k[0]-rozw3(0));
            for(k=0;k<N;++k){

    printf("%4d  %12.8f  %15.8f  %15.8f  %15.8f\n",k,tabt_k[k],taby_k[k],rozw3(tabt_k[k]),abv(taby_k[k]-rozw3(tabt_k[k])));

    if(abv(taby_k[k]-rozw3(tabt_k[k]))>diff) diff=abv(taby_k[k]-rozw3(tabt_k[k]));
t_k+=h;
}
printf("\nmax diff : %.8f\n",diff);

}

    return 0;
}

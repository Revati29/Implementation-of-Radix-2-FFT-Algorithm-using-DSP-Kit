#include<math.h>
#include<stdio.h>
void fft(int n,int m,double x[],double y[])
{
int i,j,k,n1,n2;
double c,s,e,a,t1,t2;
j = 0;
n2 = n/2;
for (i=1; i < n - 1; i++)
{
 n1 = n2;
 while ( j >= n1 )
 {
j = j - n1;
 n1 = n1/2;
}
j = j + n1;
if (i < j)
 {
 t1 = x[i];
 x[i] = x[j];
 x[j] = t1;
 t1 = y[i];
 y[i] = y[j];
 y[j] = t1;
 } }
n1 = 0; /* FFT */
n2 = 1;
for (i=0; i < m; i++)
{
 n1 = n2;
 n2 = n2 + n2;
 e = -6.283185307179586/n2;
 a = 0.0;
for (j=0; j < n1; j++)
 {
 c = cos(a);
 s = sin(a);
 a = a + e;
for (k=j; k < n; k=k+n2)
 {
 t1 = c*x[k+n1] - s*y[k+n1];
 t2 = s*x[k+n1] + c*y[k+n1];
 x[k+n1] = x[k] - t1;
 y[k+n1] = y[k] - t2;
 x[k] = x[k] + t1;
 y[k] = y[k] + t2;
 }
 } }
return;
}
int main()
{
 int n,m;
 printf("Enter Length of FFT : ");
 scanf("%d",&n);
 double x[n],y[n];
 m=log2(n);
 printf("Enter Real Part : ");
 for (int i=0;i<n;i++) {
 scanf("%lf",&x[i]);
 }
 printf("Enter Imaginary Part : ");
 for (int i=0; i<n;i++){
 scanf("%lf",&y[i]);
 }
 fft(n,m,x,y);
 printf("Output : ");
 for (int i=0;i<n;i++){
 if(y[i]>=0){
 printf("%.3lf +%.3lf j, ",x[i],y[i]);
}
 else
 {
 printf("%.3lf %.3lf j, ", x[i],y[i]);
 }
 }
 return 0;
}













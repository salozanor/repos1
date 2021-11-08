#include<iostream>
#include<cmath>

double fun (double x)
{
  double f=2*x*sin(x);
  return f;
}

double trap (double n,double a, double b, double d)//suma con la regla de trapecios
{
  double s=0;//sumatoria
  double v=0;//minimo del intervalo
  double vv=0;//maximo del intervalo
  double r=0;
  for(int ii=0;ii<n;ii++)
    {
      double i=0;
      if(ii==0){
	i=ii;
      }
      else {
	i=ii-1;}
      v=(a+(i*d));
      vv=(a+(ii*d));
      double f= fun(v);
      double ff= fun (vv);
      s=d*((f+ff)/2);
      r=r+s;
    }
      
     
  return r;
}

double simp (int n,double a, double b, double d)
{
  double r=0;
  double s=0;
  if(n%2==0){}
  else{n=n+1;}
  for(int ii=0;ii<(n+1);ii++)
    {
      double v=a+(ii*d);
      if((ii==0)||(ii==n)){
	double f= fun(v);
	s=s+(f);
      }
      if((ii%2==0)&&(ii>0)&&(ii<n)){
	double f=2*fun(v);
	s=s+(f);
      }
      else{
	if((ii>0)&&(ii<n)){
	  double f=4*fun(v);
	  s=s+(f);
	}
      }
    }
  r=(d/3)*s;
  return r;
}

int main (void)
{
  double a=0;
  double b=4;
  double m=1.25;
  int n=10;
  int nn=1000;
  double d=(b-a)/n;
  double dd=(b-a)/nn;
  double intt= trap (n,a,b,d);//integral de trapecios
  double inttt= trap (nn,a,b,dd);
  double ints= simp (n,a,b,d);//integral de simpson
  double intss= simp (nn,a,b,dd);
  double intr= ((-2)*b*cos(b))+(2*sin(b));//integral real
  double velr= sqrt(2*intr/m);//velfin
  double velt= sqrt(2*intt/m);
  double veltt= sqrt(2*inttt/m);
  double vels= sqrt(2*ints/m);
  double velss= sqrt(2*intss/m);
  double dift= ((velr-velt)/velr)*100;
  double diftt= ((velr-veltt)/velr)*100;
  double difs= ((velr-vels)/velr)*100;
  double difss= ((velr-velss)/velr)*100;//da nan porque es muy pequeño
  std::cout<<n<<"\t"<<dift<<"\t"<<difs<<std::endl;
  std::cout<<nn<<"\t"<<diftt<<"\t"<<difss<<std::endl;
  return 0;
}

  

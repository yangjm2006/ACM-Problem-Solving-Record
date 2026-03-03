#pragma once

#include<stdio.h>
#include<math.h>
#include<stdbool.h>

typedef struct ComplexTag{
    double real,imag;
}Complex;

Complex complex_add(Complex* x ,Complex* y){
    return (Complex){x->real+y->real,x->imag+y->imag};
}

Complex complex_mul(Complex* x ,Complex* y){
    return (Complex){x->real*y->real-x->imag*y->imag,x->real*y->imag+x->imag*y->real};
}


bool is_zero(double x,double eps){
    if(fabs(x)<=eps) return 1;
    return 0;
}

bool is_eq(double x,double y,double eps){
    if(fabs(x-y)<=eps) return 1;
    return 0;
}

void complex_print(Complex* p,double eps){
    if(is_zero(p->imag,eps)) printf("%.4lf",p->real);
    else if(p->imag>0) printf("%.4lf+%.4lfi",p->real,p->imag);
    else printf("%.4lf%.4lfi",p->real,p->imag);
}

int solve_quadratic(double a,double b,double c,Complex* r1,Complex* r2,double eps){
    bool f=0;
    if(b*b-4*a*c<0) f=1;
    double d;
    if(f) d=sqrt(-b*b+4*a*c)/2/a;
    else d=sqrt(b*b-4*a*c)/2/a;
    int tmp;
    r1->real=r1->imag=r2->real=r2->imag=0;
    if(is_zero(d,eps)){
        tmp=1;
        r1->real=-b/2/a;
    }else{
        if(f){
            r1->real=r2->real=-b/2/a;
            if(d>0){
                r1->imag=-d;
                r2->imag=d;
            }
            else{
                r1->imag=d;
                r2->imag=-d;
            }
            tmp=-2;
        }else{
            r1->real=-b/2/a;
            r2->real=-b/2/a;
            if(d>0){
                r1->real-=d;
                r2->real+=d;
            }else{
                r1->real+=d;
                r2->real-=d;
            }
            tmp=2;
        }
    }
    return tmp;
}
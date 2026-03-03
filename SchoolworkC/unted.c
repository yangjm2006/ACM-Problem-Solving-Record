#pragma once

#include<math.h>
#include<stdlib.h>

typedef struct vec3_tag{
    double x,y,z;
}vec3;

vec3* vec3_new(){
    vec3* v=(vec3*)malloc(sizeof(vec3));
    *v=(vec3){0,0,0};
    return v;
}

void vec3_delete(vec3* v){
    free(v);
}

double vec3_x(const vec3* v){
    return v->x;
}

double vec3_y(const vec3* v){
    return v->y;
}

double vec3_z(const vec3* v){
    return v->z;
}

void vec3_set_x(vec3* v,double x){
     v->x=x;
}

void vec3_set_y(vec3* v,double x){
     v->y=x;
}

void vec3_set_z(vec3* v,double x){
     v->z=x;
}

vec3* vec3_let(double x,double y,double z){
    vec3* v=(vec3*)malloc(sizeof(vec3));
    *v=(vec3){x,y,z};
    return v;
}

double vec3_get(vec3* v,int id){
    if(id==0) return v->x;
    if(id==1) return v->y;
    return v->z;
}

void vec3_set(vec3* v,double x,double y,double z){
    *v=(vec3){x,y,z};
}

vec3* vec3_zero(){
    static vec3 v={0,0,0};
    return &v;
}

void fswap(double* x,double *y){
    double z=*x;
    *x=*y;
    *y=z;
}

void vec3_swap(vec3* a,vec3* b){
    fswap(&(a->x),&(b->x));fswap(&(a->y),&(b->y));fswap(&(a->z),&(b->z));
}

vec3* vec3_copy(const vec3* v){
    vec3* vn=(vec3*)malloc(sizeof(v));
    *vn=*v;
    return vn;
}

void vec3_assign(vec3* a,vec3* b){
    *a=*b;
}

int is_zero(double x,double eps){
    return fabs(x)<=eps;
}

int is_eq(double x,double y,double eps){
    return fabs(x-y)<=eps;
}

void vec3_add(vec3* a,const vec3* b,const vec3* c){
    a->x=b->x+c->x;a->y=b->y+c->y;a->z=b->z+c->z;
}

void vec3_mul(vec3* a,const vec3* b,double c){
    a->x=b->x*c;a->y=b->y*c;a->z=b->z*c;
}

double vec3_dot(const vec3* a,const vec3* b){
    return a->x*b->x+a->y*b->y+a->z*b->z;
}

vec3* vec3_cross(vec3* a,const vec3* b,const vec3* c){
    *a=(vec3){b->y*c->z-b->z*c->y,b->z*c->x-b->x*c->z,b->x*c->y-b->y*c->x};
}

double vec3_length(const vec3* v){
    return sqrt(vec3_dot(v,v));
}
#include<stdlib.h>
struct vec3_tag{
    double x,y,z;
};
typedef struct vec3_tag vec3;
vec3* vec3_new(){
    vec3* v=(vec3*)malloc(sizeof(vec3));
    *v=(vec3){0,0,0};
    return v;
}
void vec3_delete(vec3* v){
    free(v);
}
double vec3_x(vec3* v){
    return v->x;
}
double vec3_y(vec3* v){
    return v->y;
}
double vec3_z(vec3* v){
    return v->z;
}
void vec3_set_x(vec3* v,double val){
    v->x=val;
}
void vec3_set_y(vec3* v,double val){
    v->y=val;
}
void vec3_set_z(vec3* v,double val){
    v->z=val;
}
void vec3_let(double xx,double yy,double zz){
    vec3* v=(vec3*)malloc(sizeof(vec3));
    v->x=xx;v->y=yy;v->z=zz;
}
double vec3_get(vec3* v,int id){
    if(id==1) return v->x;
    if(id==2) return v->y;
    return v->z;
}
vec3* vec3_zero(){
    static vec3 O={0,0,0};
    return &O;
}
void swapf(double* a,double* b){
    double x=*a;
    *a=*b;
    *b=x;
}
void vec3_swap(vec3* v1,vec3* v2){
    swapf(&(v1->x),&(v2->x));swapf(&(v1->y),&(v2->y));swapf(&(v1->z),&(v2->z));
}
vec3* vec3_copy(vec3* v){
    vec3* vnw=(vec3*)malloc(sizeof(vec3));
    *vnw=*v;
    return vnw;
}
void vec3_assign(vec3* v1,vec3* v2){
    *v1=*v2;
}
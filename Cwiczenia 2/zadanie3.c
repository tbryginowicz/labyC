#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int x;
    int y;
}Point;

typedef struct{
    int a;
    int b;
}Rectangle;

int area(Rectangle *r);

void changeCoords(Point *p, int x1, int y1);

int main() {
    Point p;
    p.x = 5;
    p.y = 5;
    Point *pp = &p;
    changeCoords(pp, 15,15);
    printf("x: %i\ny: %i",p.x,p.y);
    
    printf("\n");

    Rectangle r;
    Rectangle *pr = &r;
    r.a = 22;
    r.b = 3;
    printf("Pole: %i",area(pr));
    return 0;
}

void changeCoords(Point *p, int x1, int y1){
    p->x = x1;
    p->y = y1;
}

int area(Rectangle *r){
    return r->a * r->b;
}
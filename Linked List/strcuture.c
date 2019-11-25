#include <stdio.h>

struct {
    char name[10];
    double distance;
}one_planet;

typedef int Bool;

int main(){
    one_planet.distance = 10.0;
    Bool x = 100;

    printf("%d\n", x);

    printf("%lf\n", one_planet.distance);
    return 0;
}

#include "stdio.h"
#include "math.h"

struct point {
    int x_coord;
    int y_coord;
};



int x_coordinate(struct point a){
        return a.x_coord;
    }

int y_coordinate(struct point a){
        return a.y_coord;
    }

void print_point(struct point a){
        printf("(%d,%d)", a.x_coord, a.y_coord);
    }

struct point closest_to_x(struct point points[], int n){
    struct point closest = points[0];
    for (int i = 1;i < n; i++){
        if (y_coordinate (points[i])<y_coordinate(closest))
        {
            closest = points[i];
        }
        
    }
    printf("(%d,%d)", x_coordinate(closest),y_coordinate(closest));
};

double distance(struct point a, struct point b){
    double x_distance = abs(a.x_coord - b.x_coord);
    double y_distance = abs(a.y_coord - b.y_coord);
    if (x_distance == 0){
        return y_distance;}
    else if (y_distance == 0){
        return x_distance;}
    else {
        return sqrt(x_distance * x_distance + y_distance * y_distance);}
}


double width(struct point points[], int n){
    double max_distance = distance(points[0], points[1]);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (j + 1 < n && distance(points[i], points[j]) < distance(points[i], points[j + 1])) {
                max_distance = distance(points[i], points[j + 1]);
            }
        }
    }
    return max_distance;
}
#include <vector>

class Point {
    public:
        double x;
        double y;
        void init(double init_x, double init_y){
            x = init_x;
            y = init_y;
        }
        void set(Point p){
            x = p.x;
            y = p.y;
        }
};

#ifndef RANDOMIZEDFITTING_H
#define RANDOMIZEDFITTING_H

class RandomizedFitting {
    public:
        void fit(std::vector<Point> p_list);
};

#endif

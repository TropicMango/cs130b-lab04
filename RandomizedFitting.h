#include <vector>

class Point {
    public:
        float x;
        float y;
        void init(float init_x, float init_y){
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

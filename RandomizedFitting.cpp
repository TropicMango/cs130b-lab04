#include "RandomizedFitting.h"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
#include <cmath>
#include <iomanip>
using namespace std;

float DistFromLine(Point p1, Point p2, Point t){
    float numerator = abs((p2.y-p1.y)*t.x - (p2.x-p1.x)*t.y + p2.x*p1.y - p2.y*p1.x);
    float denominator = pow((p2.y-p1.y)*(p2.y-p1.y) + (p2.x-p1.x)*(p2.x-p1.x), 0.5);
    return numerator/denominator;
}

void RandomizedFitting::fit(vector<Point> p_list){
    srand(time(0));
    float min_error = -1;
    Point min_p1, min_p2;
    int num_points = p_list.size();
    for(int i=0; i<max(10000, num_points); i++){
        // generate two random unique index
        int index_1 = rand() % num_points;
        int index_2 = rand() % num_points;
        while(index_1 == index_2)
            index_2 = rand() % num_points;

        Point p1 = p_list[index_1];
        Point p2 = p_list[index_2];

        // cout << "set " << i << endl;
        // cout << "index 1: " << index_1 << ", x: " << p1.x << " y: " << p1.y << endl;
        // cout << "index 2: " << index_2 << ", x: " << p2.x << " y: " << p2.y << endl;

        // calculating median error
        float error[num_points];
        for(int j=0; j<num_points; j++){
            if(j==index_1 || j==index_2)
                continue;
            error[j] = DistFromLine(p1, p2, p_list[j]);
        }
        sort(error, error + num_points);
        float median_error = error[(int)(num_points/2)];
        
        // store median and points 
        if(median_error < min_error || min_error == -1){
            min_error = median_error;
            min_p1.set(p1);
            min_p2.set(p2);
        }
    }

    // cout << "min 1: " << min_p1.x << ", " << min_p1.y << " min 2: " << min_p2.x << ", " << min_p2.y << endl;
    // cout << "error: " << min_error << endl;
    // float m = (min_p2.y-min_p1.y) / (min_p2.x-min_p1.x);
    // float b = min_p1.y - m*min_p1.x;
    
    float sum_x=0, sum_y=0, sum_xy=0, sum_xx=0, num_fit=0;
    // finding the points to perform regression
    for(int i=0; i<num_points; i++){
        Point p_temp = p_list[i];
        if(DistFromLine(min_p1, min_p2, p_temp) < min_error){
            sum_x += p_temp.x;
            sum_y += p_temp.y;
            sum_xy += p_temp.x * p_temp.y;
            sum_xx += p_temp.x * p_temp.x;
            num_fit ++;
        }
    }

    float a = (num_fit * sum_xy - sum_x * sum_y) / (num_fit * sum_xx - sum_x * sum_x);
    float b = (sum_y - a * sum_x) / num_fit;

    cout << fixed;
    cout << setprecision(5);
    cout << a << " " << b << endl;
}

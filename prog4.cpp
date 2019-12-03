#include "RandomizedFitting.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    // cout << "Enter Points: " << endl;
    
    vector<Point> p_list;
    string l;
    while(getline(cin, l)){
        if(l == ""){break;}
        Point temp;
        int index = l.find(" ");
        if(index == string::npos)
            index = l.find("\t");
        temp.init(stof(l.substr(0, index)), stof(l.substr(index+1)));
        p_list.push_back(temp);
    }

    RandomizedFitting rf;
    rf.fit(p_list);
}


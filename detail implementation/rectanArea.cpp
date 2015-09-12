/* Copyright 2015 Edmund Liu

Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure: "rectangle_area.png".

Assume that the total area is never beyond the maximum possible value of int.

*/

#include <iostream>
#include <algorithm>
using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    if (C <= E || G <= A) return (C-A)*(D-B) + (G-E)*(H-F);
    if (D <= F || H <= B) return (C-A)*(D-B) + (G-E)*(H-F);
    int x = min(min(abs(A-G), abs(C-E)), min(C-A, G-E));
    int y = min(min(abs(B-H), abs(D-F)), min(D-B, H-F));
    return (C-A)*(D-B) + (G-E)*(H-F) - x*y;
}

int main() {
    cout << computeArea(-3,0,3,4,0,-1,9,2) << endl;
    cout << computeArea(0,0,0,0,-1,-1,1,1) << endl;
    cout << computeArea(-2,-2,2,2,1,-3,3,3);
    return 0;
}

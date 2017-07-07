/* UVa problem: 10065
 *
 * Topic: Geometry
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Given an input of points, compute the percentage difference between teh minumum boundning box and the area of the polynomial made by the points
 *
 * Solution Summary:
 *
 *   compute area of polygon, compute minum bounding box area, take ratio
 *
 * Used Resources:
 *
 *   code from Competitive Programming on minumum bounding boxes, and code from code archive on area of polygon.
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 * Dylan Hyatt-Denesik
 * --------------------- (Your Name)
 */


#include <complex>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// stuff from code base

struct point 
{ 
    point(){}
    point(int x_, int y_)
        :x(x_),y(y_)
    {}
    int x, y;
}; // a point has two members

//typedef complex<double> point;


double cross(const point &a, const point &b) {
    return a.x*b.y - a.y*b.x;
    //return imag(conj(a)*b);
}

double area_poly(const vector<point> &p){
    double sum = 0;

    for(int i = p.size()-1, j = 0; j < p.size(); i = j++)
        sum += cross(p[i], p[j]);

    return sum/2.0;
}

//stuff from text

int turn(point p, point q, point r) 
{
    int result = (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
    if (result < 0) return -1; // P->Q->R is a right turn
    if (result > 0) return 1; // P->Q->R is a left turn
    return 0; // P->Q->R is a straight line, i.e. P, Q, R are collinear
}
// Note: sometimes, we change the ’> 0’ to ’>= 0’ to accept collinear points
bool ccw(point p, point q, point r) 
{ 
    return (turn(p, q, r) > 0); 
}

point pivot; // global variable
vector<point> polygon, CH;

int area2(point a, point b, point c) 
{
    return a.x * b.y - a.y * b.x + b.x * c.y - b.y * c.x + c.x * a.y - c.y * a.x;
}

 // function to compute distance between 2 points
int dist2(point a, point b) 
{
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

// important angle-sorting function
bool angle_cmp(point a, point b) 
{ 
    if (area2(pivot, a, b) == 0) // collinear
        return dist2(pivot, a) < dist2(pivot, b); // which one closer

    int d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    int d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2((double)d1y, (double)d1x) - atan2((double)d2y, (double)d2x)) < 0;
}

// first, find P0 = point with lowest Y and if tie: rightmost X
vector<point> GrahamScan(vector<point> Polygon) 
{
    int i, P0 = 0, N = Polygon.size();
    for (i = 1; i < N; i++)
        if (Polygon[i].y < Polygon[P0].y ||
        (Polygon[i].y == Polygon[P0].y && Polygon[i].x > Polygon[P0].x))
            P0 = i;

    point temp = Polygon[0]; // swap selected vertex with Polygon[0]
    Polygon[0] = Polygon[P0];
    Polygon[P0] = temp;
    // second, sort points by angle w.r.t. P0, skipping Polygon [0]
    pivot = Polygon[0]; // use this global variable as reference
    sort(++Polygon.begin(), Polygon.end(), angle_cmp);
    // third, the ccw tests
    stack<point> S;
    point prev, now;
    S.push(Polygon[N - 1]); // put two starting vertices into stack S
    S.push(Polygon[0]);
    i = 1; // and start checking the rest

    while (i < N) 
    { // note: N must be >= 3 for this method to work
        now = S.top();
        S.pop(); prev = S.top(); S.push(now); // trick to get the 2nd item from top of S

        if (ccw(prev, now, Polygon[i])) 
        { // if these 3 points make a left turn
            S.push(Polygon[i]); // accept
            i++;
        }
        else // otherwise
            S.pop(); // pop this point until we have a left turn
    }

    vector<point> ConvexHull;

    while (!S.empty()) 
    { // from stack back to vector
        ConvexHull.push_back(S.top());
        S.pop();
    }
    ConvexHull.pop_back(); // the last one is a duplicate of first one
    return ConvexHull; // return the result
}


int main(){
    vector<point> poly;
    int i, n, tile = 1;

    while(cin >> n, n > 0)
    {
        poly.resize(n);
        
        for(i = 0; i < n; i++)
        {
            double x, y;
            cin >> x >> y;
            poly[i] = point(x, y);
        }
       //cout << "Signed Area = "<< area_poly(poly) << endl;
       //cout << "Graham scan area = " << abs(area_poly(GrahamScan(poly))) << endl;
       cout << "Tile #" << tile << endl;
       tile++;
       printf("Wasted Space = %.2f %%\n\n",(1 - abs(area_poly(poly))/abs(area_poly(GrahamScan(poly))))*100);
    }
    return 0;
}
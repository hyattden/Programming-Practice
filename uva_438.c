/* UVa problem: 438
 *
 * Topic: Geometry
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Given sequence of colinear points, deterimine circumference of induced circle
 *
 * Solution Summary:
 *
 *   Use code form code archive to solve problem
 *
 * Used Resources:
 *
 *   Code-Archive/2d_geometry/circ_3pts.c
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 * Dylan Hyatt-Denesik
 * --------------------- (Your Name)
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* how close to call equal */
#define EPS 1E-8

typedef struct {
  double x, y;
} Point;

int circle(Point p1, Point p2, Point p3, Point *center, double *r)
{
  double a,b,c,d,e,f,g;

  a = p2.x - p1.x;  b = p2.y - p1.y;
  c = p3.x - p1.x;  d = p3.y - p1.y;
  e = a*(p1.x + p2.x) + b*(p1.y + p2.y);
  f = c*(p1.x + p3.x) + d*(p1.y + p3.y);
  g = 2.0*(a*(p3.y - p2.y) - b*(p3.x - p2.x));
  if (fabs(g) < EPS) return 0;
  center->x = (d*e - b*f) / g;
  center->y = (a*f - c*e) / g;
  *r = sqrt((p1.x-center->x)*(p1.x-center->x) +
	    (p1.y-center->y)*(p1.y-center->y));
  return 1;
}

int main(void)
{
  Point a, b, c, center;
  double r;
  
  while (scanf("%lf %lf %lf %lf %lf %lf", 
	       &a.x, &a.y, &b.x, &b.y, &c.x, &c.y) == 6) {
    if (circle(a, b, c, &center, &r)) {
      printf("%.2f\n", r*2*3.1415926535);
    } else {
      printf("colinear\n\n");
    }
  }
  return 0;
}

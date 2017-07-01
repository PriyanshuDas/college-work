// A C++ program to find convex hull of a set of points. Refer
// http://www.geeksforgeeks.org/orientation-3-ordered-points/
// for explanation of orientation()
#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

// Prints convex hull of a set of n points.
vector <Point> convexHull(Point points[], int n)
{
    // There must be at least 3 points

    // Initialize Result
    vector<Point> hull;

    // Find the leftmost point
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

    // Start from leftmost point, keep moving counterclockwise
    // until reach the start point again.  This loop runs O(h)
    // times where h is number of points in result or output.
    int p = l, q;
    do
    {
        // Add current point to result
        hull.push_back(points[p]);

        // Search for a point 'q' such that orientation(p, x,
        // q) is counterclockwise for all points 'x'. The idea
        // is to keep track of last visited most counterclock-
        // wise point in q. If any point 'i' is more counterclock-
        // wise than q, then update q.
        q = (p+1)%n;
        for (int i = 0; i < n; i++)
        {
           // If i is more counterclockwise than current q, then
           // update q
           if (orientation(points[p], points[i], points[q]) == 2)
               q = i;
        }

        // Now q is the most counterclockwise with respect to p
        // Set p as q for next iteration, so that q is added to
        // result 'hull'
        p = q;

    } while (p != l);  // While we don't come to first point

    // Print Result
    return hull;
}

// Driver program to test above functions
int main()
{
    Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1},
                      {3, 0}, {0, 0}, {3, 3}};
    int n = sizeof(points)/sizeof(points[0]);
    vector <Point> hull = convexHull(points, n);
    Point min_x = {9999999, 9999999}, max_x = {-9999999, -9999999};
    int p1, p2;
    for(int i = 0; i < hull.size(); i++)
    {
        if(min_x.x > hull[i].x)
        {
            p1 = i;
            min_x = hull[i];
        }
        if(max_x.x < hull[i].x)
        {
            p2 = i;
            max_x = hull[i];
        }
    }
    vector <Point> bottom_hull;
    for(int i = p1; i <= p2; i++)
    {
        bottom_hull.push_back(hull[i]);
        printf("(%d, %d)\t", bottom_hull[i-p1].x, bottom_hull[i-p1].y);
    }
    //printf("(%d, %d)\t\t(%d, %d)\n", min_x.x, min_x.y, max_x.x, max_x.y);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;// A structure to represent a Point in 2D plane
struct Point
{
int x, y;
};
// Needed to sort array of points according to X coordinate
int compareX(const void* a, const void* b)
{

Point *p1 = (Point *)a,*p2 = (Point *)b;

return (p1->x - p2->x);

}

// Needed to sort array of points according to Y coordinate

int compareY(const void* a, const void* b)

{

Point *p1 = (Point *)a,*p2 = (Point *)b;

return (p1->y - p2->y);

}

// A utility function to find the distance between two points

float dist(Point p1, Point p2)

{

return abs(p1.x - p2.x) +abs(p1.y - p2.y);

}


// A Brute Force method to return the smallest distance between two points

// in P[] of size n

float bruteForce(Point P[], int n)

{

float max = FLT_MIN;

for (int i = 0; i < n; ++i)
	for (int j = i+1; j < n; ++j)
		if (dist(P[i], P[j]) > max)

			max = dist(P[i], P[j]);

return max;

}



// A utility function to find maximum of two float values

float max(float x, float y)

{

return (x > y)? x : y;

}


// A utility function to find the distance beween the closest points of

// strip of given size. All points in strip[] are sorted accordint to

// y coordinate. They all have an upper bound on maximum distance as d.

// Note that this method seems to be a O(n^2) method, but it's a O(n)

// method as the inner loop runs at most 6 times

float stripClosest(Point strip[], int size, float d)

{

float max = d; // Initialize the maximum distance as d
qsort(strip, size, sizeof(Point), compareY); 
	for (int i = 0; i < size; ++i)

		for (int j = i+1; j < size && (strip[j].y - strip[i].y) < max; ++j)

			if (dist(strip[i],strip[j]) < max)

				max = dist(strip[i], strip[j]);

return max;

}


// A recursive function to find the smallest distance. The array P contains

// all points sorted according to x coordinate

float closestUtil(Point P[], int n)

{

// If there are 2 or 3 points, then use brute force

if (n <= 3)

return bruteForce(P, n);


int mid = n/2;

Point midPoint = P[mid];
float dl = closestUtil(P, mid);

float dr = closestUtil(P + mid, n-mid);
float d = max(dl, dr);
Point strip[n];
int j = 0;
for (int i = 0; i < n; i++)
if (abs(P[i].x - midPoint.x) > d)
strip[j] = P[i], j++;
return max(d, stripClosest(strip, j, d) );
}
// The main functin that finds the smallest distance
// This method mainly uses closestUtil()
float closest(Point P[], int n)
{
qsort(P, n, sizeof(Point), compareX);
// Use recursive function closestUtil() to find the smallest distance
return closestUtil(P, n);
}
int main()
{
	
}




# Program Project 2: Closest Pair of Points

This project requires the implementation of the Closest Pair of Points algorithm

##Project Background

The closest pair of points algorithm is a divide and conquer algorithm, where the overall goal is to find the two closes pairs of points on
a 2D plane. The brute-force version of this algorithm is easy to program, in where we check every point with every other point on the plane.
The only drawback is that it has a big O of n^2. To make this faster, we want to bring this down to O(n log(n))

##Project Description

To perform this algorithm, we first sort each point by it's x value, and we find the mid point. We then perform a recursive call to both the left
and right side until we reach either two point or three points. At this point, we calculate the minimum distance between the left and right sides.
We use this minimum value (we call this lambda) after reaching our base case to find points that have a smaller distance. We look for points within one lambda distance left and one lambda distance right of the dividing line. This recursive solution will keep going until it reaches the original dividing line, where it will return the
final two points.

from queue import PriorityQueue
class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        ans, lines, pq = [], [], PriorityQueue()
        for build in buildings:
            lines.extend([build[0], build[1]])
        lines.sort()
        curbuilding, n = 0, len(buildings)
        for line in lines: 
            while curbuilding < n and buildings[curbuilding][0] <= line:
                pq.put([-buildings[curbuilding][2], buildings[curbuilding][0], buildings[curbuilding][1]]) 
                curbuilding += 1
            while not pq.empty() and pq.queue[0][2] <= line: # higher at heap top after negated
                pq.get() # i.e. pop(), remove no-overlapping building
            high = 0 
            if not pq.empty():
                high = -pq.queue[0][0]
            if len(ans) > 0 and ans[-1][1] == high: 
                continue
            ans.append([line, high])
        return ans

############
import heapq

class Solution:
    def getSkyline(self, buildings):
        # Create a list to store the critical points and heights
        points = []
        for left, right, height in buildings:
            points.append((left, -height))  # Start of building, negative height
            points.append((right, height))  # End of building, positive height

        # Sort the points in ascending order based on x-coordinate
        # If two points have the same x-coordinate, the one with larger height comes first
        points.sort()

        # Create a heap to store the heights in descending order
        heights = [0]  # Initialize the heap with a height of 0
        skyline = [(0, 0)]  # Initialize the skyline with a point (0, 0)

        for x, h in points:
            if h < 0:
                heapq.heappush(heights, h)  # Add the negative height to the heap
            else:
                heights.remove(-h)  # Remove the corresponding negative height from the heap
                heapq.heapify(heights)  # Reorganize the heap

            # The current maximum height is the first element in the heap
            max_height = -heights[0]

            # If the maximum height has changed, add the current point to the skyline
            if max_height != skyline[-1][1]:
                skyline.append((x, max_height))

        return skyline[1:]  # Exclude the initial point (0, 0)
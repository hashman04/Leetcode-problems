from queue import PriorityQueue
class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        ans, lines, pq = [], [], PriorityQueue()
        for build in buildings:
            lines.extend([build[0], build[1]])
        lines.sort()
        curbuilding, n = 0, len(buildings)
        for line in lines: # 对于每一个边界线 lines[i]，找出所有包含 lines[i] 的建筑物
            while curbuilding < n and buildings[curbuilding][0] <= line:
                pq.put([-buildings[curbuilding][2], buildings[curbuilding][0], buildings[curbuilding][1]]) # 建筑物的高度构建优先队列（大根堆），这里会包括line自己的building
                curbuilding += 1
            while not pq.empty() and pq.queue[0][2] <= line: # higher at heap top after negated
                pq.get() # i.e. pop(), remove no-overlapping building
            high = 0 # 建筑物的左边界小于等于 lines[i]，右边界大于 lines[i]，则这些建筑物中高度最高的建筑物的高度就是该线轮廓点的高度
            if not pq.empty():
                high = -pq.queue[0][0]
            if len(ans) > 0 and ans[-1][1] == high: # 绿色建筑的左边的line，就要跳过
                continue
            ans.append([line, high])
        return ans

############

'''
The solution uses a list called points to store the critical points and heights of the buildings. Each point is represented as a tuple (x, h), where x is the x-coordinate and h is the height. The points are sorted in ascending order based on the x-coordinate.

The solution also uses a heap to store the heights in descending order. The heap is initialized with a height of 0. For each point, if the height is negative, it means it is the start of a building, so the negative height is added to the heap. If the height is positive, it means it is the end of a building, so the corresponding negative height is removed from the heap.

After processing each point, the maximum height is obtained from the heap, and if it is different from the previous maximum height, the current point is added to the skyline.

Finally, the skyline is returned, excluding the initial point (0, 0) that was added as a starting point.

Note: The solution assumes that the input buildings is a list of tuples (left, right, height), where left and right represent the x-coordinates of the building's left and right edges, and height represents the height of the building.
'''

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
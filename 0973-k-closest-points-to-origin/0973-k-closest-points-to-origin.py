import heapq

class Solution:
    def kClosest(self, points, k):
        pq = []

        for i in range(len(points)):
            x = points[i][0]
            y = points[i][1]

            distance = x * x + y * y

            if len(pq) < k:
                heapq.heappush(pq, (-distance, i))
            else:
                heapq.heappush(pq, (-distance, i))
                heapq.heappop(pq)

        result = []

        while pq:
            _, index = heapq.heappop(pq)
            result.append(points[index])

        return result
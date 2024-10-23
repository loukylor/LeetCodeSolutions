class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        
        # Get edges
        edges = defaultdict(list)
        visited = [0] * numCourses
        for prereq in prerequisites:
            edges[prereq[0]].append(prereq[1])

         # Loop through nodes and look for repeats
        path = []
        for course in range(numCourses):
            if not self.dfs(course, edges, visited, path):
                return []

        return path

    def dfs(self, course: int, edges: dict[int, int], visited: list[int], path: list[int]) -> bool:
        # Return false if we've already visited this iteration
        if visited[course] == -1:
            return False
        elif visited[course] == 1:
            return True

        # Mark visited this iteration
        visited[course] = -1

        # Loop into edges
        for prereq in edges[course]:
            if not self.dfs(prereq, edges, visited, path):
                return False
        
        # Mark fully visited
        visited[course] = 1
        path.append(course)
        return True

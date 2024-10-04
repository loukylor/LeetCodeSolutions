class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        prereq_map = [[] for _ in range(numCourses)]
        for c1, c2 in prerequisites:
            prereq_map[c2].append(c1)
        
        memo = [None] * numCourses

        def _canFinish(course):
            if memo[course] is not None:
                return memo[course]
            
            memo[course] = False

            for dep in prereq_map[course]:
                if not _canFinish(dep):
                    return False

            memo[course] = True
            return True

        for course in range(numCourses):
            if not _canFinish(course):
                return False
        return True
        
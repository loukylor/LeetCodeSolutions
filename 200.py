class Solution:
    def solution1(self, grid: List[List[str]]) -> int:
        traversed = set()
        visit_list = [(0, 0)]
        islands = 0
        last_tile_water = True
        
        # While we haven't visited all locations
        while len(traversed) != len(grid) * len(grid[0]):
            pos = visit_list.pop(0)
            if pos in traversed:
                continue
            
            if grid[pos[1]][pos[0]] == "1":
                # If last tile was water and were currently
                # on land, then we're on a new island
                if last_tile_water:
                    islands += 1
                last_tile_water = False
            else:
                last_tile_water = True
            
            # Check adj tiles for land
            # Left
            if pos[0] == 0 or (pos[0] - 1, pos[1]) in traversed:
                pass
            elif grid[pos[1]][pos[0] - 1] == "0":
                # Add water tiles to end; prioritize land tiles
                # guaranteeing consecutive land tiles in visit_list
                # are part of the same island
                visit_list.append((pos[0] - 1, pos[1]))
            else:
                visit_list.insert(0, (pos[0] - 1, pos[1]))
                # If on water, only allow discovery of one land
                if grid[pos[1]][pos[0]] == "0":
                    continue
            
            # Right
            if pos[0] == len(grid[0]) - 1 or (pos[0] + 1, pos[1]) in traversed:
                pass
            elif grid[pos[1]][pos[0] + 1] == "0":
                visit_list.append((pos[0] + 1, pos[1]))
            else:
                visit_list.insert(0, (pos[0] + 1, pos[1]))
                if grid[pos[1]][pos[0]] == "0":
                    continue
                    
            # Up
            if pos[1] == 0 or (pos[0], pos[1] - 1) in traversed:
                pass
            elif grid[pos[1] - 1][pos[0]] == "0":
                visit_list.append((pos[0], pos[1] - 1))
            else:
                visit_list.insert(0, (pos[0], pos[1] - 1))
                if grid[pos[1]][pos[0]] == "0":
                    continue
                    
            # Down
            if pos[1] == len(grid) - 1 or (pos[0], pos[1] + 1) in traversed:
                pass
            elif grid[pos[1] + 1][pos[0]] == "0":
                visit_list.append((pos[0], pos[1] + 1))
            else:
                visit_list.insert(0, (pos[0], pos[1] + 1))
                if grid[pos[1]][pos[0]] == "0":
                    continue
                    
            traversed.add(pos)
        
        return islands
        
        
    def solution2(self, grid: List[List[str]]) -> int:
        islands = 0
        for y in range(len(grid)):
            for x in range(len(grid[0])):
                if grid[y][x] != "1":
                    continue
                    
                self.traverse_island(grid, x, y)
                islands += 1
        
        return islands                
    
    def traverse_island(self, grid, x, y):
        if x < 0 or x >= len(grid[0]) or y < 0 or y >= len(grid) or grid[y][x] != "1":
            return
        
        grid[y][x] = "x"
        self.traverse_island(grid, x - 1, y)
        self.traverse_island(grid, x + 1, y)
        self.traverse_island(grid, x, y - 1)
        self.traverse_island(grid, x, y + 1)

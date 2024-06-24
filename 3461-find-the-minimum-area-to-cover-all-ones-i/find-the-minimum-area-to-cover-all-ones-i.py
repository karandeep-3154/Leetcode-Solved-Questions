class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        l = u = sys.maxsize
        r = d = -sys.maxsize
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    l = min(l, j)
                    u = min(u, i)
                    r = max(r, j)
                    d = max(d, i)
        return (r-l+1)*(d-u+1)
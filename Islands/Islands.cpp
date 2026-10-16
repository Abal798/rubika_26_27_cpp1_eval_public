#include <vector>

/*
 * To analyze satellite images, a geospatial company studies maps of remote ocean regions.
 * Each map is represented as a grid where land and water are identified.
 *
 * Your task is to determine how many separate islands are present on a given map.
 * The map is represented as a 2D grid of characters :
 *    - '1' represents land
 *    - '0' represents water
 *
 * An island is defined as a group of connected land cells.
 * Cells are considered connected if they are adjacent horizontally or vertically(not diagonally).
 * The grid is surrounded by water.
 * 
 * Implement the function count_islands which returns the total number of islands present in the map.
 */

void RemoveIsland(std::vector<std::vector<char>>& grid, int x, int y)
{
    if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size()) return;
    if (grid[x][y] == '0')return;
    grid[x][y] = '0';
    RemoveIsland(grid, x-1, y);
    RemoveIsland(grid, x+1, y);
    RemoveIsland(grid, x, y+1);
    RemoveIsland(grid, x, y-1);
}

int count_islands(std::vector<std::vector<char>>& grid)
{
	if (grid.empty())return 0;
    int count = 0;
    
    for (int y=0; y<grid.size(); ++y)
    {
        for (int x=0; x<grid[0].size(); ++x)
        {
            if (grid[x][y] == '1')
            {
                ++count;
                RemoveIsland(grid, x, y);
            }
        }
    }
    
    return count;
}




int main()
{
    {
        std::vector<std::vector<char>> grid = {
            {'1','1','0','0'},
            {'1','0','0','0'},
            {'0','0','1','0'},
        };
        printf("%d\n",count_islands(grid));
    }

    return 0;
}
#!/usr/bin/python3
"""Module to calculate the perimeter of an island in a grid."""

def island_perimeter(grid):
    """
    Calculate the perimeter of an island in a grid.

    Args:
        grid (list of list of int): A 2D grid representing land and water.

    Returns:
        int: The perimeter of the island.
    """
    perimeter = 0
    for r in range(len(grid)):
        for c in range(len(grid[0])):
            if grid[r][c] == 1:
                # Check all 4 adjacent cells
                perimeter += 4
                
                # Subtract adjacent land cells
                if r > 0 and grid[r-1][c] == 1:
                    perimeter -= 2
                if c > 0 and grid[r][c-1] == 1:
                    perimeter -= 2
    
    return perimeter

#include "main.h"
#include <stdlib.h>

/**
* free_grid - Frees a 2D grid previously created by alloc_grid.
* @grid: The 2D grid.
* @height: The height of the grid.
*/
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]);

	free(grid);
}

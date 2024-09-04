#include "find_square.h"
#include <stdio.h>

int	get_cache_value(int *cache, int width, int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	return (cache[y * width + x]);
}

int	ft_scan_rec(t_map *map, int r, int c, int *cache, int *max_square_length,
		int *first_max_index)
{
	int	index;
	int	down;
	int	right;
	int	diag;

	if (r >= map->height || c >= map->width)
		return (0);
	index = r * map->width + c;
	if (cache[index] == -1)
	{
		down = ft_scan_rec(map, r + 1, c, cache, max_square_length,
				first_max_index);
		right = ft_scan_rec(map, r, c + 1, cache, max_square_length,
				first_max_index);
		diag = ft_scan_rec(map, r + 1, c + 1, cache, max_square_length,
				first_max_index);
		if (map->matrix[r][c] == map->empty)
		{
			cache[index] = 1 + MIN(down, MIN(right, diag));
			if (cache[index] > *max_square_length)
			{
				*max_square_length = cache[index];
				*first_max_index = index;
			}
		}
		else
			cache[index] = 0;
	}
	return (cache[index]);
}

int	find_biggest_square(t_map *map)
{
	int rows;
	int cols;
	int max_square_length;
	int first_max_index;
	int *cache;
	int i;
    int first_max_row, first_max_col;


	if (map->height == 0 || map->width == 0)
		return (0);
	rows = map->height;
	cols = map->width;
	max_square_length = 0;
	first_max_index = -1;
    first_max_col = 0;
    first_max_row = 0;
	cache = (int *)malloc(rows * cols * sizeof(int));
	if (!cache)
	{
		ft_puterror("Memory allocation failed\n");
		return (-1);
	}
	i = 0;
	while (i < (rows * cols))
	{
		cache[i] = -1;
		i++;
	}
	ft_scan_rec(map, 0, 0, cache, &max_square_length, &first_max_index);
	if (first_max_index != -1)
	{
		first_max_row = first_max_index / cols;
		first_max_col = first_max_index % cols;
	}

	free(cache);
	return (max_square_length);
}

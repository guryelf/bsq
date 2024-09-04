#ifndef MAP_H
# define MAP_H

# include "bsq.h"

t_map   *parse_map(char *filename);
int     validate_map(t_map *map);
void    free_map(t_map *map);

#endif

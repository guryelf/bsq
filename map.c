#include "map.h"
#include "utils.h"
#include <stdio.h>


t_map	*parse_map(char *filename)
{
    int     fd;
    char    buf;
    char    *config = NULL;
    t_map   *map;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (NULL);
    printf("%s",config);
    while (read(fd, &buf, 1) && buf != '\n')
    {
        config = ft_strjoin(config, (char[]){buf, '\0'});
        printf("%s",config);
    }
    map = (t_map *)malloc(sizeof(t_map));
    if (!map || !config || ft_strlen(config) < 4)
        return (NULL);
    map->height = ft_atoi(config);
    map->width = ft_atoi(config);
    map->full = config[ft_strlen(config) - 1];
    map->obstacle = config[ft_strlen(config) - 2];
    map->empty = config[ft_strlen(config) - 3];
    free(config);
    map->matrix = (char **)malloc(map->height * sizeof(char *));
    printf(%)
    close(fd);
    return (map);
}

int	validate_map(t_map *map)
{
	int	i;
	int	j;
    
	if ((map->height <= 0 && map->width <= 0)){
        printf("as");
		return (0);
    }
	i = 0;
	while (i < map->height)
	{
		if (ft_strlen(map->matrix[i]) != map->width)
			return (0);
		j = 0;
		while (j < map->width)
		{
			if (map->matrix[i][j] != map->empty
				&& map->matrix[i][j] != map->obstacle)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
void	print_map(t_map *map)
{
	for (int i = 0; i < map->height; i++)
	{
		ft_putstr(map->matrix[i]);
		ft_putstr("\n");
	}
}

void	free_map(t_map *map)
{
	int	i;

	if (map)
	{
		i = 0;
		while (i < map->height)
			free(map->matrix[i++]);
		free(map->matrix);
		free(map);
	}
}

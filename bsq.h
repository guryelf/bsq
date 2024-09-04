#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	int		width;
	int		height;
	char	empty;
	char	obstacle;
	char	full;
	char	**matrix;
}			t_map;

void		free_map(t_map *map);
int			validate_map(t_map *map);
void		print_map(t_map *map);
t_map		*parse_map(char *filename);
int			find_biggest_square(t_map *map);
void		ft_putstr(char *str);
void		ft_puterror(char *str);
int			ft_strlen(char *str);
char		*ft_strdup(char *src);
char		*ft_strjoin(char *s1, char *s2);

#endif

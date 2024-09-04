#include "bsq.h"
#include <stdio.h>
int	main(int argc, char **argv)
{
    t_map   *map;
    int     i;
    printf("Program started\n");
    if (argc < 2)
    {
        ft_puterror("map error1\n");
        return (1);
    }
    i = 1;
    while (i < argc)
    {
        map = parse_map(argv[i]);
        if (!map || !validate_map(map))
        {
            ft_puterror("map error2\n");
            free_map(map);
        }
        else
        {
            find_biggest_square(map);
            print_map(map);
            free_map(map);
        }
        if (i < argc - 1)
            ft_putstr("\n");
        i++;
    }
    return (0);
}

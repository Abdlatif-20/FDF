/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:50:53 by aben-nei          #+#    #+#             */
/*   Updated: 2023/03/09 21:54:05 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	str_length(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if ((str[i] != ' ' && str[i + 1] == ' ') || str[i + 1] == '\0')
			len++;
		i++;
	}
	return (len);
}

void	check_lenght_of_map(int fd, t_data	*data)
{
	size_t	len;
	size_t	len1;
	int		height;
	char	*str;

	str = get_next_line(fd);
	if (!str)
		return (ft_putendl_fd("Found empty Map.", 2), exit(1));
	if (str[0] == '\n')
		return (ft_putendl_fd("Found empty line.", 2), exit(1));
	len = str_length(str);
	data->width = len;
	free(str);
	str = get_next_line(fd);
	height = 1;
	while (str)
	{
		height++;
		len1 = str_length(str);
		if (len > len1)
			return (ft_putendl_fd("Found empty line.", 2), exit(1));
		free(str);
		str = get_next_line(fd);
	}
	data->height = height;
}

void	check_name_of_map(char *str, char *find)
{
	int	i;
	int	j;

	i = ft_strlen(str) - 1;
	j = 0;
	while (str[i] && find[j])
	{
		while (str[i] != '.')
			i--;
		if (i < 0)
			return (ft_putendl_fd("Wrong file extension.", 2), exit(1));
		if (str[i] == '.' && i >= 0)
		{
			while (str[i])
			{
				if (str[i] != find[j])
					return (ft_putendl_fd("Wrong file extension.", 2), exit(1));
				i++;
				j++;
			}
		}
	}
}

void	ft_check_map_is_valid(char **av, int fd, t_data *data)
{
	int		i;

	(void)(data);
	i = 0;
	check_name_of_map(av[1], ".fdf");
	fd = open(av[1], O_RDONLY, 777);
	if (fd < 0)
		return (ft_putstr_fd("no such file: ", 2),
			ft_putendl_fd(av[1], 2), exit(1));
	check_lenght_of_map(fd, data);
	close(fd);
}

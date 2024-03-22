/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:29:36 by malanglo          #+#    #+#             */
/*   Updated: 2024/03/22 16:46:50 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	argc_count(int argc)
{
	if (argc != 2)
	{
		ft_putstr("Wrong number of arguments - expected ./fdf selected_map\n");
		return (0);
	}
	else
		return (1);
}

int	check_input_existence(char *input)
{
	int	fd;

	fd = open(input, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("La donnee d entree est invalide.\n");
		return (0);
	}
	else
	{
		close(fd);
		return (1);
	}
}

int	check_folder_validity(char *folder)
{
	int		fd;

	fd = open(folder, __O_DIRECT);
	if (fd < 0)
	{
		ft_putstr("La donnee d entree est invalide.\n");
		return (0);
	}
	else
	{
		close(fd);
		return (1);
	}
}

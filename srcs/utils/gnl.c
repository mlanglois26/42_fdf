/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:47:25 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/30 14:53:24 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

char	*ft_read_from_fd_and_concatenate_to_stash(int fd, char *stash)
{
	char	*buff;
	char	*tmp;
	int		bytes_read;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buff), free(stash), NULL);
		buff[bytes_read] = '\0';
		tmp = ft_strjoin(stash, buff);
		free(stash);
		stash = tmp;
	}
	return (free(buff), stash);
}

char	*ft_get_content(char *stash)
{
	char	*content;
	int		i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (ft_strchr(stash, '\n'))
		content = ft_substr(stash, 0, i + 1);
	else
		content = ft_strdup(stash);
	return (content);
}

char	*ft_update_stash_after_line_exctraction(char *stash)
{
	char	*new_stash;
	char	*tmp;

	if (!stash)
		return (NULL);
	new_stash = ft_strchr(stash, '\n');
	if (new_stash)
	{
		tmp = ft_strdup(new_stash + 1);
		return (free(stash), tmp);
	}
	else
		return (free(stash), NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_from_fd_and_concatenate_to_stash(fd, stash);
	if (!stash || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = ft_get_content(stash);
	stash = ft_update_stash_after_line_exctraction(stash);
	return (line);
}

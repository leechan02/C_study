/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:00:22 by euiclee           #+#    #+#             */
/*   Updated: 2022/10/14 17:32:23 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*free_all(char **s)
{
	if (*s)
		free(*s);
	*s = NULL;
	return (NULL);
}

char	*new_backup(char **backup, char *buf)
{
	char	*new_backup;
	size_t	backup_len;
	size_t	buf_len;

	backup_len = get_strlen(*backup);
	buf_len = get_strlen(buf);
	new_backup = (char *)get_calloc(backup_len + buf_len + 1, sizeof(char));
	if (!new_backup)
		return (free_all(backup));
	get_strlcat(new_backup, *backup, backup_len + buf_len + 1);
	get_strlcat(new_backup, buf, backup_len + buf_len + 1);
	free_all(backup);
	return (new_backup);
}

char	*get_line(char **backup)
{
	char	*line;
	char	*line_end;

	if (get_strchr(*backup, '\n'))
		line_end = get_strchr(*backup, '\n') + 1;
	else
		line_end = get_strchr(*backup, '\0');
	line = (char *)get_calloc(line_end - *backup + 1, sizeof(char));
	if (!line)
		return (free_all(backup));
	get_strlcat(line, *backup, line_end - *backup + 1);
	*backup[0] = '\0';
	*backup = new_backup(backup, line_end);
	return (line);
}

char	*read_line(int fd, char **backup)
{
	char	buf[4];
	int		byte;

	byte = 1;
	while (byte)
	{
		if (get_strchr(*backup, '\n'))
			break ;
		byte = read(fd, buf, 3);
		if (byte < 0)
			return (free_all(backup));
		buf[byte] = '\0';
		*backup = new_backup(backup, buf);
		if (!backup || !*backup)
			return (free_all(backup));
	}
	if (byte == 0 && **backup == '\0')
		return (free_all(backup));
	return (get_line(backup));
}

char	*get_next_line(int fd)
{
	static char	*backup;

	if (fd < 0 || fd > OPEN_MAX)
		return (0);
	return (read_line(fd, &backup));
}

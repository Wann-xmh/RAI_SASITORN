/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasijaro <sasijaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:45:45 by sasijaro          #+#    #+#             */
/*   Updated: 2025/07/27 16:25:40 by sasijaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <fcntl.h>

#define MAX_LEN 1024

int	key_exists(t_dict *dict, int size, char *key)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_strcmp(dict[i].key, key) == 0)
			return (1);
		i++;
	}
	return (0);
}

#define MAX_LEN 10000

// ฟังก์ชันช่วย: แยก key:value และเพิ่ม entry ถ้ายังไม่มี
void	parse_and_add_entry(char *line, t_dict *dict, int *size)
{
	char	*sep;
	char	*key;
	char	*value;

	sep = line;
	while (*sep && *sep != ':')
		sep++;
	if (*sep != ':')
		return ;
	*sep = '\0';
	key = ft_strtrim(line);
	value = ft_strtrim(sep + 1);
	if (!key_exists(dict, *size, key))
	{
		dict[*size].key = key;
		dict[*size].value = value;
		(*size)++;
	}
	else
	{
		free(key);
		free(value);
	}
}

// ฟังก์ชันหลัก
int	load_dict(const char *filename, t_dict *dict, int *size)
{
	int		fd;
	int		i;
	char	buffer[MAX_LEN];
	int		bytes;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	bytes = read(fd, buffer, MAX_LEN - 1);
	buffer[bytes] = '\0';
	close(fd);
	*size = 0;
	line = buffer;
	while (buffer[i])
	{
		if (buffer[i] == '\n' || buffer[i + 1] == '\0')
		{
			if (buffer[i] != '\n')
				i++; // ให้รวมตัวสุดท้ายถ้าไม่มี \n
			buffer[i] = '\0';
			parse_and_add_entry(line, dict, size);
			line = buffer + i + 1;
		}
		i++;
	}
	return (1);
}

void	write_str(int fd, char *s)
{
	write(fd, s, ft_strlen(s));
}

void	save_dict(const char *filename, t_dict *dict, int size)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return ;
	while (i < size)
	{
		write_str(fd, dict[i].key);
		write_str(fd, " : ");
		write_str(fd, dict[i].value);
		write_str(fd, "\n");
		i++;
	}
	close(fd);
}

void	free_dict(t_dict *dict, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(dict[i].key);
		free(dict[i].value);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasijaro <sasijaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:38:47 by sasijaro          #+#    #+#             */
/*   Updated: 2025/07/26 19:14:35 by sasijaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *s)
{
	unsigned int	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!(dest))
		return ((void *)0);
	while (*src)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strtrim(char *s)
{
	unsigned int	len;
	unsigned int	i;
	char			*out;

	i = 0;
	len = ft_strlen(s);
	while (*s == ' ' || *s == '\t')
		s++;
	while (len > 0 && (s[len - 1] == ' ' || s[len - 1] == '\n'))
		len--;
	out = malloc(len + 1);
	if (!out)
		return ((void *)0);
	while (i < len)
	{
		out[i] = s[i];
		i++;
	}
	out[len] = '\0';
	return (out);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 19:12:26 by rle               #+#    #+#             */
/*   Updated: 2017/05/08 13:57:23 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

char	*get_link_num(char *link, int n)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	while (link[i] != '-')
		i++;
	c = (char *)malloc(sizeof(char) * i + 1);
	i = -1;
	while (link[++i] != '-')
		c[i] = link[i];
	c[i] = '\0';
	if (n == 0)
		return (c);
	free(c);
	j = 0;
	while (link[i + j])
		j++;
	c = (char *)malloc(sizeof(char) * j + 1);
	j = 0;
	while (link[++i])
		c[j++] = link[i];
	c[j] = '\0';
	return (c);
}

int		get_ants(t_data *data)
{
	int	i;
	int	j;

	data->ants = 0;
	i = 0;
	while (data->doc[i][0] == '#')
		i++;
	if (!valid_ants(data->doc[i]))
		return (-1);
	j = 0;
	while (data->doc[i][j] && ft_isdigit(data->doc[i][j]))
	{
		data->ants *= 10;
		data->ants += data->doc[i][j] - '0';
		j++;
	}
	return (1);
}

t_data	get_data(void)
{
	t_data	data;

	get_doc(&data);
	if (!validate_doc(data))
	{
		ft_printf("ERROR: invalid doc\n");
		exit(1);
	}
	get_max_rooms(&data);
	get_rooms(&data);
	get_links(&data);
	if (-1 == get_ants(&data))
	{
		ft_printf("ERROR: invalid ants\n");
		exit(1);
	}
	get_start(&data);
	get_end(&data);
	return (data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:30:40 by heantoni          #+#    #+#             */
/*   Updated: 2021/02/10 22:25:59 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int			make_file(char *name_file)
{
	int		fd1;
	int		i;
	char	*new_name;

	if ((new_name = (char *)malloc(sizeof(char) * (ft_strlen(name_file) + 3))) \
			< 0)
		return (-1);
	i = 0;
	while (i < (int)(ft_strlen(name_file) - 1))
	{
		new_name[i] = name_file[i];
		i++;
	}
	new_name[i++] = 'c';
	new_name[i++] = 'o';
	new_name[i++] = 'r';
	new_name[i] = '\0';
	if ((fd1 = open(new_name, O_CREAT | O_WRONLY, 0644)) < 0)
	{
		free(new_name);
		return (-1);
	}
	free(new_name);
	return (fd1);
}

int			write_code3(int fd1, t_chempion *ch, char **nullu)
{
	(*nullu)[0] = 0;
	(*nullu)[1] = 0;
	(*nullu)[2] = 0;
	(*nullu)[3] = 0;
	write(fd1, *nullu, 4);
	write(fd1, ch->code, ch->smehenee);
	free(ch->code);
	free(*nullu);
	return (1);
}

int			write_code2(int fd1, t_chempion *ch)
{
	char	*nullu;
	short	m;
	int		i;

	i = 0;
	if ((nullu = (char *)malloc(sizeof(char) * 4)) < 0)
		return (-1);
	nullu[0] = 0;
	nullu[1] = 0;
	nullu[2] = 0;
	nullu[3] = 0;
	write(fd1, nullu, 4);
	m = (ch->smehenee) >> 16;
	nullu[0] = m >> 8;
	nullu[1] = m & 255;
	m = ch->smehenee;
	nullu[2] = m >> 8;
	nullu[3] = m & 255;
	write(fd1, nullu, 4);
	write(fd1, ch->comment, COMMENT_LENGTH);
	free(ch->comment);
	write_code3(fd1, ch, &nullu);
	return (1);
}

int			write_code(char *name_file, t_chempion *ch)
{
	int		fd1;
	char	*magic;
	short	m;

	fd1 = make_file(name_file);
	magic = (char *)malloc(sizeof(char) * 4);
	magic[0] = COREWAR_EXEC_MAGIC >> 24;
	magic[1] = (char)((COREWAR_EXEC_MAGIC >> 16) & 255);
	m = (short)COREWAR_EXEC_MAGIC;
	magic[2] = m >> 8;
	magic[3] = m & 255;
	write(fd1, magic, 4);
	free(magic);
	write(fd1, ch->name, PROG_NAME_LENGTH);
	free(ch->name);
	if (write_code2(fd1, ch) < 0)
		return (-1);
	close(fd1);
	return (1);
}

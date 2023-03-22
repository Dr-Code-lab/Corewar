/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 22:57:02 by heantoni          #+#    #+#             */
/*   Updated: 2021/02/13 21:59:30 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		zap_struct_ascii(t_chempion *ch, char *str, \
		t_new_st_label **label)
{
	t_new_st_label	*label2;

	if (ch->flag == 3)
	{
		if (proverca_label(str) < 0)
			return (-1);
		if (ch->flag_label == 1)
		{
			label2 = label_last(label);
			add_label(str, &(label2->lab));
		}
		else
		{
			ch->flag_label = 1;
			add_st_label(str, label);
		}
	}
	return (1);
}

int		init_asm(t_chempion *ch, t_new_st_label **label, \
		t_op_strukt **op, int fd)
{
	if ((ch->name = (char*)malloc(sizeof(char) * PROG_NAME_LENGTH + 1)) < 0)
		return (-1);
	ch->name[PROG_NAME_LENGTH] = '\0';
	ch->name[0] = '\0';
	ch->n = 0;
	if ((ch->comment = (char*)malloc(sizeof(char) * COMMENT_LENGTH + 1)) < 0)
		return (-1);
	ch->comment[COMMENT_LENGTH] = '\0';
	ch->comment[0] = '\0';
	ch->i = 0;
	ch->code = NULL;
	ch->flag_label = 0;
	ch->smehenee = 0;
	ch->size = 0;
	ch->len_com = 0;
	ch->fd = fd;
	ch->kol_name_comment = 0;
	ch->flag = -1;
	ch->prov = 0;
	(*op) = NULL;
	(*label) = NULL;
	zap_registr(ch);
	return (1);
}

void	err(t_chempion *ch, t_new_st_label *label, t_op_strukt *op)
{
	close(ch->fd);
	free(ch->name);
	free(ch->comment);
	free_op_struct(op);
	free_lab(label);
	write(2, "Can't read code\n", 16);
}

int		err1(t_chempion *ch, t_new_st_label *label, t_op_strukt *op)
{
	err(ch, label, op);
	free(ch->code);
	return (-1);
}

int		main(int argc, char *ar[])
{
	int				fd;
	t_chempion		ch;
	t_new_st_label	*label;
	t_op_strukt		*op;

	if (argc != 2 || file_argv(ar[1]) < 0 || (fd = open(ar[1], O_RDONLY)) < 0)
	{
		write(2, "Can't read file\n", 16);
		return (-1);
	}
	if (init_asm(&ch, &label, &op, fd) < 0 || \
	read_line(fd, &ch, &label, &op) < 0 || ch.i != 0 || ch.n != 0)
	{
		err(&ch, label, op);
		return (-1);
	}
	if (ch.smehenee == 0 || trace_byte_code(&ch, label, op) < 0)
		return (err1(&ch, label, op));
	free_op_struct(op);
	free_lab(label);
	if (write_code(ar[1], &ch) < 0)
		return (-1);
	close(fd);
	return (0);
}

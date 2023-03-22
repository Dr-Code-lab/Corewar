/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:01:55 by heantoni          #+#    #+#             */
/*   Updated: 2021/02/13 22:07:28 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../printf/includes/printf.h"
# include "op.h"

typedef struct				s_op
{
	char					*name;
	int						arg;
	int						reg[3];
	int						code_op;
	int						neponatca;
	char					*poasny;
	int						code_type;
	int						size;
}							t_op;

extern						t_op g_op_tab[17];

typedef struct				s_registr
{
	int						code;
	int						size;
}							t_registr;

typedef struct				s_op_strukt
{
	int						size;
	int						name;
	int						smechenee;
	char					*stroca;
	struct s_op_strukt		*next;
}							t_op_strukt;

typedef struct				s_chempion
{
	char					*name;
	char					*comment;
	char					*code;
	int						size;
	int						flag;
	int						flag_label;
	int						smehenee;
	int						mestnoe_smehenee;
	int						mestnoe_size;
	int						i;
	int						n;
	int						tu;
	int						prov;
	int						fd;
	int						len_com;
	int						kol_name_comment;
	t_registr				reg[3];
}							t_chempion;

typedef struct				s_label
{
	char					*name;
	t_op_strukt				*op;
	struct s_label			*next;
}							t_label;

typedef struct				s_new_st_label
{
	t_label					*lab;
	int						smehenee;
	struct s_new_st_label	*next;
}							t_new_st_label;

int							kol_sim(char *str, char c);
int							kol_sim_not(char *str, char c);
t_label						*add_label(char *str, t_label **label);
t_new_st_label				*add_st_label(char *str, t_new_st_label **label);
int							pars_name(char *line, t_chempion *ch);
int							par_l(char *line, t_chempion *ch, \
							t_new_st_label **label);
int							proverca_label(char *str);
int							zap_struct_ascii(t_chempion *ch, char *str, \
							t_new_st_label **label);
char						*cut_one(char *str, char c, int n);
void						zap_operation(t_chempion *ch);
t_op_strukt					*add_op_struct(t_op_strukt **label);
void						zap_registr(t_chempion *ch);
int							operation_name(char *srez, t_op_strukt **op);
int							pars_operation(char *line, t_chempion *ch, \
							t_op_strukt **op, t_new_st_label **label);
int							pars_one(char *line, t_chempion *ch, \
							t_new_st_label **label, t_op_strukt **op);
int							trace_byte_code(t_chempion *ch, \
							t_new_st_label *label, t_op_strukt *op);
int							prop_probel(char *str);
int							number_pr(char *str);
int							write_code(char *name_file, t_chempion *ch);
t_op_strukt					*operation_last(t_op_strukt **op);
t_new_st_label				*label_last(t_new_st_label **label);
t_label						*new_add_label(char *str);
int							proverca_registr(char *srez, t_chempion *ch, \
							t_new_st_label *label, t_op_strukt *new_op);
int							proverca(char c);
int							proverca_registr3(char *srez, t_chempion *ch, \
							t_op_strukt *new_op);
int							lab_ch(char *str);
void						free_lab(t_new_st_label *label);
void						free_op_struct(t_op_strukt *op);
int							simvol(char *str, char c);
int							read_name(t_chempion *ch, char *line);
int							read_comment(t_chempion *ch, char *line);
int							read_line(int fd, t_chempion *ch, \
							t_new_st_label **label, t_op_strukt **op);
int							flag_name(char *line, t_chempion *ch, int n, int k);
int							file_argv(char *str);
int							pars_register(char *str, t_op_strukt **op, int n);
int							proverca_registr2(char *srez, t_chempion *ch, \
							t_new_st_label *label, t_op_strukt *new_op);
int							proverca_instruction(char *str, t_chempion *ch, \
							t_new_st_label *label);
void						byte_code(short tmp2, t_chempion *ch);
int							prop_srez(char *str);
int							free_and_return(char *line, int k);
int							prov(char *srez);
int							is_space_ch(char *s, int a);
void						pars_register2(char *str, t_op_strukt **op);
int							pars_register3(char *str, t_op_strukt **op);

#endif

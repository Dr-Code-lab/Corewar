/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 20:10:42 by hlikely           #+#    #+#             */
/*   Updated: 2021/02/10 19:21:54 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "../printf/includes/printf.h"
# include "op.h"
# include "vm_op.h"
# include "SDL2/SDL.h"
# include "SDL2/SDL_ttf.h"

# define MAGIC_NUMBER_LENGTH 4

# define WIDTH 1640
# define HEIGHT 1080
# define RED 207, 55, 91
# define YELLOW 229, 179, 76
# define GREEN 89, 178, 129
# define BLUE 97, 194, 235
# define GREY 125, 125, 125

typedef struct			s_vis
{
	int					par_id;
	char				map_cpy[MEM_SIZE];
	int					n_col[4096];
	char				line[3];
	int					b_n;
	SDL_Color			clr;
	SDL_Window			*wind;
	SDL_Surface			*scrn;
	SDL_Surface			*sur;
	TTF_Font			*font;
	SDL_Event			eve;
	char				*font_path;
	int					quit;
}						t_vis;

typedef struct			s_champ
{
	int					number;
	char				*name;
	int					code_size;
	char				*comm;
	unsigned char		*code;
	int					live_cycle;
	int					lives_num;
}						t_champ;

typedef struct			s_koretko
{
	int					id;
	int					carry;
	int					position;
	int					last_alive;
	int					delay;
	int					step;
	int					regs[REG_NUMBER];
	int					args[3];
	int					op_code;
	int					parent_id;
	int					ind_adrs;
	struct s_koretko	*next;
}						t_koretko;

typedef struct			s_cw
{
	t_champ				*champs[MAX_PLAYERS];
	unsigned char		map[MEM_SIZE];
	int					num_of_champ;
	int					num_of_koretko;
	int					last_id;
	int					cycles;
	int					last_player;
	int					num_of_lives;
	int					cycles_to_die;
	int					cycles_to_check;
	int					num_of_checks;
	int					dump_cycle;
	int					vs;
	t_koretko			*kors;
	t_vis				*vis;
}						t_cw;

void					ft_print_memory(const void *addr, size_t size);
int						get_adrs(t_koretko *koretko, int modif,
						int phantom_step);
int						is_reg(t_cw *cw, t_koretko *koretko);
int						is_dir(t_cw *cw, t_koretko *koretko, int n, int pha);
int						is_indir(t_cw *cw, t_koretko *koretko);
int						get_value(t_cw *cw, t_koretko *koretko, int arg,
						int pha);
void					write_value(t_cw *cw, int adrs, int value, int size);
void					op_live(t_cw *cw, t_koretko *kor);
void					op_ld(t_cw *cw, t_koretko *kor);
void					op_st(t_cw *cw, t_koretko *kor);
void					op_add(t_cw *cw, t_koretko *kor);
void					op_sub(t_cw *cw, t_koretko *kor);
void					op_and(t_cw *cw, t_koretko *kor);
void					op_or(t_cw *cw, t_koretko *kor);
void					op_xor(t_cw *cw, t_koretko *kor);
void					op_zjmp(t_cw *cw, t_koretko *kor);
void					op_ldi(t_cw *cw, t_koretko *kor);
void					op_sti(t_cw *cw, t_koretko *kor);
void					op_fork(t_cw *cw, t_koretko *old_kor);
void					op_lld(t_cw *cw, t_koretko *kor);
void					op_lldi(t_cw *cw, t_koretko *kor);
void					op_lfork(t_cw *cw, t_koretko *old_kor);
void					op_aff(t_cw *cw, t_koretko *kor);
void					read_magic_number(char *argv, int fd, t_cw *cw);
void					read_champ_name(int fd, t_champ *champ, t_cw *cw);
void					read_champ_code_size(int fd, t_champ *champ, t_cw *cw);
void					read_champ_comm(int fd, t_champ *champ, t_cw *cw);
void					read_champ_code(int fd, t_champ *champ, t_cw *cw);
void					place_pl_and_kors(t_cw *cw);
t_koretko				*create_koretko(int id, int position);
void					chain_kor(t_koretko **kors, t_koretko *kor);
void					check_cycles(t_cw *cw);
void					wrong_args(t_koretko *kor);
int						is_correct_args(int i, int *ar, t_cw *cw,
						t_koretko *koretko);
void					cycle(t_cw *cw);
void					output_error(int n, t_cw *cw);
void					print_usage();
void					free_after_finish(t_cw *cw);
int						get_adrs(t_koretko *koretko, int modif,
						int phantom_step);
int						ft_atoi_only_dig(const char *str, t_cw *cw);
int						has_cor(char *str);
void					check_players_n(t_cw *cw, int ac, char **av);
void					check_players_wo_n(t_cw *cw, int ac, char **av);
int						parse_player(t_cw *cw, int ac, char **av, int i);
void					cycle_to_die_check(t_cw *cw);
void					swap_kor(t_koretko **prev, t_koretko **kor);
void					make_cycle(t_cw *cw);
void					make_op(t_cw *cw);
void					visualiser(t_cw *cw);
void					vis_init(t_cw *cw);
int						vis_deinit(t_cw *cw);
void					get_clr(t_cw *cw);
void					ft_print_hex_to_line(unsigned char c, t_cw *cw);
void					draw_param(t_cw *cw);
void					get_clr_param(t_cw *cw);
void					d_lp_name(t_cw *cw);
void					d_lp_par(t_cw *cw);
void					d_p1n_name(t_cw *cw);
void					d_p1n_par(t_cw *cw);
void					d_p1l_name(t_cw *cw);
void					d_p1l_par(t_cw *cw);
void					d_p2n_name(t_cw *cw);
void					d_p2n_par(t_cw *cw);
void					d_p2l_name(t_cw *cw);
void					d_p2l_par(t_cw *cw);

#endif

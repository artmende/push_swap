# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artmende <artmende@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 15:42:45 by artmende          #+#    #+#              #
#    Updated: 2021/10/18 11:08:21 by artmende         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS_PUSH_SWAP =	./push_swap_folder/main.c \
					./push_swap_folder/verify_and_store_nbrs.c \
					./push_swap_folder/create_nbr_list_from_args.c \
					./push_swap_folder/create_nbr_list_from_str.c \
					./push_swap_folder/linked_list_add_back_and_free.c \
					./push_swap_folder/algo_chunks.c \
					./push_swap_folder/algo_chunks_utils.c \
					./push_swap_folder/send_nbr_to_b.c \
					./push_swap_folder/actions_ra_rb_rr.c \
					./push_swap_folder/actions_rra_rrb_rrr.c \
					./push_swap_folder/actions_sa_sb_ss_pa_pb.c \
					./push_swap_folder/mix_libft/ft_atoi.c \
					./push_swap_folder/mix_libft/ft_memset.c \
					./push_swap_folder/mix_libft/ft_strchr.c \

SRCS_CHECKER =	./checker_folder/main.c \
				./checker_folder/verify_and_store_nbrs.c \
				./checker_folder/create_nbr_list_from_args.c \
				./checker_folder/create_nbr_list_from_str.c \
				./checker_folder/linked_list_add_back_and_free.c \
				./checker_folder/run_actions.c \
				./checker_folder/actions_ra_rb_rr.c \
				./checker_folder/actions_rra_rrb_rrr.c \
				./checker_folder/actions_sa_sb_ss_pa_pb.c \
				./checker_folder/get_next_line/get_next_line.c \
				./checker_folder/get_next_line/get_next_line_utils.c \
				./checker_folder/mix_libft/ft_atoi.c \
				./checker_folder/mix_libft/ft_memset.c \
				./checker_folder/mix_libft/ft_strchr.c \
				./checker_folder/mix_libft/ft_strnstr.c \

OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)

OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)

RM = rm -f

NAME_PUSH_SWAP = push_swap

NAME_CHECKER = checker

all: $(NAME_PUSH_SWAP)

bonus: $(NAME_CHECKER)

$(NAME_PUSH_SWAP): $(OBJS_PUSH_SWAP)
	$(CC) -o $(NAME_PUSH_SWAP) $(CFLAGS) $(OBJS_PUSH_SWAP)

$(NAME_CHECKER): $(OBJS_CHECKER)
	$(CC) -o $(NAME_CHECKER) $(CFLAGS) $(OBJS_CHECKER)

clean:
	$(RM) $(OBJS_PUSH_SWAP)
	$(RM) $(OBJS_CHECKER)

fclean: clean
	$(RM) $(NAME_PUSH_SWAP)
	$(RM) $(NAME_CHECKER)

re: fclean all

.PHONY: clean fclean re all bonus

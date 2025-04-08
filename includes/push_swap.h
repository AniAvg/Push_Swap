/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:16:08 by anavagya          #+#    #+#             */
/*   Updated: 2025/04/05 11:20:30 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h> // read(), write()
# include <stdlib.h> // malloc(), free(), exit()
# include <limits.h>

void	ft_error(void);
int		ft_myatoi(const char *str);
int		args_len(char **argv);
char	*join_args(char **argv);
void	is_duplicate(long *num_array);
int		*validate_args(char **argv);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 00:00:28 by hyeojang          #+#    #+#             */
/*   Updated: 2021/05/22 20:59:59 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_UTILS_H
# define CUB3D_UTILS_H

# include "../base.h"
# include "../main.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

int				get_next_line(int fd, char **line);
int				ft_check_line(char **save, char **line);
int				savejoin(char **save, char *buf, size_t read_size);
char			*ft_strchr(const char *s, int c);
char			*ft_strndup(const char *s, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
void			*ft_memcpy(void *dest, const void *src, size_t n);
size_t			ft_strlen(const char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			**ft_split(char const *s, char c, int *cnt);
void			ft_free_split(char **s, int cnt);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			free_word(char **s, int i);
void			ft_lstclear(t_list **lst, void (*del)(void*));
t_list			*ft_lstnew(void *content);
void			ft_lstadd_back(t_list **lst, t_list *new_list);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
t_floatxy		put_xy(float x, float y);

#endif

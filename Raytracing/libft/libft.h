/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:51:31 by kkuhn             #+#    #+#             */
/*   Updated: 2025/04/20 12:17:55 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "../garbageCollector.h"
# include <ctype.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	size_t			size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
int					ft_atoi(const char *number);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(int count, int size);
int					ft_isalnum(int a);
int					ft_isalpha(int a);
int					ft_isascii(int a);
int					ft_isdigit(int a);
int					ft_isprint(int a);
char				*ft_itoa(int n);
void				*ft_memchr(const void *s, int c, int size);
int					ft_memcmp(void *s1, void *s2, size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int number, int fd);
void				ft_putstr_fd(char *s, int fd);
char				*ft_strchr(char const *s, int c);
char				*ft_strdup(char *s1);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, char *src, size_t destsize);
size_t				ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t				ft_strlen(char const *str);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(char *s1, char *s2, size_t n);
char				*ft_strnstr(char *text, char *to_search, int n);
char				*ft_strrchr(char *s, int c);
char				**ft_split(char const *s, char c);
char				*ft_strtrim(char const *s, char const *set);
char				*ft_substr(char const *s, size_t start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);

#endif /* MY_HEADER_FILE_H */
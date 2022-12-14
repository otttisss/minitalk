/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilagro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:31:11 by cmilagro          #+#    #+#             */
/*   Updated: 2022/03/15 19:31:14 by cmilagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

char			*get_next_line(int fd);
int				ft_wdcounter(char const *str, char c);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
				void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstadd_back(t_list **lst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_front(t_list **lst, t_list *new);
t_list			*ft_lstnew(void *content);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
//char			**ft_split(char const *s, char c);
char			**ft_split(char const *str, char c);
void			*ft_memchr(const void *s, int c, size_t n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_itoa(int n);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strjoin(char *reminder, char *buff);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_strncmp(const char *s, const char *t, size_t num);
char			*ft_strdup(const char *str);
void			*ft_calloc(size_t num, size_t size);
int				ft_atoi(const char *str);
char			*ft_strnstr(const char *big, const char *lit, size_t len);
int				ft_memcmp(const void *buf1, const void *buf2, size_t count);
char			*ft_strrchr(const char *str, int ch);
char			*ft_strchr(const char *str, int c);
int				ft_tolower(int ch);
int				ft_toupper(int ch);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *s1, const char *s2, size_t l);
void			*ft_memmove(void *dst, const void *src, size_t count);
void			*ft_memcpy(void *dest, const void *source, size_t count);
void			ft_bzero(void *inp, size_t count);
void			*ft_memset(void *src, int sym, size_t count);
size_t			ft_strlen(const char *l);
int				ft_isprint(int l);
int				ft_isascii(int l);
int				ft_isalnum(int l);
int				ft_isalpha(int l);
int				ft_isdigit(int l);
#endif

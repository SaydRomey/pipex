/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:49:35 by cdumais           #+#    #+#             */
/*   Updated: 2023/09/19 11:24:30 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_UTILS_H
# define LIBFT_UTILS_H

/* headers */

# include <unistd.h> // write, read, close
# include <stdlib.h> // malloc, free, exit
# include <string.h> // size_t, NULL //?
# include <stdio.h> // printf, size_t, NULL
# include <fcntl.h> // open, read, write, close
# include <stdarg.h> // va_list, va_start, va_arg, va_end

/* abbreviated data types*/

typedef signed char			t_s8;
typedef unsigned char		t_u8;
typedef const unsigned char	t_cu8;

typedef signed short		t_s16;
typedef unsigned short		t_u16;

typedef signed int			t_s32;
typedef unsigned int		t_u32;

typedef signed long long	t_s64;
typedef unsigned long long	t_u64;

/* numeral bases */

# define BINARY		"01"
# define OCTAL		"01234567"
# define DECIMAL	"0123456789"
# define HEX_LO		"0123456789abcdef"
# define HEX_UP		"0123456789ABCDEF"

/* GNL */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MAX_OPEN 256

/* Limits */
# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# define TRUE 1
# define FALSE 0

// for toggle function
# define ON 1
# define OFF 0

// for read_check
# define VALID 1
# define EMPTY 0

// use with ft_strncmp
# define SAME 0

# define LOOP 1

/* Return values */

// successful exit status
# define SUCCESS 0
// failing exit status
# define FAILURE 1
// error exit status
# define ERROR -1

/* Standard File Descriptors */

// STDIN_FILENO
# define FD_INPUT	0
// STDOUT_FILENO
# define FD_OUTPUT	1
// STDERR_FILENO
# define FD_ERROR	2

/* Standard File Permissions */

# define READ O_RDONLY
# define WRITE O_WRONLY
# define READ_WRITE O_RDWR
# define CREATE O_CREAT
# define TRUNCATE O_TRUNC
# define APPEND O_APPEND

#endif

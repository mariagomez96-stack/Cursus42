/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:07:42 by marigome          #+#    #+#             */
/*   Updated: 2024/06/12 11:28:12 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

// =======================================================
// To fix the visibility of the sigaction structure
// =======================================================
# include <unistd.h>

# ifndef _POSIX_C_SOURCE
#  define _POSIX_C_SOURCE 199309L
# endif

// =======================================================
// Access to my libraries
// =======================================================
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
// ===========================

// =======================================================
// Libraries
// =======================================================
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <time.h>

# define RED        "\033[0;31m"
# define GREEN      "\033[0;32m"
# define YELLOW     "\033[0;33m"
# define BLUE       "\033[0;34m"
# define MAGENTA    "\033[0;35m"
# define CYAN       "\033[0;36m"
# define WHITE      "\033[0;37m"
# define ORANGE     "\033[1;31m"

// # Bold
# define BDBLACK    "\033[1;30m"
# define BDRED      "\033[1;31m"
# define BDGREEN    "\033[1;32m"
# define BDYELLOW   "\033[1;33m"
# define BDBLUE     "\033[1;34m"
# define BDMAGENTA  "\033[1;35m"
# define BDCYAN     "\033[1;36m"
# define BDWHITE    "\033[1;37m"

// # Underline
# define ULRED      "\033[4;31m"
# define ULGREEN    "\033[4;32m"
# define ULYELLOW   "\033[4;33m"
# define ULBLUE     "\033[4;34m"
# define ULMAGENTA  "\033[4;35m"
# define ULCYAN     "\033[4;36m"
# define ULWHITE    "\033[4;37m"

// # Lines, fills, miscellany
// # (see graphics bellow)
# define EQLIN      "\u2550"
# define LSHADE     "\u2591"
# define MSHADE     "\u2592"
# define HSHADE     "\u2593"
# define FBLOCK     "\u2588"
# define EBLOCK     "\u258d"
# define ARROWRG    "\u2911"

// EQLIN    ═══════════════════
// LSHADE   ░░░░░░░░░░░░░░░░░░░
// MSHADE   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
// HSHADE   ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
// FBLOCK   ███████████████████
// EBLOCK   ▍▍▍▍▍▍▍▍▍▍▍▍▍▍▍▍▍▍▍
// ARROWRG  ⤑⤑⤑⤑⤑⤑⤑⤑⤑⤑⤑⤑⤑⤑

// Define messages
// =======================================================
# define MSG_ARG_1 "Arguments missing"
# define MSG_ARG_2 "Too many Arguments"
# define MSG_PID_1 "Could not generate the PID"
# define MSG_PID_2 "Invalid PID"
# define MSG_WAR_1 "Delivery failed"
# define MSG_INF_1 "Info message 1"
# define MSG_SUC_1 "Succees message"

#endif
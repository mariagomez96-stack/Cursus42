/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macros.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:22:32 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/15 17:30:30 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MACROS_H
# define FT_MACROS_H

/**
 * Standard image sizes in pixels
 * 	1920 * 1080 HDTV, 16:9, presentations, RRSS images
 *  1280 * 720 HD, 16:9, photography and cinema
 *  1080 * 1080 RRSS publications and profile images, 1:1
 * 
 */
# define DEFWIDTH			1280
# define DEF_HEIGHT			720
# define WIDTH					1920
# define HEIGHT					1080

# define DEFAULT_MENU_WIDTH		250
# define M_PI					3.14159265358979323846

# define INIT_ERR				"42FdF : ==> "
# define NUM_ARGV_ERR			"❗1️⃣ Incorrect number of arguments, expected \
								one."
# define OPEN_ERR				"📖 Error opening source file!!!"
# define CLOSED_ERR				"📚 Error closing source file!!!"
# define SHORT_NAME_ERR			"🗺️ Map name is very short!!!"
# define EXT_ERR				"❌ⓔⓧⓣ File extension error!!!"
# define MALLOC_ERR				"❌Ⓜⓐⓛⓛⓞⓒ Error creating malloc!!!"
# define MLX_ERR 				"4️⃣2️⃣📈📉 Error connecting to graphics server \
								MLX42!!!"
# define IMG_ERR 				"❌4️⃣2️⃣🎞️ Error initializing image MLX42!!!"
# define INIT_MAP_ERR			"🌎 Error initializing map!!!"
# define MATRIX1_ERR			"🔛 Wrong matrix line width!!!"
# define MATRIX2_ERR			"❗🔛 FdF file has irregular width!!!"
# define MLLC_CAM_ERR			"📽️ Error ailed to allocate memory for \
								camera!!!"

# define MOUSE_CLICK_LEFT		1
# define MOUSE_CLICK_RIGHT		2
# define MOUSE_CLICK_MIDDLE		3
# define MOUSE_WHEEL_UP			4
# define MOUSE_WHEEL_DOWN		5
# define MLX_MOTION				6


#endif
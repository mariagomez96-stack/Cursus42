/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:18:19 by marigome          #+#    #+#             */
/*   Updated: 2024/09/12 15:54:50 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_manage_hook" Configure hooks for keyboard, window closing 
 * and mouse.
 * 
 * @param t_fdf	*rol 				rol instance created in fdf.c.
 * 
 * 
 * The function "ft_mouse_hook" mouse event handling.
 * 
 * -action- handles all mouse events
 * 
 * @param mouse_key_t button		identifies which mouse button has been 
 * 									pressed.
 * @param action_t action			Describes the action that has taken place,
 * 									similar to what happens with the keyboard.
 * 									Values ​​can be MLX_PRESS (button pressed) 
 * 									or MLX_RELEASE (button released).
 * @param modifier_key_t mods		Represents the keyboard modifiers that were
 * 									active when the mouse event occurred, such 
 * 									as Shift, Ctrl, etc. This parameter can be 
 * 									used to detect if modifier keys were being 
 * 									pressed when the mouse was clicked.
 * @param void *param				It is used to pass a pointer to the t_fdf 
 * 									structure. It is cast to be able to access 
 * 									the elements of the rol structure and 
 * 									update the cam or redraw the scene.
 * 
 * 
 * The function "ft_close_hook" window close event management.
 * 
 * Note. "mlx_close_window" closes the window when the X is closed.
 * 
 * @param void *param				It is cast to be able to close the window 
 * 									using mlx_close_window(role->mlx).
 * 
 * 
 * The function "ft_key_hook" keyboard event management.
 * 
 * Inside the if statement relative to action, you can add more keyboard 
 * controls like moving the cam, rotating, etc.
 * 
 * @param mlx_key_data_t keydata	Contains information about the keyboard 
 * 									event that has occurred.
 * @param void *param				This pointer is cast to a pointer of type
 * 									t_fdf to access the elements of the rol 
 * 									structure.
 * 
 */



static void ft_free_img_cam(t_fdf *fdf)
{
    if (!fdf)
        return ;
    if (fdf->cam)
    {
        free(fdf->cam);
        fdf->cam = NULL;
    }
    if (fdf->image)
    {
        mlx_delete_image(fdf->mlx, fdf->image);
        fdf->imgstatic = NULL;
    }
}

static void mouse_move_events(t_fdf *fdf, int x, int y)
{
    if (fdf->mouse->button == MOUSE_CLICK_RIGHT)
    {
        fdf->cam->x_ang += (y - fdf->mouse->prev_y) * 0.002;
        fdf->cam->y_ang += (x - fdf->mouse->prev_x) * 0.002;
        ft_reset_ang(&fdf->cam->x_ang);
        ft_reset_ang(&fdf->cam->y_ang);
        fdf->mouse->prev_x = x;
        fdf->mouse->prev_y = y;
        ft_draw(fdf->map, fdf);
    }
    else if (fdf->mouse->button == MOUSE_CLICK_LEFT)
    {
        fdf->cam->x_offset += (x - fdf->mouse->prev_x);
        fdf->cam->y_offset += (y - fdf->mouse->prev_y);
        fdf->mouse->prev_x = x;
        fdf->mouse->prev_y = y;
        ft_draw(fdf->map, fdf);
    }
}

static void ft_press_scape(mlx_key_data_t keydata, void *param)
{
    t_fdf   *fdf;

    fdf = (t_fdf *)param;
    if (fdf->mlx && keydata.action == MLX_PRESS && keydata.key == MLX_KEY_ESCAPE)
        mlx_close_window(fdf->mlx);
}

static void ft_close(void *param)
{
    t_fdf   *fdf;

    fdf = (t_fdf *)param;
    if (fdf)
    {
        if (fdf->mlx)
        {
            mlx_close_window(fdf->mlx);
            fdf->mlx = NULL;
        }
        ft_free_img_cam(fdf);
        free(fdf);
        fdf = NULL;
    }
}

static void	ft_cam_move(int button, t_fdf *rol)
{
	if (button == 1 || button == 3)
	{
		if (button == 1)
			rol->cam->zoom += 2;
		else if (button == 3)
			rol->cam->zoom -= 2;
		if (rol->cam->zoom < 1)
			rol->cam->zoom = 1;
		ft_draw(rol->map, rol);
	}
}

static void ft_mouse_hook(mouse_key_t button, action_t action, modifier_key_t \
mods, void *param)
{
	t_fdf	*fdf;
	int		x;
	int		y;

	(void) mods;
	fdf = (t_fdf *)param;
	x = fdf->mouse->current_x;
	y = fdf->mouse->current_y;

	if (action == MLX_PRESS && (button == 1 || button == 3))
		ft_cam_move(button, fdf);
	else if (action == MLX_PRESS || action == MLX_RELEASE) // release = dejar de pulsar //
	{
		if (button >= MLX_MOUSE_BUTTON_LEFT && button <= \
		MLX_MOUSE_BUTTON_MIDDLE)
		{
			if (action == MLX_PRESS)
			{
				fdf->mouse->button = button;
				fdf->mouse->prev_x = x;
				fdf->mouse->prev_y = y;
			}
			else if (action == MLX_RELEASE)
				fdf->mouse->button = 0;
		}
	}
	else if (action == MLX_MOTION && fdf->mouse->button != 0)
		mouse_move_events(fdf, x, y);
}

/*static void close_window(void *param)
{
    t_fdf *fdf = (t_fdf *)param;
    mlx_close_window(fdf->mlx);  // Cierra la ventana
}*/

void    manage_moves(t_fdf *fdf)
{
    mlx_key_hook(fdf->mlx, &ft_press_scape, fdf);
    mlx_close_hook(fdf->mlx, &ft_close, fdf);
    mlx_mouse_hook(fdf->mlx, ft_mouse_hook, fdf);
}
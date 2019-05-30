# smlx

Description:
	- This Library is sketcher extend from minilibx_macos(made by Olivier Crouzet) which handle multiples windows
		and trigger customizable events (like keyboard and mouse)

Requirements:

	- libft --> (git clone https://lloyet@bitbucket.org/lloyet/libft.git)
	- minilibx_macos --> (git clone https://lloyet@bitbucket.org/lloyet/minilibx.git)
	- libhook --> (git clone https://lloyet@bitbucket.org/lloyet/libhook.git)
	- payload --> (git clone https://lloyet@bitbucket.org/lloyet/payload.git)

Features:

	- Handle customizable windows (width, heigh)
	- Trigger keyboard and mouse events with key statements and edge.
	- Handle User's event function from separte windows

How To:

	- IMAGE:

		1) Create an image define by the width and heigh (By default the image dock at x:0 and y:0):

			t_image			*new_image(void *mlx_id, int width, int heigh);

		2) Modify docking position into the window:

			void			image_dock(t_image *img, int x, int y);

		3) Draw a pixel into an image or fill it:

			void			image_pixel_put(t_image *img, int x, int y, int color);
			void			image_fill(t_image *img, int color);

	- WINDOWS:

		1) Create (NOT OPEN) a window from the background image:

			t_window		*new_window(void *mlx_id, t_image *bg, char *title, int (*event)(void*));

		2) Add or remove an image to/from a window:

			void			window_add_image(t_window *win, t_image *img);
			void			window_del_image(t_window *win, t_image *img);

		3) Refresh image stack of a window

			void			window_refresh(t_window *win);

	- FRAMEWORK:

		1) Create sketch framework:

			t_framework		*new_framework(void);

		2) Initalize framework:

			int				framework_init(t_framework *mlx, t_window *win);

		3) Open And Close Windows previously created with exemples explain before:

			void			framework_open_window(t_framework *mlx, t_window *win);
			void			framework_close_window(t_framework *mlx, t_window *win);

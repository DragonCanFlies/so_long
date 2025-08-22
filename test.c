#include "mlx.h"

// gcc test.c -Imlx_linux -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o test

int	main(void)
{
	void	*mlx;
	void	*win;

	// establish a connection to the correct graphical system and 
	// will return a void * which holds the location of our current MLX instance
	mlx = mlx_init();
	if (!mlx)
		return (1);

	// Create a window (width=800, height=600, title="Hello MLX")
	// returns a pointer to the window
	win = mlx_new_window(mlx, 800, 600, "Hello MLX");
	if (!win)
		return (1);

	// Keep window open, wait for events
	mlx_loop(mlx);

	return (0);
}

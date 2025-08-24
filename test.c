#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

// gcc test.c -Imlx_linux -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o test

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
}				t_mlx_data;

int	handle_input(int key, t_mlx_data *data)
{
	if (key == 97)
	{
		printf("Exit the game\n");
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
	printf("Key number %i\n", key);
	return (0);
}

int	main(void)
{
	t_mlx_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);

	data.win = mlx_new_window(data.mlx, 800, 600, "Hello MLX");
	if (!data.win)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		return (1);
	}

	mlx_key_hook(data.win, handle_input, &data);
	
	mlx_loop(data.mlx);
	
	return (0);
}

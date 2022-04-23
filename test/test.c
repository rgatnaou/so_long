// #include<mlx.h>
// #include<unistd.h>

// // int main()
// // {
// 	// void	*ptr;
// 	// void	*win;
// 	// int		x = 250;
// 	// int		y =150;
// 	// int		i = 251;

// 	// ptr = mlx_init();
// 	// win = mlx_new_window(ptr,500,500,"redouane");
// 	// while(y < 350)
// 	// {
// 	// 	x = 250 ;
// 	// 	while(x < i)
// 	// 	{
// 	// 		mlx_pixel_put(ptr,win,x,y,0x00FF0000);
// 	// 		x++;
// 	// 	}
// 	// 	i++;
// 	// 	y++;
// 	// }
// 	// mlx_loop(ptr);

// 	/**********************************************************************/
	
// // }

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;
// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }
// #include <stdlib.h>
// #include <stdio.h>
// // int	key_hook(int keyint x, int y)
// // {
// // 	// (void)vars;
// // 	// if (keycode == 17)
// // 	// {
// // 	// 	printf("hi\n");
// // 	// }
// // 	if ()
// // 	return (0);
// // }
// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	float 	i =0;
// 	float 	j;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world!");
// 	img.img = mlx_new_image(mlx, 1000, 1000);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	while(i < 1000)
// 	{
// 		j = 0;
// 		while(j < 1000)
// 		{
// 			if ((i - 500)*(i - 500) + (j - 500)*(j - 500) <= 201 * 201 && (i - 500)*(i - 500) + (j - 500)*(j - 500) >= 190 * 190 )
// 				my_mlx_pixel_put(&img, i, j, 0x00FFFFFF);
// 			j++;
// 		}
// 		i++;
// 	}
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	// my_mlx_pixel_put(&img, 10, 10, 0x00FF0000);
// 	// mlx_key_hook(mlx_win, key_hook, &img);
// 	//mlx_mouse_hook(mlx_win, key_hook, &img);
// 	mlx_loop(mlx);
// }
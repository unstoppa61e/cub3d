#include "graphics.h"

static SDL_Window	*window = NULL;
static SDL_Renderer	*renderer = NULL;
static uint32_t		*colorBuffer = NULL;
static SDL_Texture	*colorBufferTexture;

bool	initializeWindow(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == SDL_ERROR)
	{
		ft_putstr_fd("Error initializing SDL.\n", STDERR_FILENO);
		return (false);
	}
	SDL_DisplayMode display_mode;
	SDL_GetCurrentDisplayMode(0, &display_mode);
	int	fullScreenWidth = display_mode.w;
	int	fullScreenHeight = display_mode.h;
	window = SDL_CreateWindow
	(
		NULL,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		fullScreenWidth,
		fullScreenHeight,
		SDL_WINDOW_BORDERLESS
	);
	if (window == NULL)
	{
		ft_putstr_fd("Error creating SDL window.\n", STDERR_FILENO);
		return (false);
	}
	renderer = SDL_CreateRenderer(window, DEFAULT_GRAPHIC_DRIVER, 0);
	if (renderer == NULL)
	{
		ft_putstr_fd("Error creating SDL renderer.\n", STDERR_FILENO);
		return (false);
	}
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	colorBuffer = malloc(sizeof(uint32_t) * (uint32_t)WINDOW_WIDTH * (uint32_t)WINDOW_HEIGHT);
	//	create an SDL Texture to display the colorbuffer
	colorBufferTexture = SDL_CreateTexture(
		renderer,
		SDL_PIXELFORMAT_RGBA32,
		SDL_TEXTUREACCESS_STREAMING,
		WINDOW_WIDTH,
		WINDOW_HEIGHT
	);
	return (true);
}

void	destroyWindow(void)
{
	free(colorBuffer);
	SDL_DestroyTexture(colorBufferTexture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void	clearColorBuffer(t_color color)
{
	int	index;

	index = 0;
	while (index < WINDOW_WIDTH * WINDOW_HEIGHT)
	{
		colorBuffer[index] = color;
		index++;
	}
}

void	renderColorBuffer(void)
{
	// second parameter -> the rectangle I want to update. This time, entire -> null
	SDL_UpdateTexture
	(
		colorBufferTexture,
		NULL,
		colorBuffer,
		(int)(WINDOW_WIDTH * sizeof(t_color))
	);
	//	from NULL to NULL -> the entire texture
	SDL_RenderCopy(renderer, colorBufferTexture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void	drawPixel(int x, int y, t_color color)
{
	colorBuffer[(WINDOW_WIDTH * y) + x] = color;
}

void	drawRect(int x, int y, int width, int height, t_color color)
{
	int	xi;
	int	yi;

	yi = y;
	while (yi < y + height)
	{
		xi = x;
		while (xi < x + width)
		{
			drawPixel(xi, yi, color);
			xi++;
		}
		yi++;
	}
}

void	drawLine(int x0, int y0, int x1, int y1, t_color color)
{
	int		deltaX;
	int		deltaY;
	int		longerSideLength;
	int		index;
	float	xIncrement;
	float	yIncrement;
	float	currentX;
	float	currentY;

	deltaX = (x1 - x0);
	deltaY = (y1 - y0);
	longerSideLength = (abs(deltaX)) >= abs(deltaY) ? abs(deltaX) : abs(deltaY);
	xIncrement = deltaX / (float)longerSideLength;
	yIncrement = deltaY / (float)longerSideLength;
	currentX = x0;
	currentY = y0;
	index = 0;
	while (index < longerSideLength)
	{
		drawPixel(round(currentX), round(currentY), color);
		currentX += xIncrement;
		currentY += yIncrement;
		index++;
	}
}
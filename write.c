#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
}

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i++]);	
	}
	return (i);
}

int	ft_isansi(char *s)
{
	if (s[0] == '0' && s[1] == '3' && s[2] == '3')
		return (1);
	return (0);
}

void	ft_putstrwinfix(char *s)
{
	int i;
	
	i = 0;
	while (s[i])
	{
		if (s[i] == '\\')
		{
			i++;
			if (s[i] == '\\')
			{
				ft_putchar('\\');
				i++;
			}
			if (s[i] == 'n')
			{
				ft_putchar('\n');
				i++;
			}
			else if (ft_isansi(&s[i]))
			{
				ft_putchar('\033');
				i += 3;
			}
		}
		else
		{
			ft_putchar(s[i++]);	
		}
	}
}

int	main(int c, char **v)
{
	c--;
	while (c)
		ft_putstrwinfix(v[c--]);
	return (0);
}

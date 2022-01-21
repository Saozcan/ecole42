
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);

int	ft_chrcounter(char *s, int c)
{
	int count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			count++;
		s++;
	}
	return (count);
}

static char	*get_next_line_clean(char **str)
{
	char	*buff;
	char	*tmp;
	size_t	i;

	buff = *str;
	//printf("first,%s\n", *str);
	if (buff == 0)
		return (0);
	if ((buff[ft_strlen(buff) - 1] == '\n' && ft_chrcounter(*str, '\n') == 1) || ft_chrcounter(*str, '\n') == 0)
	{
		buff = ft_strdup(*str);
		*str = NULL;
		return (buff);
	}
	i = ft_strlen(*str) - ft_strlen(ft_strchr(*str, '\n'));
	printf("%zu\n",i);
	//buff = (char *)malloc((i + 2) * sizeof(char));
	//if (!buff)
	//	return (0);
	buff = ft_substr(*str, 0, i + 1);
	tmp = *str;
	*str = ft_substr(*str + i + 1, 0, ft_strlen(*str + i + 1));
	free(tmp);
	//printf("second,%s\n...", *str);
   	return (buff);
}

static char	*read_first_line(int fd, char *buff, char **str)
{
	int 	i;
	char 	*tmp;

	i = read(fd, buff, BUFFER_SIZE);
	//printf("buff...%s\n...", buff);
	//printf("%d\n", i);
	while(i > 0)
	{
		if (!*str)
			*str = ft_substr(buff, 0, BUFFER_SIZE + 1);
		else
		{
			tmp = *str;
			*str = ft_strjoin(*str, buff);
			//printf("inRead   %s\n...", buff);
			free(tmp);
		}
		if (ft_strchr(*str, '\n') || *str == 0)
			break ;
		i = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (get_next_line_clean(str));
}

char	*get_next_line(int fd)
{
	static char	*str = 0;
	char		*returnbuff;
	int 		i;

	i = 0;
	returnbuff = (char *)calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!returnbuff)
		return (0);
	if (fd == -1 || read(fd, returnbuff, 0) == -1 || BUFFER_SIZE <= 0)
	{
		free(returnbuff);
		return (0);
	}
	return 	(read_first_line(fd, returnbuff, &str));
}

#include <stdio.h>

int	main(void)
{
	int fd;

	fd = open("text.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	/*printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));*/
	close(fd);
}
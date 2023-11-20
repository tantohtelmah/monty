#include "monty.h"
/**
* _strcmp - Function that compares two strings.
* @s1: type str compared
* @s2: type str compared
* Return: 0 if s1 and s2 are equals.
*/
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/**
* _search - search if a char is inside a string
* @s: string to review
* @c: char to find
* Return: 1 if success 0 if not
*/
int _search(char *s, char c)
{
	int cont = 0;

	while (s[cont] != '\0')
	{
		if (s[cont] == c)
		{
			break;
		}
		cont++;
	}
	if (s[cont] == c)
		return (1);
	else
		return (0);
}

/**
* _strtoky - function that cut a string into tokens depending of the delimit
* @s: string to cut in parts
* @d: delimiters
* Return: first partition
*/
char *_strtoky(char *s, char *d)
{
	static char *ultimo;

	int i = 0, j = 0;

	if (!s)
		s = ultimo;
	while (s[i] != '\0')
	{
		if (_search(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			ultimo = s + i + 1;
			*ultimo = '\0';
			s = s + j;
			return (s);
		}
		else if (_search(d, s[i]) == 0 && _search(d, s[i + 1]) == 0)
			i++;
		else if (_search(d, s[i]) == 0 && _search(d, s[i + 1]) == 1)
		{
			ultimo = s + i + 1;
			*ultimo = '\0';
			ultimo++;
			s = s + j;
			return (s);
		}
		else if (_search(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}

/**
* _getline - gets a line from a stream
* @lineptr: string to cut in parts
* @n: delimiters
* @stream: file stream
* Return: ssize_t
*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t nread;
	size_t len = 0;
	char *line = NULL;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}

	while ((nread = _getline(&line, &len, stream)) != -1)
	{
		if (*lineptr == NULL)
		{
			*lineptr = line;
		} else
		{
			*lineptr = realloc(*lineptr, *n + nread);
			strcat(*lineptr, line);
		}
		*n += nread;

		if (line[nread - 1] == '\n')
		{
			break;
		}
	}

	free(line);

	if (*n == 0)
	{
		return (-1);
	}

	return (*n);
}

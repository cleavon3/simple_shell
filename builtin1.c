#include "shell.h"
/**
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments
 * Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}
/**
 * unset_alias - unsets an alias.
 * @info: Parameter structure
 * @str: String alias
 * Return: Success - 0, Error - 1
 */
int unset_alias(info_t *info, char *str)
{
	char *q, s;
	int ret;

	q = strchr(str, '=');

	if (!q)
		return (1);

	s = *q;
	*q = 0;

	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));

	*q = s;

	return (ret);
}

/**
 * set_alias - sets an alias to a string.
 * @info: Parameter structure
 * @str: String alias
 * Return: On success - 0, On error - 1
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = strchr(str, '=');

	if (!p)
		return (1);

	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);

	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string.
 * @node: Alias node
 * Return: On success - 0, On error - 1
 */
int print_alias(list_t *node)
{
	char *q = NULL, *b = NULL;

	if (node)
	{
		q = strchr(node->str, '=');
		for (b = node->str; b <= q; b++)
			_putchar(*b);
		_putchar('\'');
		_puts(q + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias).
 * @info: Structure containing arguments
 * Return: Always 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *q = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}

	for (i = 1; info->argv[i]; i++)
	{
		q = strchr(info->argv[i], '=');
		if (q)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}
	return (0);
}


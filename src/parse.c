

int parse_line(t_store* st, char *line)
{
    int i;
    
    while (line)
    {
        if (line[i] != ft_isdigit && line[i] != ft_is)
    }

}

static void	ft_check_format(char *name)
{
	char	*format;

	format = ".rt";
	while (*name != '.' && *name != '\0')
		name++;
	if (*name == '\0')
		ft_error("Error\nInvalid scene\n");
	if (*name == '.')
	{
		if (ft_strncmp(name, format, 4) != 0)
			ft_error("Error\nInvalid scene\n");
	}
}

void parse(t_store* st,  char* rt_file)
{
    int fd;
    char *line;

    check_format(rt_file);
    fd = open(rt_file, O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        if (parse_line(line))
            ft_error("Error\nInvalid scene\n");
        free(line);
        get_next_line(fd);
    }
    free(line);
    close(fd);
    return (0);
}

// количество аргументов проверяем в main

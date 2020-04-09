int		flag_doublon(char *spec)
{
	int i; 
	int sign;

	i = 0;
	while (spec[i] != '\0')
	{
		 spec[i] == '-' && spec[i++] == '0' ? sign = 1: sign;
		spec[i] == '+' && spec[i++] == ' ' ? sign = 2: sign;
		i++;
	}
	return (sign)
}
void	flag_exist(char *spec)
{
 	int i; 
	i = 0;
	while (spec[i] != '\0')
	{
		if (spec[i] == '+')
			spec->plus = 1;
		if (spec[i] == '-')
			spec->moins = 1;
		if (spec[i] == '0') 
			spec->zero = 1;
		if (spec[i] == ' ') 
			spec->space = 1;
		if (spec[i] == '#')
			spec->hash = 1;
		i++;
	}
	return (0);
}
int 	width_min(char *spec)
{
	char arg;
	int spec->len;
	int spec->len_arg;
	spec->len_arg = ft_strlen(arg);
	spec->len = int_in_str(spec);
	space = spec->len - spec->len_arg;
	if (spec->len_arg < spec->len)
	{
		fill_space(space - 1) // char² 
		fill_space(space);
	}	
	return (0);


int 	flag_simple(char *spec, int sign)
{
	if (sign == 1)
		ft_strjoin(fill_space(len,s),arg);
	if (sign == 2)
		write(1,'+',1);
	if (flag->plus)
		write(1,'+',1);
	if (flag->moins)
		ft_strjoin(s,fill_space(len,s);
	if (flag->zero)
		fill_0(len,s);
	if (flag->space)
		write(1,' ',1);
}


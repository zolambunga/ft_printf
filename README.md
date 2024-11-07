# ft_printf
A basic implementation of the Printf function from C language

follow this to help you in adding other flags in the code


<script>
#include <stdio.h>

int main()
{
	int	num = 42;
	float	pi = 3.14159;
	int	hex_num = 255;
	char	*str = "Oi";
	printf("|%-10s|\n", str);
	printf("|%010d|\n", num);
	printf("|%.2f|\n", pi);
	printf("|% d|\n", num);
	printf("|%#x|\n", hex_num);
	printf("|%+d|\n", num);
	return (0);
}
</script>

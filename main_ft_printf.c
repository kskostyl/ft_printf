/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:42:31 by tkatolik          #+#    #+#             */
/*   Updated: 2019/07/30 20:48:31 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			main()
{
	int		i = 1735;
	int		a = -4200;
	int		b = 90009;
	
	//ouxX
	unsigned int			o = 16392;
	unsigned int			u = UINT_MAX;
	unsigned int			x = 163392;
	unsigned long long		ull = ULLONG_MAX;
	long long				ll = 235897998;
	long					l = 99999;
	unsigned char			uc = 245;

	//psc
	char					*adr = "String Var";
	char					ch = 'Y';

	//fGeE
	float					f = 123.456789;
	float					e = 0.40;
//	float					f2 = 123.8889999324814;
	double					dbl = -5145.10939400444;
	double					e2 = -1859.939400444;
	long double				ldbl = 123049851.23898420983222;
	long double				e3 = -123049851.23898420983222;
//	long double				ldbl2 = 123049851.1298;

	char 					*str;

	str = "hello";
	ft_printf("---------- TEST PART 1: clean string, i, %% --------------\n\n");

	printf("%s\n", str);
	ft_printf("%s\n\n", str);
	printf("1: %-10i 2: %c 3: %+.15i kek\n\n", i, ch, b);
	ft_printf("1: %-10i 2: %c 3: %+.15i kek\n\n", i, ch, b);

	printf("Only string\n");
	ft_printf("Only string\n");
//	system("leaks a.out");
	printf("string + persent %%\n");
	ft_printf("string + persent %%\n");
	printf("string + int %i\n", i);
	ft_printf("string + int %i\n", i);
	printf("string + 3 int %i second: %i third: %i kek\n", i, a, b);
	ft_printf("string + 3 int %i second: %i third: %i kek\n\n", i, a, b);

//	system("leaks a.out");

	ft_printf("---------- TEST PART 2: ouxX -----------------------------\n\n");

	printf("test 'o': %o, test 'u': %u, test 'x': %x, test 'X': %X\n", 
			o, u, x, x);
	ft_printf("test 'o': %o, test 'u': %u, test 'x': %x, test 'X': %X\n\n", 
			o, u, x, x);

	printf("test 'lo': %lo, test 'llu': %llu, test 'llx': %llx, test 'hhX': %hhX\n", 
			l, ull, ll, uc);
	ft_printf("test 'lo': %lo, test 'llu': %llu, test 'llx': %llx, test 'hhX': %hhX\n\n",
			l, ull, ll, uc);

	ft_printf("---------- TEST PART 2: csp ------------------------------\n\n");

	printf("test address: %p, char: %c, string %s, sting as arg: %s\n", 
			adr, ch, adr, "direct string");
	ft_printf("test address: %p, char: %c, string %s, sting as arg: %s\n\n", 			adr, ch, adr, "direct string");

//	system("leaks a.out");

	ft_printf("---------- TEST PART 3: %%f ------------------------------\n\n");

	printf("test float: %f, double: %f, Ldouble %Lf\n", 
			f, dbl, ldbl);
	ft_printf("test float: %f, double: %f, Ldouble %Lf\n", 
			f, dbl, ldbl);
	printf("test float: %.15f, double: %.15f, Ldouble %.15Lf\n", 
			f, dbl, ldbl);
	ft_printf("test float: %.15f, double: %.15f, Ldouble %.15Lf\n\n", 
			f, dbl, ldbl);

	ft_printf("---------- TEST PART 4: flags for pcs --------------------\n\n");

	printf("test address: %-18p$, char: %4c$\n, string %8.5s$, sting as arg: %-15.10s$\n", 
			adr, ch, adr, "direct string");
	ft_printf("test address: %-18p$, char: %4c$\n, string %8.5s$, sting as arg: %-15.10s$\n\n", 
			adr, ch, adr, "direct string");

	ft_printf("---------- TEST PART 5: flags for idouxXf ----------------\n\n");

	printf("1: %-10i 2: %.2i 3: %+.15i kek\n", i, a, b);
	ft_printf("1: %-10i 2: %.2i 3: %+.15i kek\n\n", i, a, b);

	printf("1: %#-10x 2: %#.2X 3: %#.15X 4: %20.15X 5: %15.20X\n", i, a, b, a, a);
	ft_printf("1: %#-10x 2: %#.2X 3: %#.15X 4: %20.15X 5: %15.20X\n\n", i, a, b, a, a);
	
	printf("1: %+-10d 2: %020.2o 3: %+.15d 4: %0.15X\n", i, a, b, i);
	ft_printf("1: %+-10d 2: %020.2o 3: %+.15d 4: %0.15X\n\n", i, a, b, i);

	printf("1: %+-12.7f 2: %#020.2o 3: %+010.8f 4: %#0.15X\n", dbl, a, f, i);
	ft_printf("1: %+-12.7f 2: %#020.2o 3: %+010.8f 4: %#0.15X\n\n", dbl, a, f, i);
	printf("1: %#-12.7x 2: %-#20.2o 3: %#010.14x 4: %#010.5X\n", b, a, a, i);
	ft_printf("1: %#-12.7x 2: %-#20.2o 3: %#010.14x 4: %#010.5X\n", b, a, a, i);

	ft_printf("---------- BUG FIX ------------- BUG FIX -----------------\n\n");

	printf("(%d)\n", printf("%0+5d", -42));
	printf("(%d)\n", ft_printf("%0+5d", -42));
	printf("(%d)\n", printf("%0+5.15d", -42));
	printf("(%d)\n", ft_printf("%0+5.15d", -42));
	printf("(%d)\n", printf("%5d", -42));
	printf("(%d)\n", ft_printf("%5d", -42));
	printf("(%d)\n", printf("%05d", -42));
	printf("(%d)\n", ft_printf("%05d", -42));
	printf("(%d)\n", printf("%+10.5d", 4242));
	printf("(%d)\n", ft_printf("%+10.5d", 4242));
	printf("(%d)\n", printf("%0+5d", 42));
	printf("(%d)\n", ft_printf("%0+5d", 42));
	printf("(%d)\n", printf("%#010x", 42));
	printf("(%d)\n", ft_printf("%#010x", 42));
	printf("(%d)\n", printf("%03.2d", -1));
	printf("(%d)\n", ft_printf("%03.2d", -1));
	printf("(%d)\n", printf("%.10d", -42));
	printf("(%d)\n\n", ft_printf("%.10d", -42));

	printf("(%d)\n", printf("%.d %.0d", 0, 0));
	printf("(%d)\n", ft_printf("%.d %.0d", 0, 0));
	printf("(%d)\n", printf("%5.d %5.0d", 0, 0));
	printf("(%d)\n", ft_printf("%5.d %5.0d", 0, 0));
	printf("(%d)\n", printf("%5.0d", 0));
	printf("(%d)\n\n", ft_printf("%5.0d", 0));

	ft_printf("---------- BUG FIX SEGFOULTS-----------------------------\n\n");

	printf("(%d)\n", printf("%5.0d", 0));
	printf("(%d)\n\n", ft_printf("%5.0d", 0));
	printf("(%d)\n", printf("%U", u));
	printf("(%d)\n\n", ft_printf("%u", u));
	printf("(%d)\n", printf("%c", 0));
	printf("(%d)\n\n", ft_printf("%c", 0));

	ft_printf("---------- BONUS STARTRACK ------------------------------\n\n");

	printf("(%d)\n", printf("%+10.5d", 4242));
	printf("(%d)\n", ft_printf("%+10.5d", 4242));
	printf("(%d)\n", printf("%+*.*d", 10, 5, 4242));
	printf("(%d)\n", ft_printf("%+*.*d", 10, 5, 4242));

	ft_printf("---------- FLOAT    ROUNDING ----------------------------\n\n");

	
	printf("test float: %-10.15f, double: %f, Ldouble %Lf\n", 
			f, dbl, ldbl);
	ft_printf("test float: %-10.15f, double: %f, Ldouble %Lf\n", 
			f, dbl, ldbl);
	printf("test float: %.25f, double: %05.25f, Ldouble %-.25Lf\n", 
			f, dbl, ldbl);
	ft_printf("test float: %.25f, double: %05.25f, Ldouble %-.25Lf\n\n", 
			f, dbl, ldbl);
	
	ft_printf("---------- FLOAT e E g G ? ------------------------------\n\n");

	printf("test float: %e, double: %e, Ldouble %Le\n", e, e2, e3);
	ft_printf("test float: %e, double: %e, Ldouble %Le\n", e, e2, e3);
	printf("%.15Le\n", e3);
	ft_printf("%.15Le\n", e3);

	printf("test float: %10.15e, double: %015.1f, Ldouble %015.1Lf\n", e, e2, e3);
	ft_printf("test float: %10.15e, double: %015.1f, Ldouble %015.1Lf\n", e, e2, e3);
	printf("--test: %10.15i, double: %-15.10i, Ldouble %015.1i\n", i, a, b);
	ft_printf("--test: %10.15i, double: %-15.10i, Ldouble %015.1i\n", i, a, b);

	printf("e float: %+10.15e, double: %+015.1e, Ldouble %+015.1Le\n", e, e2, e3);
	ft_printf("e float: %+10.15e, double: %+015.1e, Ldouble %+015.1Le\n", e, e2, e3);
//	system("leaks a.out");
	return (0);
}

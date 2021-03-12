# Printf_tester

![GitHub release (latest by date)](https://img.shields.io/github/v/release/hilmi-yilmaz/printf_tester?logo=GitHub)
![GitHub last commit](https://img.shields.io/github/last-commit/hilmi-yilmaz/printf_tester)
![GitHub issues](https://img.shields.io/github/issues-raw/hilmi-yilmaz/printf_tester)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

![Tester output gif](./imgs/gif.gif)

>:warning:**Don't use this tester while writing your code. To be a good programmer, you should write your own tests. This tester is intended as a last check for your project, to see whether you missed some testcases.**

## :rocket: Description

This is a tester for the ft_printf project in 42's curriculum. It contains 800+ tests and is made with the user in mind. It is very easy to use after a small setup. It is also very easy to see which test cases you failed (see figure above).

It only tests for:<br>
1. "cspdiuxX%" conversions.
2. "0-" flags.
3. Width and precision (also with the '*' option).

**The output of printf on Linux and MacOS is different. Be aware of this. Make sure you test it on the iMacs! Below you can find some cases (not all) in which Linux and MacOS differ:**
```C
Precision used with s-conversion with NULL as input: printf("%.2s", NULL);
Width used with %-conversion: printf("%3%");
NULL as input with p-conversion: printf("%p", NULL);
```

## :gear: Installation and Setup

Clone this repository and go inside the project folder. Now we are going to create a symbolic to your ft_printf project. This makes it easy to debug. You can just work on your original project and these symbolic links will follow the changes you make to your original code. To create a symbolic link, run the following command from inside the _printf_tester_ directory:

```sh
ln -s path/to/your/ft_printf src
```

:warning: **Make sure you call the directory _src_.**

Your directory should look like this now:

![After linking](./imgs/link.png)

## :joystick: Usage

To run the tester on all testcases, simply run:

```sh
./printf_tester.sh
```

You can also choose a specific conversion test to run. In this case, it tests for the s-conversion:

```sh
./printf_tester.sh s
```


In the **logs/wrong_test_cases** file you can find all the testcases for which your project has failed.

## :compass: Roadmap
- Add more testcases.
- Improve error messages.

## :mailbox: Contribute

Found a bug? Ran into a specific problem? Missing a feature? Or you have some more testcases? Feel free to **file a new issue** with a respective title and description on the [issue page](https://github.com/hilmi-yilmaz/printf_tester/issues). You can also ask questions in [GitHub Discussion](https://github.com/hilmi-yilmaz/printf_tester/discussions). 

## :blue_book: License
[MIT](https://opensource.org/licenses/MIT)

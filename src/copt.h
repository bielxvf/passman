#ifndef _COPT_H
#define _COPT_H

#define _COPT_VERSION 0.1.0

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	const char *name;
	const char *s;
	const char *l;
	const char *usage;
	const char *params;
} copt_Option;

typedef struct {
	const char *name;
	const char *version;
	const char *usage;
	size_t options_size;
	copt_Option *options;
} copt_Program;

void copt_program_init(const char *name, const char *version,
		       const char *usage);
void copt_add_option(const char *optname, const char *s, const char *l,
		     const char *usage, const char *params);
bool copt_option_is(const char *optname, char **argv);
void copt_print_help();
void copt_print_version();

void _copt_option_print(const copt_Option *opt);

static copt_Program program = {0};

void copt_program_init(const char *name, const char *version, const char *usage)
{
	program.name = name;
	program.version = version;
	program.usage = usage;
	program.options_size = 0;
}

void copt_add_option(const char *optname, const char *s, const char *l,
		     const char *usage, const char *params)
{
	size_t Option_size = sizeof(copt_Option);

	copt_Option opt = {.name = optname,
			   .s = s,
			   .l = l,
			   .usage = usage,
			   .params = params};

	if (program.options_size == 0) {
		program.options_size++;
		program.options = malloc(Option_size * program.options_size);
	} else {
		program.options_size++;
		program.options = reallocarray(
			program.options, program.options_size, Option_size);
	}
	program.options[program.options_size - 1] = opt;
}

bool copt_option_is(const char *optname, char **argv)
{
	bool found = false;
	int i = 0;
	for (; i < program.options_size; i++) {
		if (!strcmp(optname, program.options[i].name)) {
			found = true;
			break;
		}
	}

	if (found
	    && (!strcmp(argv[1], program.options[i].s)
		|| !strcmp(argv[1], program.options[i].l))) {
		return true;
	}
	return false;
}

void copt_print_help()
{
	fprintf(stderr, "Usage: %s %s\n", program.name, program.usage);
	fprintf(stderr, "Options:\n");
	for (int i = 0; i < program.options_size; i++) {
		_copt_option_print(&program.options[i]);
	}
	exit(1);
}

void _copt_option_print(const copt_Option *opt)
{
	fprintf(stderr, "\t%s,%s %s\t%s\n", opt->s, opt->l, opt->params,
		opt->usage);
}

void copt_print_version()
{
	printf("version: %s\n", program.version);
}

#endif // _COPT_H

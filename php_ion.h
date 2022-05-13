/*
    +--------------------------------------------------------------------+
    | PECL :: ion                                                        |
    +--------------------------------------------------------------------+
    | Redistribution and use in source and binary forms, with or without |
    | modification, are permitted provided that the conditions mentioned |
    | in the accompanying LICENSE file are met.                          |
    +--------------------------------------------------------------------+
    | Copyright (c) 2021, Michael Wallner <mike@php.net>                 |
    +--------------------------------------------------------------------+
*/

#ifndef PHP_ION_H
# define PHP_ION_H

extern zend_module_entry ion_module_entry;
# define phpext_ion_ptr &ion_module_entry

# define PHP_ION_VERSION "0.2.0"

# if defined(ZTS) && defined(COMPILE_DL_ION)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#define SUCCESS 0

#endif	/* PHP_ION_H */

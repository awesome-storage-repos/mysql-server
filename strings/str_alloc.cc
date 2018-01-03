/* Copyright (c) 2000, 2016, Oracle and/or its affiliates. All rights reserved.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License, version 2.0,
   as published by the Free Software Foundation.

   This program is also distributed with certain software (including
   but not limited to OpenSSL) that is licensed under separate terms,
   as designated in a particular file or component or in included license
   documentation.  The authors of MySQL hereby grant you an additional
   permission to link the program and your derivative works with the
   separately licensed software that they have included with MySQL.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License, version 2.0, for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA */

#include <stdlib.h>

extern "C" {
static void *my_str_malloc_default(size_t size)
{
  void *ret= malloc(size);
  if (!ret)
    exit(1);
  return ret;
}

static void my_str_free_default(void *ptr)
{
  free(ptr);
}

static void *my_str_realloc_default(void *ptr, size_t size)
{
  return realloc(ptr, size);
}

void *(*my_str_malloc)(size_t)= &my_str_malloc_default;
void (*my_str_free)(void *)= &my_str_free_default;
void *(*my_str_realloc)(void *, size_t)= &my_str_realloc_default;
} // extern "C"

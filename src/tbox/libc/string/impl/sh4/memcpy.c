/*!The Treasure Box Library
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Copyright (C) 2009-2020, TBOOX Open Source Group.
 *
 * @author      ruki
 * @file        memcpy.c
 *
 */

/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */
#include "prefix.h"

/* //////////////////////////////////////////////////////////////////////////////////////
 * macros
 */
#if 1//def TB_ASSEMBLER_IS_GAS
#   define TB_LIBC_STRING_IMPL_MEMCPY
#endif


/* //////////////////////////////////////////////////////////////////////////////////////
 * implementation
 */
#if 1
static tb_pointer_t tb_memcpy_impl(tb_pointer_t s1, tb_cpointer_t s2, tb_size_t n)
{
    tb_assert_and_check_return_val(s1 && s2, tb_null);

    return memcpy(s1, s2, n);
}
#elif defined(TB_ASSEMBLER_IS_GAS)
static tb_pointer_t tb_memcpy_impl(tb_pointer_t s1, tb_cpointer_t s2, tb_size_t n)
{
    tb_assert_and_check_return_val(s1 && s2, tb_null);


    return tb_null;
}
#endif

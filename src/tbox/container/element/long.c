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
 * @file        long.c
 * @ingroup     container
 *
 */

/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */
#include "prefix.h"

/* //////////////////////////////////////////////////////////////////////////////////////
 * implementation
 */
static tb_long_t tb_element_long_comp(tb_element_ref_t element, tb_cpointer_t ldata, tb_cpointer_t rdata)
{
    // compare it
    return ((tb_long_t)ldata < (tb_long_t)rdata)? -1 : ((tb_long_t)ldata > (tb_long_t)rdata);
}
static tb_pointer_t tb_element_long_data(tb_element_ref_t element, tb_cpointer_t buff)
{
    // check
    tb_assert_and_check_return_val(buff, tb_null);

    // the element data
    return (tb_pointer_t)*((tb_long_t*)buff);
}
static tb_char_t const* tb_element_long_cstr(tb_element_ref_t element, tb_cpointer_t data, tb_char_t* cstr, tb_size_t maxn)
{
    // check
    tb_assert_and_check_return_val(element && cstr, "");

    // format string
    tb_long_t n = tb_snprintf(cstr, maxn, "%ld", (tb_long_t)data);
    if (n >= 0 && n < (tb_long_t)maxn) cstr[n] = '\0';

    // ok?
    return (tb_char_t const*)cstr;
}
static tb_void_t tb_element_long_free(tb_element_ref_t element, tb_pointer_t buff)
{
    // check
    tb_assert_and_check_return(buff);

    // clear
    *((tb_size_t*)buff) = 0;
}
static tb_void_t tb_element_long_copy(tb_element_ref_t element, tb_pointer_t buff, tb_cpointer_t data)
{
    // check
    tb_assert_and_check_return(buff);

    // copy element
    *((tb_long_t*)buff) = (tb_long_t)data;
}
static tb_void_t tb_element_long_nfree(tb_element_ref_t element, tb_pointer_t buff, tb_size_t size)
{
    // check
    tb_assert_and_check_return(buff);

    // clear elements
    if (size) tb_memset(buff, 0, size * sizeof(tb_long_t));
}
static tb_void_t tb_element_long_ncopy(tb_element_ref_t element, tb_pointer_t buff, tb_cpointer_t data, tb_size_t size)
{
    // check
    tb_assert_and_check_return(buff);

    // copy elements
    if (size) tb_memset_ptr(buff, data, size);
}

/* //////////////////////////////////////////////////////////////////////////////////////
 * interfaces
 */
tb_element_t tb_element_long()
{
    // the size element
    tb_element_t element_size = tb_element_size();

    // init element
    tb_element_t element = {0};
    element.type   = TB_ELEMENT_TYPE_LONG;
    element.flag   = 0;
    element.hash   = element_size.hash;
    element.comp   = tb_element_long_comp;
    element.data   = tb_element_long_data;
    element.cstr   = tb_element_long_cstr;
    element.free   = tb_element_long_free;
    element.dupl   = tb_element_long_copy;
    element.repl   = tb_element_long_copy;
    element.copy   = tb_element_long_copy;
    element.nfree  = tb_element_long_nfree;
    element.ndupl  = tb_element_long_ncopy;
    element.nrepl  = tb_element_long_ncopy;
    element.ncopy  = tb_element_long_ncopy;
    element.size   = sizeof(tb_long_t);

    // ok?
    return element;
}

/*!The Treasure Arch Library
 *
 * TArch is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * TArch is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with TArch;
 * If not, see <a href="http://www.gnu.org/licenses/"> http://www.gnu.org/licenses/</a>
 *
 * Copyright (C) 2009-2020, ruki All rights reserved.
 *
 * @author      ruki
 * @file        getchar.c
 * @ingroup     libc
 *
 */

/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */
#include "stdio.h"
#include "../../platform/platform.h"

/* //////////////////////////////////////////////////////////////////////////////////////
 * implementation
 */

tb_int_t tb_getchar()
{
    tb_char_t ch;
    return tb_stdfile_getc(tb_stdfile_input(), &ch)? (tb_int_t)ch : TB_EOF;
}

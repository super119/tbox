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
 * @file        expf.c
 * @ingroup     libm
 *
 */

/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */
#include "math.h"
#include <math.h>

/* //////////////////////////////////////////////////////////////////////////////////////
 * implementation
 */
tb_float_t tb_expf(tb_float_t x)
{
#ifdef TB_CONFIG_LIBM_HAVE_EXPF
    return expf(x);
#else
    tb_float_t a = x - (tb_long_t)x;
    return (tb_expif(((tb_long_t)x)) * tb_exp1f(a));
#endif
}

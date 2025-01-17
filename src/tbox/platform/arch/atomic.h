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
 * @file        atomic.h
 *
 */
#ifndef TB_PLATFORM_ARCH_ATOMIC_H
#define TB_PLATFORM_ARCH_ATOMIC_H

/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */
#include "prefix.h"

/* //////////////////////////////////////////////////////////////////////////////////////
 * macros
 */
#if !defined(tb_memory_barrier) && defined(TB_ASSEMBLER_IS_GAS) && (defined(TB_ARCH_x86) || defined(TB_ARCH_x64))
#   define tb_memory_barrier()                  __tb_asm__ __tb_volatile__ ("" ::: "memory")
#endif

#endif

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
 * @file        quick_sort.h
 * @ingroup     algorithm
 *
 */
#ifndef TB_ALGORITHM_QUICK_SORT_H
#define TB_ALGORITHM_QUICK_SORT_H

/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */
#include "prefix.h"

/* //////////////////////////////////////////////////////////////////////////////////////
 * extern
 */
__tb_extern_c_enter__

/* //////////////////////////////////////////////////////////////////////////////////////
 * interfaces
 */

/*! the quick sorter, O(nlog(n))
 *
 * @param iterator  the iterator
 * @param head      the iterator head
 * @param tail      the iterator tail
 * @param comp      the comparer
 */
tb_void_t           tb_quick_sort(tb_iterator_ref_t iterator, tb_size_t head, tb_size_t tail, tb_iterator_comp_t comp);

/*! the quick sorter for all
 *
 * @param iterator  the iterator
 * @param comp      the comparer
 */
tb_void_t           tb_quick_sort_all(tb_iterator_ref_t iterator, tb_iterator_comp_t comp);

/* //////////////////////////////////////////////////////////////////////////////////////
 * extern
 */
__tb_extern_c_leave__
#endif

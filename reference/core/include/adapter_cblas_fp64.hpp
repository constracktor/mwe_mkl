// Copyright (c) 2026 Alexander Strack
//
// SPDX-License-Identifier: BSL-1.0
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef CPU_ADAPTER_CBLAS_FP64_H
#define CPU_ADAPTER_CBLAS_FP64_H

#pragma once

#include <vector>

using vector = std::vector<double>;

// LAPACK level 3 operations

/**
 * @brief FP64 In-place Cholesky decomposition of A using a threaded
 *        LAPACKE_dpotrf2 call.
 *
 * @param A row-major matrix of size N*N to be factorized in place
 * @param N matrix dimension
 */
void lapacke_potrf(vector &A, const int N);
#endif  // end of CPU_ADAPTER_CBLAS_FP64_H

// Copyright (c) 2026 Alexander Strack
//
// SPDX-License-Identifier: BSL-1.0
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include "adapter_cblas_fp64.hpp"

#ifdef ENABLE_MKL
// MKL CBLAS / LAPACKE
#include "mkl_cblas.h"
#include "mkl_lapacke.h"
#else
#include "cblas.h"
#include "lapacke.h"
#endif

void lapacke_potrf(vector &A, const int N)
{
    lapack_int info = LAPACKE_dpotrf2(LAPACK_ROW_MAJOR, 'L', N, A.data(), N);
    if (info != 0)
    {
        // clang-format off
        fprintf(stderr, "LAPACKE_dpotrf2 failed: info=%d (matrix not positive definite)\n", (int) info);
        // clang-format on
    }
}

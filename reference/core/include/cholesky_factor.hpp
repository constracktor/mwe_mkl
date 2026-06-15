// Copyright (c) 2026 Alexander Strack
//
// SPDX-License-Identifier: BSL-1.0
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef CPU_CHOLESKY_FACTOR_H
#define CPU_CHOLESKY_FACTOR_H

#pragma once

#include <stdexcept>
#include <string>
#include <vector>

namespace cpu
{

/**
 * @brief Reference Cholesky variants.
 *
 *   - lapacke : threaded LAPACKE_dpotrf2 call
 *   - plasma  : plasma_dpotrf call (PLASMA's high-level
 *               synchronous Cholesky over the OpenMP runtime).
 */
enum class Variant { lapacke, plasma };

inline Variant to_variant(const std::string &s)
{
    if (s == "lapacke")
    {
        return Variant::lapacke;
    }
    if (s == "plasma")
    {
        return Variant::plasma;
    }
    throw std::invalid_argument("Unknown Variant: " + s);
}

/**
 * @brief Run the requested reference variant on the full row-major N x N
 *        matrix. Factorization is in place; @p matrix holds the lower
 *        triangular factor L on return.
 */
void parallel_cholesky(Variant variant, std::vector<double> &matrix, int N);

}  // end of namespace cpu
#endif  // end of CPU_CHOLESKY_FACTOR_H

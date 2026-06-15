// Copyright (c) 2026 Alexander Strack
//
// SPDX-License-Identifier: BSL-1.0
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef CPU_FUNCTIONS_H
#define CPU_FUNCTIONS_H

#pragma once

#include <cstddef>
#include <string>
#include <vector>

namespace cpu
{

/**
 * @brief Time a single call to the requested reference variant
 *        ('lapacke' or 'plasma') on the @p matrix buffer (row-major, N x N).
 *        The buffer is factorized in place.
 *
 * @param matrix  row-major matrix; on return contains the lower-triangular factor L
 * @param N       matrix dimension
 * @param variant which reference path to time
 * @return wall-clock elapsed time in seconds
 */
double cholesky(std::vector<double> &matrix, std::size_t N, const std::string &variant);

}  // namespace cpu
#endif  // end of CPU_FUNCTIONS_H

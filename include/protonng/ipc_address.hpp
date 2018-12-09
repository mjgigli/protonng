/*
 * Copyright (c) 2018 Matt Gigli
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE
 * SOFTWARE.
 */
#ifndef PROTONNG_IPC_ADDRESS_HPP_
#define PROTONNG_IPC_ADDRESS_HPP_

#include <string>

#include "protonng/address.hpp"

namespace protonng {
class IpcAddress : public Address {
 public:
  explicit IpcAddress(absl::string_view addr);
  IpcAddress(const IpcAddress& rhs);
  IpcAddress(IpcAddress&& rhs);
  IpcAddress& operator=(const IpcAddress& rhs);
  IpcAddress& operator=(IpcAddress&& rhs);
  ~IpcAddress() override;
  absl::string_view transport() const override;
};
}  // namespace protonng

#endif  // PROTONNG_IPC_ADDRESS_HPP_

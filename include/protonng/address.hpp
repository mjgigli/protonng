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
#ifndef PROTONNG_ADDRESS_HPP_
#define PROTONNG_ADDRESS_HPP_

#include <string>

#include "absl/strings/string_view.h"

namespace protonng {
class Address {
 public:
  struct Transport {
    static const std::string ipc;
    static const std::string tcp;
    static const std::string inproc;
  };

  absl::string_view addr() const;
  virtual absl::string_view transport() const = 0;

 protected:
  explicit Address(absl::string_view addr);
  Address(const Address& rhs);
  Address(Address&& rhs);
  Address& operator=(const Address& rhs);
  Address& operator=(Address&& rhs);
  virtual ~Address();

 private:
  std::string addr_;
};
}  // namespace protonng

#endif  // PROTONNG_ADDRESS_HPP_

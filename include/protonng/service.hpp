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
#ifndef PROTONNG_SERVICE_HPP_
#define PROTONNG_SERVICE_HPP_

#include <string>

#include "absl/strings/string_view.h"
#include "nngpp/socket.h"

#include "protonng/address.hpp"

namespace protonng {
class Service {
 public:
  explicit Service(absl::string_view name);
  Service(const Service& rhs) = delete;
  Service(Service&& rhs) noexcept;
  Service& operator=(const Service& rhs) = delete;
  Service& operator=(Service&& rhs);

  virtual ~Service();

  absl::string_view name() const;
  int socket_id() const;
  void Bind(const Address& addr);

 private:
  std::string name_;
  nng::socket socket_;

  void HandleRequest(nng::msg_view msg);
};
}  // namespace protonng

#endif  // PROTONNG_SERVICE_HPP_

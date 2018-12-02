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

#include "protonng/ipc_address.hpp"

#include "absl/strings/str_cat.h"

namespace protonng {

IpcAddress::IpcAddress(absl::string_view addr) :
    Address(absl::StrCat(Address::Transport::ipc, "://", addr)) {
    // TODO(mjgigli) validate addr
}

IpcAddress::IpcAddress(const IpcAddress& rhs) = default;
IpcAddress::IpcAddress(IpcAddress&& rhs) = default;
IpcAddress& IpcAddress::operator=(const IpcAddress& rhs) = default;
IpcAddress& IpcAddress::operator=(IpcAddress&& rhs) = default;
IpcAddress::~IpcAddress() = default;

absl::string_view IpcAddress::transport() const {
    return Address::Transport::ipc;
}

}  // namespace protonng

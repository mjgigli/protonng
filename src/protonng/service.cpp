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

#include "protonng/service.hpp"

#include "nngpp/protocol/rep0.h"

namespace protonng {

Service::Service(absl::string_view name) :
    name_(name),
    socket_(nng::rep::open())
{}

Service::Service(Service&& rhs) noexcept :
    name_(),
    socket_()
{
    name_ = std::move(rhs.name_);
    socket_ = std::move(rhs.socket_);
}

Service& Service::operator=(Service&& rhs) {
    if (this != &rhs) {
        name_ = std::move(rhs.name_);
        socket_ = std::move(rhs.socket_);
    }
    return *this;
}

Service::~Service() = default;

absl::string_view Service::name() const {
    return name_;
}

int Service::socket_id() const {
    return socket_.id();
}

void Service::Bind(const Address& addr) {
    socket_.listen(std::string(addr.addr()).c_str(),
                   addr.addr().size());

    // TODO(mjgigli) Check if context(s) created, instantiate if not
}

void Service::HandleRequest(nng::msg_view msg) {
    (void)msg;  // TODO(mjgigli) Ignore compiler warnings until implemented
    // TODO(mjgigli) Trim RPC header from msg
    // TODO(mjgigli) Parse header, use header info to call CallMethod()
}

}  // namespace protonng

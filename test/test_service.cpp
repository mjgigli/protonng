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

#include <gtest/gtest.h>
#include <string>

#include "protonng/service.hpp"
#include "protonng/tcp_address.hpp"

TEST(ServiceConstructorTest, Name) {
    protonng::Service service("test");
    EXPECT_EQ(service.name(), "test");
}

TEST(ServiceConstructorTest, SocketId) {
    protonng::Service service("test");
    EXPECT_GT(service.socket_id(), 0);
}

TEST(ServiceConstructorTest, Move) {
    protonng::Service service1("test");
    int id = service1.socket_id();
    protonng::Service service2(std::move(service1));
    EXPECT_EQ(service1.socket_id(), -1);
    EXPECT_EQ(service1.name(), "");
    EXPECT_EQ(service2.socket_id(), id);
    EXPECT_EQ(service2.name(), "test");
}

TEST(ServiceBind, TcpLoopback) {
    protonng::Service service("test");
    service.Bind(protonng::TcpAddress("127.0.0.1", 7777));
}

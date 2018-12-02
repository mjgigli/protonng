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

#include "protonng/tcp_address.hpp"

TEST(TcpAddressTest, Loopback) {
    protonng::TcpAddress tcp_addr("127.0.0.1", 7777);
    EXPECT_EQ(tcp_addr.addr(), "tcp://127.0.0.1:7777");
    EXPECT_EQ(tcp_addr.transport(), "tcp");
}

TEST(TcpAddressCopy, CopyConstructor) {
  protonng::TcpAddress tcp_addr1("127.0.0.1", 7777);
  protonng::TcpAddress tcp_addr2(tcp_addr1);
  EXPECT_EQ(tcp_addr1.addr(), "tcp://127.0.0.1:7777");
  EXPECT_EQ(tcp_addr2.addr(), "tcp://127.0.0.1:7777");
}

TEST(TcpAddressCopy, CopyAssignment) {
  protonng::TcpAddress tcp_addr1("127.0.0.1", 7777);
  protonng::TcpAddress tcp_addr2 = tcp_addr1;
  EXPECT_EQ(tcp_addr1.addr(), "tcp://127.0.0.1:7777");
  EXPECT_EQ(tcp_addr2.addr(), "tcp://127.0.0.1:7777");
}

TEST(TcpAddressMove, MoveConstructor) {
  protonng::TcpAddress tcp_addr1("127.0.0.1", 7777);
  protonng::TcpAddress tcp_addr2(std::move(tcp_addr1));
  EXPECT_EQ(tcp_addr1.addr(), "");
  EXPECT_EQ(tcp_addr2.addr(), "tcp://127.0.0.1:7777");
}

TEST(TcpAddressMove, MoveAssignment) {
  protonng::TcpAddress tcp_addr1("127.0.0.1", 7777);
  protonng::TcpAddress tcp_addr2 = std::move(tcp_addr1);
  EXPECT_EQ(tcp_addr1.addr(), "");
  EXPECT_EQ(tcp_addr2.addr(), "tcp://127.0.0.1:7777");
}

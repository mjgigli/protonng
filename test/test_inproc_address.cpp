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

#include "protonng/inproc_address.hpp"

TEST(InprocAddressTest, Loopback) {
  protonng::InprocAddress inproc_addr("foobar-test");
  EXPECT_EQ(inproc_addr.addr(), "inproc://foobar-test");
  EXPECT_EQ(inproc_addr.transport(), "inproc");
}

TEST(InprocAddressCopy, CopyConstructor) {
  protonng::InprocAddress tcp_addr1("foobar-test");
  protonng::InprocAddress tcp_addr2(tcp_addr1);
  EXPECT_EQ(tcp_addr1.addr(), "inproc://foobar-test");
  EXPECT_EQ(tcp_addr2.addr(), "inproc://foobar-test");
}

TEST(InprocAddressCopy, CopyAssignment) {
  protonng::InprocAddress tcp_addr1("foobar-test");
  protonng::InprocAddress tcp_addr2 = tcp_addr1;
  EXPECT_EQ(tcp_addr1.addr(), "inproc://foobar-test");
  EXPECT_EQ(tcp_addr2.addr(), "inproc://foobar-test");
}

TEST(InprocAddressMove, MoveConstructor) {
  protonng::InprocAddress tcp_addr1("foobar-test");
  protonng::InprocAddress tcp_addr2(std::move(tcp_addr1));
  EXPECT_EQ(tcp_addr1.addr(), "");
  EXPECT_EQ(tcp_addr2.addr(), "inproc://foobar-test");
}

TEST(InprocAddressMove, MoveAssignment) {
  protonng::InprocAddress tcp_addr1("foobar-test");
  protonng::InprocAddress tcp_addr2 = std::move(tcp_addr1);
  EXPECT_EQ(tcp_addr1.addr(), "");
  EXPECT_EQ(tcp_addr2.addr(), "inproc://foobar-test");
}

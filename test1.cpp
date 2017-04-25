#include <gtest/gtest.h>
#include <beast/core/detail/base64.hpp>

TEST(core, base64) {

  auto const check = [](std::string const& in, std::string const& out) {
    auto const encoded = beast::detail::base64_encode(in);
    ASSERT_TRUE(encoded == out);
    ASSERT_TRUE(beast::detail::base64_decode(encoded) == in);
  };

  check("",       "");
  check("f",      "Zg==");
  check("fo",     "Zm8=");
  check("foo",    "Zm9v");
  check("foob",   "Zm9vYg==");
  check("fooba",  "Zm9vYmE=");
  check("foobar", "Zm9vYmFy");
}

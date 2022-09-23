#include <doctest/doctest.h>
#include <greeter/greeter.h>
#include <greeter/version.h>

#include <iostream>
#include <string_view>
#include <string>
#include <sstream>

TEST_CASE("Greeter") {
  using namespace greeter;

  Greeter greeter("Tests");

  CHECK(greeter.greet(LanguageCode::EN) == "Hello, Tests!");
  CHECK(greeter.greet(LanguageCode::DE) == "Hallo Tests!");
  CHECK(greeter.greet(LanguageCode::ES) == "¡Hola Tests!");
  CHECK(greeter.greet(LanguageCode::FR) == "Bonjour Tests!");
}

TEST_CASE("Greeter version") {
  static_assert(std::string_view(GREETER_VERSION) == std::string_view("1.0"));
  CHECK(std::string(GREETER_VERSION) == std::string("1.0"));
}

TEST_CASE("influxdb connect") {
  std::cout << "before test" << std::endl;
  greeter::test_influxdb(std::cout);
}

#include <fmt/format.h>
#include <greeter/greeter.h>

#include <InfluxDBFactory.h>
#include <InfluxDB.h>
#include <InfluxDBException.h>

using namespace greeter;

Greeter::Greeter(std::string _name) : name(std::move(_name)) {}

std::string Greeter::greet(LanguageCode lang) const {
  switch (lang) {
    default:
    case LanguageCode::EN:
      return fmt::format("Hello, {}!", name);
    case LanguageCode::DE:
      return fmt::format("Hallo {}!", name);
    case LanguageCode::ES:
      return fmt::format("¡Hola {}!", name);
    case LanguageCode::FR:
      return fmt::format("Bonjour {}!", name);
  }
}

void greeter::test_influxdb(std::ostream& os) {
  constexpr auto connect_str=
    "http://root:DONev5IHThWXkxj6A3MBPPsnMLpxDEe7l1necZC5sx6CeM61PpUexVGqsaGbgPIfeIhF0FhlEhQmF_-jhqs0fw==@localhost:8086?db=influxdb-cpp-cpm";
  os << "before connect " << connect_str << std::endl;
  auto influxdb_client = influxdb::InfluxDBFactory::Get(connect_str);
  influxdb_client->createDatabaseIfNotExists();
  // looks like not supported in any way. Does this lib only support 1.x?
  for(auto i: influxdb_client->query("SHOW DATABASES")) {
    os << "db: " << i.getTags() << std::endl;
  }
}


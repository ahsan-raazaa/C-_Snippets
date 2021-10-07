#include <nlohmann/json.hpp>

#include <iostream>
#include <sstream>
#include <string>

using json = nlohmann::json;

int main() {
    // open the json file - here replaced with a std::istringstream containing the json data

    std::istringstream file(R"json({
  "emulators": [
    {
      "general_info": {
        "dev_id": "0123456789",
        "model": "my_model",
        "model_full": "my_full_model",
        "serial_num": "my_serial_num"
      }
    }
  ]
})json");

    // declare your json object and stream from the file
    json j;
    file >> j;

    // the file is now fully parsed

    // access fields
    for(json& o : j["emulators"]) {
        json& gi = o["general_info"];
        std::cout << gi["dev_id"] << '\n';
        std::cout << gi["model"] << '\n';
        std::cout << gi["model_full"] << '\n';
        std::cout << gi["serial_num"] << '\n';
    }
}
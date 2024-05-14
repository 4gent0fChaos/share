#include <iostream>
#include <fstream>
#include "include/nlohmann/json.hpp" // Make sure this library is included in your project

using json = nlohmann::json;
using namespace std;

int main() {
    // File path to the JSON config file
    const string filename = "config.json";

    // Open the file stream
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    // Parse the JSON file
    json configJson;
    try {
        file >> configJson;
    } catch (json::parse_error& e) {
        cerr << "Error parsing JSON: " << e.what() << endl;
        return 1;
    }

    // Close the file
    file.close();

    // Process each source parameters set in the JSON array
    for (const auto& source : configJson) {
        cout << "Source Name: " << source["SourceName"].get<string>() << endl;
        cout << "Mean On Time: " << source["MeanOnTime"].get<double>() << endl;
        cout << "Mean Off Time: " << source["MeanOffTime"].get<double>() << endl;
        cout << "Peak Bit Rate: " << source["PeakBitRate"].get<double>() << endl;
        cout << "Packet Size: " << source["PacketSize"].get<int>() << endl;
        cout << "--------------------------" << endl;
    }

    return 0;
}

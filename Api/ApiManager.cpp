//
// Created by lucja on 25.06.2024.
//

#include "ApiManager.hpp"
#include <iostream>
std::map<std::string,std::string>& ApiManager::getStations()
{
    cpr::Response response = cpr::Get(cpr::Url{getStationsUrl});
    if(response.status_code > 299 || response.status_code<200) return stations;
    nlohmann::json data = nlohmann::json::parse(response.text);

    for(auto &station :data)
        stations[to_string(station["id"])] = to_string(station["stationName"]);

    return stations;
}

std::map<std::string,std::string> ApiManager::getInstallations(const std::string& stationId)
{
    std::map<std::string,std::string> installations;

    cpr::Response response = cpr::Get(cpr::Url{getInstallationUrl+stationId});
    if(response.status_code > 299 || response.status_code<200) return installations;
    nlohmann::json data = nlohmann::json::parse(response.text);

    for(auto &installation : data)
        installations[to_string(installation["id"])] = to_string(installation["param"]["paramCode"]);

    return installations;
}

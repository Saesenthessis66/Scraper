//
// Created by lucja on 25.06.2024.
//

#ifndef APIMANAGER_HPP
#define APIMANAGER_HPP

#include "cpr/cpr.h"
#include "nlohmann/json.hpp"

class ApiManager {
    const std::string baseUrl = "https://api.gios.gov.pl/pjp-api/rest/station/";
    const std::string getStationsUrl = baseUrl+"findAll";
    const std::string getInstallationUrl = baseUrl+"sensors/";

    std::map<std::string,std::string>  stations;

public:
    std::map<std::string,std::string>& getStations();
    std::map<std::string,std::string> getInstallations(const std::string& stationId);
};

#endif //APIMANAGER_HPP

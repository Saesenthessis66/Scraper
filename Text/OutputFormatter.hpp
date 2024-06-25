//
// Created by lucja on 25.06.2024.
//

#ifndef OUTPUTFORMATTER_HPP
#define OUTPUTFORMATTER_HPP

#include"../Api/ApiManager.hpp"

#include<iostream>

class OutputFormatter {
    ApiManager api;
    std::string data;

    void getDataFromApi();
    void changeStationText(std::string& stationName);
    void changeInstallationText(std::string& installationName);

public:
    OutputFormatter();
    std::string& getData();
};



#endif //OUTPUTFORMATTER_HPP

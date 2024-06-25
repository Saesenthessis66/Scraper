//
// Created by lucja on 25.06.2024.
//

#include "OutputFormatter.hpp"

void OutputFormatter::getDataFromApi()
{
    std::cout<<"App is working...";
    for(auto& [stationId , stationName] : api.getStations())
    {
        changeStationText(stationName);
        data += "Station #" + stationId +" "+ stationName+":\n\n";
        for(auto& [installationId , installationName] : api.getInstallations(stationId))
        {
            changeInstallationText(installationName);
            data += "installation #"+installationId+": " + installationName+"\n\n";
        }
        data+="\n\n";
    }
    system("cls");
}

void OutputFormatter::changeStationText(std::string &stationName)
{
    std::replace(stationName.begin(),stationName.begin()+1, '\"', '(');
    std::replace(stationName.begin(), stationName.end(), '\"', ')');
}

void OutputFormatter::changeInstallationText(std::string &installationName)
{
    std::replace(installationName.begin(), installationName.end(), '\"', '\'');
}

OutputFormatter::OutputFormatter()
{
    this->getDataFromApi();
}

std::string& OutputFormatter::getData()
{
    return this->data;
}

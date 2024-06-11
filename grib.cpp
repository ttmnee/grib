#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

struct Section1Data {
    int length;
    int paramTableVersion;
    std::string center;
    std::string processID;
    int gridID;
    std::string gdsAndBms;
    int unitParams;
    int levelIndicator;
    int levelValue;
    std::string dateTime;
    int timeUnit;
    int p1;
    int p2;
    int timeRangeIndicator;
    int lastRowNumbers;
    int missingFromAverages;
    int referenceCentury;
    int subCenterID;
    int decimalScaleFactor;
};

struct Section2Data {
    int length;
    int numVerticalCoords;
    int octetNum;
    int dataRepType;
    int pointsAlongLatitude;
    int pointsAlongLongitude;
    int latitude;
    int longitude;
    std::string resolutionFlags;
    int lastGridLatitude;
    int lastGridLongitude;
    int lonDirIncrement;
    int latDirIncrement;
    std::string scanModeFlags;
    std::vector<int> rowPoints;
};

struct Section4Data {
    int length;
    int decodeFlag;
    int binaryScaleFactor;
};

void printSection1(const Section1Data& section) {
    std::cout << "======================\n"
              << "==  Section 1 Data  ==\n"
              << "======================\n";
    std::cout << "Section 1 length: " << section.length << "\n"
              << "Parameter table Version: " << section.paramTableVersion << "\n"
              << "Identification of Centre: " << section.center << "\n"
              << "Process ID number: " << section.processID << "\n"
              << "Grid Identification: " << section.gridID << "\n"
              << "GDS and BMS: " << section.gdsAndBms << "\n"
              << "Unit parameters: " << section.unitParams << "\n"
              << "Indicator of type of level or layer: " << section.levelIndicator << "\n"
              << "Height, pressure, etc. of the level or layer: " << section.levelValue << "\n"
              << "YY/MM/DD|HH:MM  :  " << section.dateTime << "\n"
              << "Time unit: " << section.timeUnit << "\n"
              << "P1 - Period of time: " << section.p1 << "\n"
              << "P2 - Period of time: " << section.p2 << "\n"
              << "Time range indicator: " << section.timeRangeIndicator << "\n"
              << "Numbers for last row: " << section.lastRowNumbers << "\n"
              << "Number missing from averages or accumulation: " << section.missingFromAverages << "\n"
              << "Reference century: " << section.referenceCentury << "\n"
              << "Identification of sub Center: " << section.subCenterID << "\n"
              << "Decimal Scale factor: " << section.decimalScaleFactor << "\n";
}

void printSection2(const Section2Data& section) {
    std::cout << "======================\n"
              << "==  Section 2 Data  ==\n"
              << "======================\n";
    std::cout << "Section 2 length: " << section.length << "\n"
              << "Number of Vertical Coordinates: " << section.numVerticalCoords << "\n"
              << "Octet number: " << section.octetNum << "\n"
              << "Data representation type: " << section.dataRepType << "\n"
              << "Numbers of points along a latitude circle: " << section.pointsAlongLatitude << "\n"
              << "Numbers of points along a longitude meridian: " << section.pointsAlongLongitude << "\n"
              << "Latitude: " << section.latitude << " degrees\n"
              << "Longitude: " << section.longitude << " degrees\n"
              << "Resolution and component flags: " << section.resolutionFlags << "\n"
              << "Latitude of last grid point: " << section.lastGridLatitude << " degrees\n"
              << "Longitude of last grid point: " << section.lastGridLongitude << " degrees\n"
              << "Longitudinal Direction Increment: " << section.lonDirIncrement << "\n"
              << "Latitudinal Direction Increment: " << section.latDirIncrement << "\n"
              << "Scanning mode flags: " << section.scanModeFlags << "\n";
    for (size_t i = 0; i < section.rowPoints.size(); ++i) {
        std::cout << "Wiersz " << i + 1 << " Punktow: " << section.rowPoints[i] << "\n";
    }
}

void printSection4(const Section4Data& section) {
    std::cout << "======================\n"
              << "==  Section 4 Data  ==\n"
              << "======================\n";
    std::cout << "Section 4 length: " << section.length << "\n"
              << "Flag to decode: " << section.decodeFlag << "\n"
              << "Binary Scale Factor: " << section.binaryScaleFactor << "\n";
}

int main() {
    // Example data (normally this would be parsed from a GRIB file)
    Section1Data section1 = {28, 2, "US National Weather Service - NCEP (WMC)", "Analysis from GFS (Global Forecast System)",
                             37, "GDS Included  BMS Omitted", 33, 100, 850, "15/3/10|00:00", 1, 0, 0, 10, 0, 0, 21, 0, 1};
    Section2Data section2 = {178, 0, 33, 0, 65535, 73, 0, -30, "Directional increment given and Earth assumed Spherical",
                             90, 60, -1, -30, "Points scan in +i and -j direction. FortransmutnyI,J",
                             {73, 73, 73, 73, 73, 73, 73, 73, 72, 72, 72, 71, 71, 71, 70, 70, 69, 69, 68, 67, 67, 66, 65, 65,
                              64, 63, 62, 61, 60, 60, 59, 58, 57, 56, 55, 54, 52, 51, 50, 49, 48, 47, 45, 44, 43, 42, 40,
                              39, 38, 36, 35, 33, 32, 30, 29, 28, 26, 25, 23, 22, 20, 19, 17, 16, 14, 12, 11, 9, 8, 6, 5, 3, 2}};
    Section4Data section4 = {4320, 2, 0};

    // Print example data
    std::cout << "Coding info: HUIA85\n"
              << "==========================\n"
              << "== General Message Info ==\n"
              << "==========================\n"
              << "Grib Finda at pos: 40\n"
              << "7777 Find at position: 4578\n"
              << "Distance between end of grib and start of 7777: 4542\n"
              << "Whole Message length: 4538\n";

    printSection1(section1);
    printSection2(section2);
    printSection4(section4);

    return 0;
}

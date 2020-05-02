#include "DemoHelper.h"

DemoHelper::DemoHelper() {}

DemoHelper::~DemoHelper() {}

EdgesList* DemoHelper::addDemoStuff(EdgesList* list) {

    result = list;

    const string demoCountries[] = {
        "Country_0",
        "Country_1",
        "Country_2",
        "Country_3"
    };

    const string demoSystems[] = {
        "System_0",
        "System_1",
        "System_2",
        "System_3",
        "System_4",
        "System_5"
    };

    const string demoEdges[] = {
        "Edge_9",
        "Edge_1",
        "Edge_7",
        "Edge_4",
        "Edge_5",
        "Edge_3",
        "Edge_2",
        "Edge_6",
        "Edge_8",
        "Edge_0"
    };

    const double demoHeights[] = {
        5555.5f, // 0
        6737.7f, // 1
        6143.2f, // 2
        2244.1f, // 3
        253.f, // 4
        100.6f, // 5
        7134.f, // 6
        6022.f, // 7
        253.f, // 8
        5.f, // 9
    };

    result->pushEnd(demoEdges[6], demoSystems[5], demoCountries[3], demoHeights[6]);
    result->pushEnd(demoEdges[7], demoSystems[5], demoCountries[3], demoHeights[7]);
    result->pushEnd(demoEdges[8], demoSystems[4], demoCountries[2], demoHeights[8]);
    result->pushEnd(demoEdges[9], demoSystems[3], demoCountries[0], demoHeights[9]);

    result->pushStart(demoEdges[5], demoSystems[2], demoCountries[1], demoHeights[5]);
    result->pushStart(demoEdges[4], demoSystems[1], demoCountries[3], demoHeights[4]);
    result->pushStart(demoEdges[3], demoSystems[1], demoCountries[1], demoHeights[3]);
    result->pushStart(demoEdges[2], demoSystems[1], demoCountries[0], demoHeights[2]);
    result->pushStart(demoEdges[1], demoSystems[0], demoCountries[0], demoHeights[1]);
    result->pushStart(demoEdges[0], demoSystems[0], demoCountries[2], demoHeights[0]);

    return result;
}

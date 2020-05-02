#pragma once

#include "EdgesList.h"

class DemoHelper
{

public:

    DemoHelper();
    ~DemoHelper();
    EdgesList* addDemoStuff(EdgesList* list);

private:

    EdgesList* result;
};
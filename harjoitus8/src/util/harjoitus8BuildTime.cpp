#include "harjoitus8BuildTime.h"

harjoitus8BuildTime::harjoitus8BuildTime()
: dateTime(__DATE__ " " __TIME__)
{
}

harjoitus8BuildTime::~harjoitus8BuildTime()
{
}

const char* harjoitus8BuildTime::GetDateTime()
{
    return dateTime;
}


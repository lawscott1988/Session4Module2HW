#pragma once

#include<string>
#include<ostream>

//This is for part 1
class ILogger {
public:
    //must 'assign' virtual function as = to 0 to make it pure virtual
    virtual ILogger& LogInfo(const std::string& s) = 0;
    virtual ILogger& LogError(const std::string& s) = 0;
    virtual const std::string& GetLastError() const = 0;
    virtual ~ILogger() = default;
};

// This is for Part 2/3
class StringLogger : public ILogger {
    std::ostream& stream;
    std::string lastError;

public:
    StringLogger(std::ostream& os)
        :   stream(os)
    {}

    ILogger& LogInfo(const std::string& s) override {
        stream << "INFO: " << s;
        return *this;
    }

    ILogger& LogError(const std::string& s) override {
        stream << "ERROR: " << s;
        lastError = s;
        return *this;
    }

    const std::string& GetLastError() const override{
        return lastError;
    }

};

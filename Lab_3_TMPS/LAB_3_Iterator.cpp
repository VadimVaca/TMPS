#include <iostream>
#include <vector>
#include <algorithm>

class RadioStation {
    friend bool operator==(const RadioStation& lhs, const RadioStation& rhs) { return lhs.frequency_ == rhs.frequency_; }
public:
    RadioStation(float frequency) : frequency_(frequency) {}
    float GetFrequency() const { return frequency_; }
private:
    float frequency_;
};

class StationList {
    using Iter = std::vector<RadioStation>::iterator;
public:
    void AddStation(const RadioStation& station) { stations_.push_back(station); }
    void RemoveStation(const RadioStation& toRemove) {
        auto found = std::find(stations_.begin(), stations_.end(), toRemove);
        if (found != stations_.end()) stations_.erase(found);
    }
    Iter begin() { return stations_.begin(); }
    Iter end() { return stations_.end(); }
private:
    std::vector<RadioStation> stations_;
};

int main()
{
    StationList stationList;

    stationList.AddStation(RadioStation(105));
    stationList.AddStation(RadioStation(106.7));

    for (auto&& station : stationList)
        std::cout << station.GetFrequency() << std::endl;

    stationList.RemoveStation(RadioStation(89)); // Will remove station 89
}
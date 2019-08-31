#include "esphome.h"
#include <CD74HC4067.h>

CD74HC4067 mux(5, 4, 0, 2);

class MuxSensor : public PollingComponent {
    private:
        // CD74HC4067 _mux;
        // int _pins[];
        int _sPin;
        std::vector<int> _channels;
    public:
        // MuxSensor(int pins[], int sPin, int channels[]) : PollingComponent(100) {
        //     _pins = pins;
        //     _sPin = sPin;
        //     _channels = channels;
        // }
        std::vector<BinarySensor*> sensors;

        MuxSensor() : PollingComponent(100) {
            // _pins = {5,4,0,2};
            _sPin = 14;
            int channels[] = {0,2,4,6,8,10,12,14};
            for (int i: channels) {
                _channels.push_back(i);
                sensors.push_back(new BinarySensor());
            }
        }
        
        void setup() override {
            // _mux = new CD74HC4067(_pins[0], _pins[1], _pins[2], _pins[3]);
              pinMode(_sPin, INPUT_PULLUP);
              ESP_LOGD("MuxSensor", "Setup complete");
        }
        
        void update() override {
            std::vector<bool> states;
              
            for (int i=0; i < _channels.size(); i++){
              mux.channel(_channels[i]);
              bool state = digitalRead(_sPin);
              states.push_back(state);
              sensors[i]->publish_state(state);
            }

            // ESP_LOGD("MuxSensor", 
            //     "Mux update %s %s %s %s %s %s %s %s",
            //     states.at(0) ? "X" : "O",
            //     states.at(1) ? "X" : "O",
            //     states.at(2) ? "X" : "O",
            //     states.at(3) ? "X" : "O",
            //     states.at(4) ? "X" : "O",
            //     states.at(5) ? "X" : "O",
            //     states.at(6) ? "X" : "O",
            //     states.at(7) ? "X" : "O"
            // );
        }
};
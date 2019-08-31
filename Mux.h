#include "esphome.h"
#include <CD74HC4067.h>

CD74HC4067 mux(5, 4, 0, 2);

#define get_mux(constructor) static_cast<Mux *>(const_cast<custom_component::CustomComponentConstructor *>(&constructor)->get_component(0))

#define mux_switch(mux, channel) get_mux(mux)->get_switch(channel)
// #define mux_binary_sensor(mux, channel) get_mux(mux)->get_binary_sensor(channel)

class Mux;

using namespace esphome;

class MuxSwitch : public Switch
{
    public:
        MuxSwitch(Mux *parent, uint8_t channel) {
            this->parent_ = parent;
            this->channel_ = channel;
        }

        void write_state(bool state) override;

        // uint8_t get_channel() {
            // return this->channel_;
        // }

    protected:
        Mux *parent_;
        uint8_t channel_;
        bool state_{false};

        friend class Mux;
};

class Mux : public Component 
{
    protected:
        // CD74HC4067 _mux;
        // int _pins[];
        uint8_t pin;
    protected:
        bool initial_state_{true};
        std::vector<MuxSwitch *> output_channels_;
        // std::vector<ApeBinarySensor *> input_channels_;
        //std::vector<ApeSensor *> analog_pins_;
    
    public:
        Mux(uint8_t pin) {
            // _pins = {5,4,0,2};
            this->pin = pin;
            // int channels[] = {0,2,4,6,8,10,12,14};
            // for (int i: channels) {
            //     _channels.push_back(i);
            //     sensors.push_back(new BinarySensor());
            // }
        }

        Switch *get_switch(uint8_t channel)
        {
          MuxSwitch *output = new MuxSwitch(this, channel);
          output_channels_.push_back(output);
          return output;
        }
       
        // binary_sensor::BinarySensor *get_binary_sensor(uint8_t channel)
        // {
        //     ApeBinarySensor *binarySensor = new MuxBinarySensor(this, channel);
        //     input_channels_.push_back(binarySensor);
        //     return binarySensor;
        // }

        void write_state(uint8_t channel, bool state, bool setup = false)
        {
              pinMode(this->pin, OUTPUT);
              mux.channel(channel);
              digitalWrite(this->pin, state);
        }
};

void MuxSwitch::write_state(bool state)
{
    publish_state(state);
    this->parent_->write_state(this->channel_, state);
}
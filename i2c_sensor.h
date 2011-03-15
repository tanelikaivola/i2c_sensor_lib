// safety againts double-include
#ifndef i2c_sensor_h
#define i2c_sensor_h
#include <WProgram.h> 
#include <Wire.h>


class i2c_sensor
{
    public:
        i2c_sensor();
        ~i2c_sensor();
        void begin(byte dev_addr, boolean wire_begin);
        virtual void read_sensor_data();
        void get_last_raw(byte *target);
        void get_last_smoothed(byte *target);
        void get_buffer(byte *target);

    protected:
        byte device_address;
        // PONDER: These might be better not be defined here (if overloading is b0rked or something
        int smooth_buffer[5];
        int last_data_buffer;

};


#endif
// *********** END OF CODE **********

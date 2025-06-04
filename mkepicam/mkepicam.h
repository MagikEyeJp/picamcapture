#ifndef _mkepicam_h
#define _mkepicam_h 1

#ifndef __cplusplus
#error "Requires C++"
#endif

#include <stdint.h>
#include <string>
#include <memory>

namespace mkepicam {

    struct camera_info {
        int width;          // image width
        int height;         // image height
        std::string name;   // sensor name
    };

    enum class Camera_num : int32_t {
        CAM0 = 0,
        CAM1 = 1,
    };

    class Authchip;
    
    class Camera {
    public:
        camera_info get_camera_info() const;
        bool open();
        bool close();
        bool get_image(uint8_t* image, int* phasePtr = nullptr);
        bool get_image16(uint16_t* image, int* phasePtr = nullptr);
        bool set_exposure(float seconds);
        bool set_gain(float gain);
        bool set_flash(bool on);
        float get_sensor_temperature();
        float get_laser_voltage();
        bool set_gamma(double gamma, int black_level = 0);
        bool set_continuous_flash_mode(bool on);
        bool set_fps(float fps);
        bool set_sequence(int count, const uint8_t* sequence);
        bool set_autoexposure_range(float min, float max);
        bool set_autoexposure_roi(float width, float height,
                                  float centerX = 0.5f, float centerY = 0.5f);
        bool set_autoexposure_phase_mask(uint8_t mask);
        Authchip* get_authchip();

        bool enable_hdr(float hdr_seconds, bool hdrc = false);
        bool disable_hdr();

        class Impl;
    private:
        Camera(Impl* _impl);
        ~Camera();
        std::unique_ptr<Impl> impl;
        friend Camera* find_camera(const char* settings);
        friend Camera* find_camera(Camera_num num);
    };

    Camera* find_camera(const char* settings = nullptr);
    Camera* find_camera(Camera_num num/* = Camera_num::CAM1*/); // Obsolete

    class Authchip {
    public:
        virtual ~Authchip() {};
        virtual std::string get_serial() = 0;
    };

    namespace LaserDriver {

        // -----------------------------------------------------------------
        //  mkepicam::LaserDriver::get_num_drivers
        //    Get number of programmable laser drivers
        //  Returns:
        //    Number of laser drivers (1 to 4), or 0 if no programmable
        //    laser drivr, or -1 if error.
        // -----------------------------------------------------------------

        int get_num_drivers();
        
        // -----------------------------------------------------------------
        //  mkepicam::LaserDriver::set_driver_current
        //    Set the laser drive current
        //  Arguments:
        //    laserID: Laser ID number (0-3)
        //    current: Laser current value in A, or 0 to stop.
        //  Returns:
        //    Actual laser current set, or negative if error.
        // -----------------------------------------------------------------

        float set_driver_current(int laserID, float current);

        // -----------------------------------------------------------------
        //  mkepicam::LaserDriver::get_driver_current
        //    Get the laser drive current
        //  Arguments:
        //    laserID: Laser ID number (0-3)
        //  Returns:
        //    Actual laser current set, or negative if error.
        // -----------------------------------------------------------------

        float get_driver_current(int laserID);

        // -----------------------------------------------------------------
        //  mkepicam::LaserDriver::get_driver_error
        //    Get the laser driver error status
        //  Arguments:
        //    laserID: Laser ID number (0-3)
        //  Returns:
        //    Bit-or'ed error status, or zero if no error
        // -----------------------------------------------------------------

        enum {
              DRIVER_NO_ERROR           = 0,
              DRIVER_UNDER_VOLTAGE      = 0x02,
              DRIVER_THERMAL_SHUTDOWN   = 0x04,
              DRIVER_THERMAL_SCALE_BACK = 0x08,
              DRIVER_SHORT_FALUT        = 0x20,
              DRIVER_I2C_ERROR          = 0x100,
         };

        int get_driver_error(int projID);

    }

}

#endif

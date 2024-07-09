# arduino_projects

Miscellaneous open-source projects primarily focusing on the tiny 
**Seeed Studio** *XIAO* microcontrollers, and some LTE boards.



## Examples Implemented


### Seeed Studios Wio LTE Board

#### GNSS_Show_Coordinate

#### Requires 
* [Update to latest firmware](#Update-Firmware)
* Use Zadig to set correct drivers ()
* ____ library installed
* sim card must be installed (does not need to be activated)

#### Steps
* Start Arduino
* File | Examples | Wio LTE Arduino Library | GNSS | GNS_Show_Coordinate



## Board References

### Seeed Studio Wio LTE

https://www.espruino.com/WioLTE

# Arduino Library
* Sketch
* Include Library
* Wio LTE Arduino Library
* Use **SerialUSB** for for output (NOT Serial)


#### Upload Firmware
* Hold *Boot* button
* Press and release *Reset* button
* Release *Boot* button


#### Run Firmware
* Press and release *Reset* button
* Monitor output on *Tera Term*







## Utility Operations

### Tera Term



* Open *Device Manager*
* Note the device driver for this board
  * Example: STM32 Virtual ComPort (COM12)
* Start *Tera Term*
* Select *Serial*
* Select correct *Port*
  * Example *COM12* 
* OK
* Setup | Serial Port | Speed "115200" | New setting


### Update Firmware

#### Get Latest Firmware (WioLTE)
https://www.espruino.com/Download

#### dfu-util
https://dfu-util.sourceforge.net/

List DFU devices
* Hold BOOT button when connecting/resetting board
```shell
dfu-util -l
```

Update to latest firmware 
* Verify numbers at "-d 0483:df11"
* Verify correct bin file
```shell
dfu-util -d 0483:df11 -c 1 -i 0 -a 0 -s 0x08000000 -D ~/downloads/espruino_2v16_Wio_LTE.bin
```

### Replace USB Drivers

#### WioLTE

##### Required
* Update to latest firmware

##### Firmware Interface Driver
* Open *Device Manger* to see what device is added on reset
* Hold *Boot* button
* Press and release *Reset* button
* Release *Boot* button
* Use *Device Manager* to find name of newly-added device
  * May need to open *Ports (COM & LPT)* group
  * Example: STM32 Virtual ComPort
* Use Zadig utility to update driver to **WinUSB** driver
* Hold *Boot* and reset again
* Verify new driver is loaded
    * May need to open *Universal Serial Bus devices* group
    * Example: STM32 BOOTLOADER
* Use Zadig to verify this device is using WinUSB driver

##### Serial Interface Driver
* Open *Device Manger* to see what device is added on reset
* Press and release *Reset* button
* Use *Device Manager* to find name of newly-added device
    * May need to open *Universal Serial Bus devices* group
    * Example: STM32 Virtual ComPort
* Use Zadig utility to update driver to **USB Serial (CDC)** driver
* Hold *Boot* and reset again
* Verify new driver is loaded
    * May need to open *Ports (COM & LPT)* group
    * Example: STM32 Virtual ComPort
* Use Zadig to verify this device is using WinUSB driver





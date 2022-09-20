# Torizon for RISC-V

Torizon is a software platform that simplifies the process of developing and maintaining embedded software. It allows you to configure the system for IoT/IIoT with over the air updates (OTA) quickly and easily, so you can focus on application development instead of Linux builds. With Torizon for Raspberry Pi and x86-64 devices, we experiment with extending the Torizon ecosystem beyond Toradex SoMs.

> ⚠️ **This software is provided experimentally as-is. Users may self-onboard, self-support and/or work with an integration partner to evaluate Torizon for RISC-V systems. Please share with us your feedback & any interest to use Torizon in your product.**

## Getting Started

### Torizon for Alwinner D1

Supported hardware:

- Nezha D1 Dev Board

#### Flashing SD Card

Download the compressed `WIC` image and `BMAP` file:

- [Torizon for RISC-V](https://github.com/microhobby/meta-toradex-torizon/releases/tag/labs-6)

Use `bmap-tools` to flash SD Card:

```bash
sudo bmaptool copy torizon-core-docker-nezha-allwinner-d1.wic.gz
 /dev/<your-sdcard-device>
```

First Boot

The board terminal can be accessed by the following methods:

- Using an USB keyboard connect to the board;

- With an Ethernet cable connected, using `SSH` (you can use IP address or hostname):
  
  

> ⚠️ The hostname to TorizonCore for Nezha D1 devices is `torizon-nezha`



Use the follow credentials to login:

- Login: `torizon`

- Password: `torizon`

> ⚠️ As a security measure TorizonCore uses the default password only for the first login, requiring a password change.


